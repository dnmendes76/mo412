#include "../inc/heap_vector.h"

HeapVector::HeapVector(int tamMax) {
  this->tamMax = tamMax;
  this->size = tamMax;
  this->qtd_fila = tamMax;
  this->valores.resize(tamMax);
  this->in_heap.resize(tamMax);
}

void HeapVector::build_heap(int n){
  size = n;
  for(int i = 0; i < n; i++) {
    valores[i] = numeric_limits<double>::max();
    in_heap[i] = 1;
  }
}

int HeapVector::extract_min() {
  int indice = 0;
  double ret = numeric_limits<double>::max();
  for (int i = 0; i < size; i++) {
    if (!in_heap[i]) continue;
    if (valores[i] < ret) {
      indice = i;
      ret = valores[i];
    }
  }
  in_heap[indice] = 0;
  qtd_fila--;
  return indice;
}

void HeapVector::decrease_key(int i, double key) {
  if(valores[i] < key){
    cout << "Erro - Key not Valid! :(" << endl;
    exit(0);
  }
  valores[i] = key;
}
