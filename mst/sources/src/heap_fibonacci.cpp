#include "../inc/heap_fibonacci.h"

HeapFibonacci::HeapFibonacci() {
	this->H = NULL;
	this->size = 0;
}

NodeFibonacci* HeapFibonacci::create_NodeFibonacci(double key, int vertice) {
	NodeFibonacci* temp = new NodeFibonacci;
	temp->value = key;
	temp->vertice = vertice;
	temp->degree = 0;
	temp->parent = NULL;
	temp->child = NULL;
	temp->marked = false;
	temp->next = temp;
	temp->prev = temp;
	return temp; 
}

NodeFibonacci* HeapFibonacci::merge_NodeFibonacci(NodeFibonacci* a, NodeFibonacci* b) {
	if(a==NULL)return b;
	if(b==NULL)return a;
	if(a->value>b->value) {
		NodeFibonacci* temp=a;
		a=b;
		b=temp;
	}
	NodeFibonacci* an=a->next;
	NodeFibonacci* bp=b->prev;
	a->next=b;
	b->prev=a;
	an->prev=bp;
	bp->next=an;
	return a;
}

void HeapFibonacci::clean_parent_and_mark(NodeFibonacci* nodeFibonacci) {
	if(nodeFibonacci==NULL)return;
	NodeFibonacci* temp = nodeFibonacci;
	do {
		temp->marked = false;
		temp->parent = NULL;
		temp = temp->next;
	} while(temp != nodeFibonacci);
}

void HeapFibonacci::add_child_NodeFibonacci(NodeFibonacci* parent, NodeFibonacci* child) {
	child->prev=child->next=child;
	child->parent=parent;
	parent->degree++;
	parent->child=merge_NodeFibonacci(parent->child,child);
}

NodeFibonacci* HeapFibonacci::delete_min(NodeFibonacci* n) {
	clean_parent_and_mark(n->child);
	if(n->next==n) {
		n=n->child;
	} else {
		n->next->prev=n->prev;
		n->prev->next=n->next;
		n=merge_NodeFibonacci(n->next,n->child);
	}
	if(n==NULL)return n;
	NodeFibonacci* trees[64]={NULL};	
	while(true) {
		if(trees[n->degree]!=NULL) {
			NodeFibonacci* t=trees[n->degree];
			if(t==n)break;
			trees[n->degree]=NULL;
			if(n->value<t->value) {
				t->prev->next=t->next;
				t->next->prev=t->prev;
				add_child_NodeFibonacci(n,t);
			} else {
				t->prev->next=t->next;
				t->next->prev=t->prev;
				if(n->next==n) {
					t->next=t->prev=t;
					add_child_NodeFibonacci(t,n);
					n=t;
				} else {
					n->prev->next=t;
					n->next->prev=t;
					t->next=n->next;
					t->prev=n->prev;
					add_child_NodeFibonacci(t,n);
					n=t;
				}
			}
			continue;
		} else {
			trees[n->degree]=n;
		}
		n=n->next;
	}
	NodeFibonacci* min=n;
	NodeFibonacci* start=n;
	do {
		if(n->value<min->value)min=n;			
		n=n->next;
	} while(n!=start);
	return min;
}

NodeFibonacci* HeapFibonacci::cut(NodeFibonacci* heap, NodeFibonacci* n) {
	if(n->next==n) {
		n->parent->child=NULL;
	} else {
		n->next->prev=n->prev;
		n->prev->next=n->next;
		n->parent->child=n->next;
	}
	n->next=n->prev=n;
	n->marked=false;
	return merge_NodeFibonacci(heap,n);

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
	NodeFibonacci* heap = H;
	if(n->value<value) exit(0);
	n->value=value;
	if(n->parent) {
		if(n->value<n->parent->value) {
			heap=cut(heap,n);
			NodeFibonacci* parent=n->parent;
			n->parent=NULL;
			while(parent!=NULL && parent->marked) {
				heap=cut(heap,parent);
				n=parent;
				parent=n->parent;
				n->parent=NULL;
			}
			if(parent!=NULL && parent->parent!=NULL)parent->marked=true;
		}
	} else {
		if(n->value < heap->value) {
			heap = n;
		}
	}
	H = heap;
}