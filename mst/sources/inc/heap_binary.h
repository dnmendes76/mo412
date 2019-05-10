#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Node{
public:
	double valor;
	int indice;
	Node() {};
};

class HeapBinary{
public:
	vector<Node> valores;
	int size;
	int tamMax;

	HeapBinary(int tamMax);
	int parent(int i);
	int left(int i);
	int right(int i);
	void heapfy(int i);
	void build_heap(int n);
	void heap_insert(Node valor);
	Node extract_min();
	void decrease_key(int i, Node key);

};