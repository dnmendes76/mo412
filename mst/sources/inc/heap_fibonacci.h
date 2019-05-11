#include <iostream>
#include <cmath>
#include <cstdlib>

// http://www.ic.unicamp.br/~zanoni/mo637/aulas/heapsFibonacci.pdf
// https://rosettacode.org/wiki/Fibonacci_heap
using namespace std;

class Node {
public:
	Node *parent;
	Node *child;
	Node *left;
    Node *right;
    int degree;
    double key;
    bool mark;
	Node() {}
};

class HeapFibonacci {
	Node* create_node(double key);
	Node* merge_node(Node* heap, Node* new_node);
	void clean_parent_and_mark(Node* n);
	void add_child_node(Node* parent, Node* child);
	Node* delete_min(Node* heap);
	Node* cut(Node* x, Node* y);
	
public:
	Node *H;

	HeapFibonacci();
	Node* insert(double key);
	Node* extract_min();
	void decrease_key(Node* n, double value);
};