#ifndef HEAP_FIBONACCI_H
#define HEAP_FIBONACCI_H

#include <iostream>
#include <cmath>
#include <cstdlib>

// http://www.ic.unicamp.br/~zanoni/mo637/aulas/heapsFibonacci.pdf
// https://rosettacode.org/wiki/Fibonacci_heap
using namespace std;

class NodeFibonacci {
public:
	NodeFibonacci *parent;
	NodeFibonacci *child;
	NodeFibonacci *left;
    NodeFibonacci *right;
    int degree;
    double key;
    int vertice;
    bool mark;
	NodeFibonacci() {}
};

class HeapFibonacci {
	NodeFibonacci* create_NodeFibonacci(double key, int vertice);
	NodeFibonacci* merge_NodeFibonacci(NodeFibonacci* heap, NodeFibonacci* new_NodeFibonacci);
	void clean_parent_and_mark(NodeFibonacci* n);
	void add_child_NodeFibonacci(NodeFibonacci* parent, NodeFibonacci* child);
	NodeFibonacci* delete_min(NodeFibonacci* heap);
	NodeFibonacci* cut(NodeFibonacci* x, NodeFibonacci* y);
	
public:
	NodeFibonacci *H;
	int size;

	HeapFibonacci();
	NodeFibonacci* insert(double key, int vertice);
	NodeFibonacci* extract_min();
	void decrease_key(NodeFibonacci* n, double value);
};

#endif