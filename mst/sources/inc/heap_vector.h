#ifndef HEAP_VECTOR_H
#define HEAP_VECTOR_H

#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class HeapVector {
public:
  vector<double> valores;
  vector<int> in_heap;
  int size;
  int qtd_fila;
  int tamMax;

  HeapVector(int tamMax);
  void build_heap(int n);
  //void heap_insert(Node valor);
  int extract_min();
  void decrease_key(int i, double key);

};

#endif
