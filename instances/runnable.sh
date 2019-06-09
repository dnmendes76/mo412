#!/bin/zsh

cd 
home=Documents/AG/mo412/mst/
cd $home
make
cd instances_tests/inputs

for f in *; do
	name_out=`echo $f | sed 's/\.in/\.out/g'`

  	path_file="../outputs/prim-0-$name_out"
  	./../../main prim 0 $f $path_file

done