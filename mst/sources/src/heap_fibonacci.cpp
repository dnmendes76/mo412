#include "../inc/heap_fibonacci.h"

HeapFibonacci::HeapFibonacci() {
	this->H = NULL;
}

Node* HeapFibonacci::create_node(double key) {
	Node* temp = new Node;
	temp->key = key;
	temp->degree = 0;
	temp->parent = NULL;
	temp->child = NULL;
	temp->mark = false;
	temp->left = temp;
	temp->right = temp;
	return temp; 
}

Node* HeapFibonacci::merge_node(Node* heap, Node* new_node) {
	if(heap==NULL) return new_node;
	if(new_node==NULL) return heap;
	if(heap->key > new_node->key) {
		Node* temp = heap; 
		heap = new_node;
		new_node = temp;
	}

	heap->left = new_node;
	new_node->right = heap;
	(heap->left)->right = new_node->right;
	(new_node->right)->left = heap->left;

	return heap;

}

void HeapFibonacci::clean_parent_and_mark(Node* node) {
	if(node==NULL)return;
	Node* temp = node;
	do {
		temp->mark = false;
		temp->parent = NULL;
		temp = temp->left;
	} while(temp != node);
}

void HeapFibonacci::add_child_node(Node* parent, Node* child) {
	child->right=child->left=child;
	child->parent=parent;
	parent->degree++;
	parent->child=merge_node(parent->child,child);
}

Node* HeapFibonacci::delete_min(Node* heap) {
	clean_parent_and_mark(heap->child);
	if(heap->left == heap) {
		heap = heap->child;
	} else {
		heap->left->right = heap->right;
		heap->right->left = heap->left;
		heap = merge_node(heap->left, heap->child);
	}
	if(heap == NULL) return heap;
	Node* A[heap->degree+1] = {NULL};
	Node* t = NULL;
	do {
		if(A[heap->degree] != NULL) {
			t = A[heap->degree];
			A[heap->degree] = NULL;
			if(heap->key < t->key) {
				(t->right)->left = t->left;
				(t->left)->right = t->right;
				add_child_node(heap, t);
			} else {
				(t->right)->left = t->left;
				(t->left)->right = t->right;
				if(heap->left == heap) {
					t->left = t->right = t;
					add_child_node(t, heap);
					heap = t;
				} else {
					(heap->right)->left = t;
					(heap->left)->right = t;
					t->left = heap->left;
					t->right = heap->right;
					add_child_node(t, heap);
					heap = t;
				}
			}
			continue;
		} else {
			A[heap->degree] = heap;
		}
		heap = heap->left;
	} while(t != heap);

	Node* min = heap;
	do {
		if(heap->key < min->key) min = heap;
		heap = heap->left;
	}while(heap != min);
	
	return min;
}

Node* HeapFibonacci::cut(Node* heap, Node* n) {
	if(n->left == n) {
		(n->parent)->child = NULL;
	} else {
		(n->left)->right = n->right;
		(n->right)->left = n->left;
		(n->parent)->child = n->left;
	}
	n->left = n->right = n;
	n->mark = false;
	return merge_node(heap, n);


}

Node* HeapFibonacci::insert(double key) {
	Node* new_node = create_node(key);
	H = merge_node(H, new_node);
	return new_node;
}

Node* HeapFibonacci::extract_min() {
	Node* min = H;
	H = delete_min(H);
	return min;
}

void HeapFibonacci::decrease_key(Node* n, double value) {
	if(n->key < value) exit(0);
	n->key = value;
	if(n->key < n->parent->key) {
		H = cut(H, n);
		Node* parent = n->parent;
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