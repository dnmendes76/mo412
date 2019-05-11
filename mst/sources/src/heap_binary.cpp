#include "../inc/heap_binary.h"

HeapBinary::HeapBinary(int tamMax) {
	this->tamMax = tamMax;
	this->size = 0;
	this->valores.resize(tamMax);
    this->posicoes.resize(tamMax);
}

int HeapBinary::parent(int i) {
	return (i-1) / 2;
}

int HeapBinary::left(int i) {
	return (2*i + 1);
}

int HeapBinary::right(int i) {
	return (2*i + 2);
}

void swap(Node &x, Node &y, vector<int>&pos) {
  int aux = pos[x.vertice];
  pos[x.vertice] = pos[y.vertice];
  pos[y.vertice] = aux;
  Node temp = x;
  x = y;
  y = temp;
}

void HeapBinary::heapfy(int i) {
	int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l <= size && valores[l].valor < valores[smallest].valor)
      smallest = l;
    if(r < size && valores[r].valor < valores[smallest].valor)
      smallest = r;
    if(smallest != i) {
      swap(valores[i], valores[smallest], posicoes);
      heapfy(smallest);
    }
}

void HeapBinary::build_heap(int n){
  size = n;
  for(int i = floor(n/2)-1; i >= 0; i--){
    heapfy(i);
  }
}

void HeapBinary::heap_insert(Node valor) {
  if(size == tamMax) {
    cout << "\nSorry!! Overflow :/\n";
    exit(0);
  }
  int i = size;
  valores[i] = valor;
  size++;
  while (i != 0 && valores[i].valor < valores[parent(i)].valor) {
    swap(valores[i], valores[parent(i)], posicoes);
    i = parent(i);
  }
}

Node HeapBinary::extract_min() {
  if(size <= 0){
    cout << "Erro - Heap empty! :(" << endl;
    exit(0);
  }

  Node min = valores[0];
  valores[0] = valores[size-1];
  size--;
  heapfy(0);
  return min;
}

void HeapBinary::decrease_key(int i, Node key) {
  int pos = posicoes[i];
  if(valores[pos].valor < key.valor){
    cout << "Erro - Key not Valid! :(" << endl;
    exit(0);
  }
  valores[pos] = key;
  while(i > 0 && valores[pos].valor < valores[parent(pos)].valor) {
    swap(valores[pos], valores[parent(pos)], posicoes);
    pos = parent(pos);
  }
}
