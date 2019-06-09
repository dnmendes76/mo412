#!/bin/zsh

g++ -o output maker.cpp
export LC_NUMERIC="en_US.UTF-8"

for n in {50..2500..50}; do
	echo $n
	densidade=$((0.01+0))
  	for i in {1..50..1}; do
  		name_file="caminhos/caminhos$n-$i.in"
  		d=`printf "%.2f" $densidade`

  		./output $n $d "caminhos" $name_file

		densidade=$((densidade+0.0205))
	done
done
