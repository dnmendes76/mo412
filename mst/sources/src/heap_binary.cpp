#include "../inc/heap_binary.h"

HeapBinary::HeapBinary(int tamMax) {
	this->tamMax = tamMax;
	this->size = 0;
	this->valores = new double[tamMax];
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

void swap(double *x, double *y) { 
    double temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void HeapBinary::heapfy(int i) {
	int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if(l <= size && valores[l] < valores[smallest]) 
        smallest = l; 
    if(r < size && valores[r] < valores[smallest]) 
        smallest = r; 
    if(smallest != i) { 
        swap(&valores[i], &valores[smallest]); 
        heapfy(smallest); 
    } 
}

void HeapBinary::build_heap(int n){
	size = n;
	for(int i = floor(n/2)-1; i >= 0; i--){
		heapfy(i);
	}
}

void HeapBinary::heap_insert(double valor) {
	if(size == tamMax) { 
        cout << "\nSorry!! Overflow :/\n"; 
        exit(0); 
    } 
    int i = size;
    valores[i] = valor;
    size++;
    while (i != 0 && valores[parent(i)] > valores[i]) { 
       swap(&valores[i], &valores[parent(i)]); 
       i = parent(i); 
    } 
}

double HeapBinary::extract_min() {
	if(size <= 0){
		cout << "Erro - Heap empty! :(" << endl;
		exit(0);
	}

	double min = valores[0];
	valores[0] = valores[size-1];
	size--;
	heapfy(0);
	return min;
}

void HeapBinary::decrease_key(int i, double key) {
	if(valores[i] < key){
		cout << "Erro - Key not Valid! :(" << endl;
		exit(0);
	}
	valores[i] = key;
	while(i > 0 && valores[i] < valores[parent(i)]) {
		swap(&valores[i], &valores[parent(i)]);
		i = parent(i);
	}

}