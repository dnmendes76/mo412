#include "../inc/heap_fibonacci.h"

HeapFibonacci::HeapFibonacci() {
	this->H = NULL;
	this->size = 0;
}

NodeFibonacci* HeapFibonacci::create_NodeFibonacci(double key, int vertice) {
	NodeFibonacci* temp = new NodeFibonacci;
	temp->key = key;
	temp->vertice = vertice;
	temp->degree = 0;
	temp->parent = NULL;
	temp->child = NULL;
	temp->mark = false;
	temp->left = temp;
	temp->right = temp;
	return temp; 
}

NodeFibonacci* HeapFibonacci::merge_NodeFibonacci(NodeFibonacci* heap, NodeFibonacci* new_NodeFibonacci) {
	if(heap==NULL) return new_NodeFibonacci;
	if(new_NodeFibonacci==NULL) return heap;
	if(heap->key > new_NodeFibonacci->key) {
		NodeFibonacci* temp = heap; 
		heap = new_NodeFibonacci;
		new_NodeFibonacci = temp;
	}

	heap->left = new_NodeFibonacci;
	new_NodeFibonacci->right = heap;
	(heap->left)->right = new_NodeFibonacci->right;
	(new_NodeFibonacci->right)->left = heap->left;

	return heap;

}

void HeapFibonacci::clean_parent_and_mark(NodeFibonacci* nodeFibonacci) {
	if(nodeFibonacci==NULL)return;
	NodeFibonacci* temp = nodeFibonacci;
	do {
		temp->mark = false;
		temp->parent = NULL;
		temp = temp->left;
	} while(temp != nodeFibonacci);
}

void HeapFibonacci::add_child_NodeFibonacci(NodeFibonacci* parent, NodeFibonacci* child) {
	
	child->right=child->left=child;
	child->parent=parent;
	parent->degree++;
	parent->child=merge_NodeFibonacci(parent->child,child);
}

NodeFibonacci* HeapFibonacci::delete_min(NodeFibonacci* heap) {
	clean_parent_and_mark(heap->child);
	if(heap->left == heap) {
		heap = heap->child;
	} else {
		heap->left->right = heap->right;
		heap->right->left = heap->left;
		heap = merge_NodeFibonacci(heap->left, heap->child);
	}
	if(heap == NULL) return heap;
	int degree = heap->degree;
	NodeFibonacci* A[64] = {NULL};
	NodeFibonacci* t = NULL;
	do {
		if(A[heap->degree] != NULL) {
			t = A[heap->degree];
			A[heap->degree] = NULL;
			if(heap->key < t->key) {
				(t->right)->left = t->left;
				(t->left)->right = t->right;
				add_child_NodeFibonacci(heap, t);
			} else {
				(t->right)->left = t->left;
				(t->left)->right = t->right;
				if(heap->left == heap) {
					t->left = t->right = t;
					add_child_NodeFibonacci(t, heap);
					heap = t;
				} else {
					(heap->right)->left = t;
					(heap->left)->right = t;
					t->left = heap->left;
					t->right = heap->right;
					add_child_NodeFibonacci(t, heap);
					heap = t;
				}
			}
			continue;
		} else {
			A[heap->degree] = heap;
		}
		heap = heap->left;
	} while(t != heap);
	NodeFibonacci* min = heap;
	do {
		if(heap->key < min->key) min = heap;
		heap = heap->left;
	}while(heap != min);
	return min;
}

NodeFibonacci* HeapFibonacci::cut(NodeFibonacci* heap, NodeFibonacci* n) {
	if(n->left == n) {
		(n->parent)->child = NULL;
	} else {
		(n->left)->right = n->right;
		(n->right)->left = n->left;
		(n->parent)->child = n->left;
	}
	n->left = n->right = n;
	n->mark = false;
	return merge_NodeFibonacci(heap, n);


}

NodeFibonacci* HeapFibonacci::insert(double key, int vertice) {
	NodeFibonacci* new_NodeFibonacci = create_NodeFibonacci(key, vertice);
	H = merge_NodeFibonacci(H, new_NodeFibonacci);
	size++;
	return new_NodeFibonacci;
}

NodeFibonacci* HeapFibonacci::extract_min() {
	NodeFibonacci* min = H;
	H = delete_min(H);
	size--;
	return min;
}

void HeapFibonacci::decrease_key(NodeFibonacci* n, double value) {
	if(n->key < value) exit(0);
	n->key = value;
	NodeFibonacci* parent = n->parent;
	if(parent == NULL) {
		H = n;
	}
	else if(n->key < n->parent->key) {
		H = cut(H, n);
		NodeFibonacci* parent = n->parent;
		n->parent = NULL;
		while(parent != NULL && parent->mark) {
			H = cut(H, parent);
			n = parent;
			parent = n->parent;
			n->parent = NULL;
		}
		if(parent!=NULL && parent->parent!= NULL) 
			parent->mark = true;
	}
}