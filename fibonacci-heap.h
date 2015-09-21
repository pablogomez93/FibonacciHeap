#ifndef FIBHEAP_H
#define FIBHEAP_H

#include <limits>
#include <vector>
#include "circular_doubly_linked_list/circular_doubly_linked_list.h"

/**
 * This fibonacci heap implementation requires a std of c++11 to compile well.
 * If you use the Makefile attached, it will do it for you :).
 */

using namespace std;

template<typename T> 
struct Node {
	int key;
	bool marked;
	T* value;
	int degree;
	CircularLinkedList<Node<T>*> children;
	Node* parent;
	int oid;
};

template<typename T>
class FibonacciHeap {
	
	typedef CircularLinkedList<Node<T>*> node_list;

	public:
		//Operations for a mergeable heap:
		FibonacciHeap();
		int FIB_HEAP_INSERT(int key, T* val);
		T* FIB_HEAP_MINIMUM();
		T* FIB_HEAP_EXTRACT_MIN();
		//void FIB_HEAP_UNION(FibonacciHeap&);
		void FIB_HEAP_DECREASE_KEY(int, int);
		void FIB_HEAP_DELETE(int);	
		int SIZE();	

	private:
		int _n, _next_oid;
		node_list _roots;
		vector<typename node_list::iterator> _references;
		typename node_list::iterator _min, _rightNode;
		void swap(Node<T>** x, Node<T>** y);
		void CONSOLIDATE();
		void LINK(Node<T>* y, Node<T>* x);
		void CUT(Node<T>* x, Node<T>* y);
		void CASCADING_CUT(Node<T>* y);

};


template<typename T> 
FibonacciHeap<T>::FibonacciHeap() {
	_min = _roots.end();
	_n     = 0;
	_roots = node_list();
	_next_oid = 0;
}


template<typename T>
int FibonacciHeap<T>::FIB_HEAP_INSERT(int key, T* val) {
	Node<T>* newGuest = new Node<T>{key, false, val, 0, node_list(), nullptr, _next_oid++};

	/**
	 * Adding node to the roots list of the heap. 
	 */
	_roots.push_back(newGuest);

	/**
	 * Save a reference to the new node
	 */
	_references.push_back(--(_roots.end()));

	/**
	 * Update minimum of the entire heap.
	 */
	if(_min == _roots.end() || (*_min)->key > newGuest->key)
		_min = --(_roots.end());

	/**
	 * Increase the count of the elements current in the heap.
	 */
	_n++;

	return newGuest->oid;
}


template<typename T> 
T* FibonacciHeap<T>::FIB_HEAP_MINIMUM() {
	return _min == _roots.end() ? nullptr : (*_min)->value;
}


template<typename T> 
T* FibonacciHeap<T>::FIB_HEAP_EXTRACT_MIN() {
	if(_min == _roots.end())	return nullptr;

	T* backup_min = (*_min)->value;

	/**
	 * Applying all children of the smallest node as roots of the heap
	 * cleaning its parent (it becomes null).
	 */
	for (typename node_list::iterator it = (*_min)->children.begin(); it != (*_min)->children.end(); ++it) {
		(*it)->parent = nullptr;
		_roots.push_back(*it);

		_references[(*it)->oid] = --(_roots.end());
	}

	/**
	 * Removing the minimum node of the root_list.
	 */
	_rightNode = _roots.right(_min);
	_roots.erase(_min);
	_min = _roots.end();

	if(_roots.size() > 0)
		CONSOLIDATE();

	_n--;
	
	return backup_min;
}

template<typename T> 
void FibonacciHeap<T>::CONSOLIDATE() {

	vector<Node<T>*> roots_sort_by_degree;
	roots_sort_by_degree.reserve(_n);

	for (int i = 0; i < _n-1; i++)
		roots_sort_by_degree.push_back(nullptr);

    for (int i = _roots.size(); i > 0; i--) {
    	Node<T>* x  = (*_rightNode);
    	_rightNode = _roots.right(_rightNode);

		int d = x->degree;
		while(roots_sort_by_degree[d] != nullptr) {
			Node<T>* y = roots_sort_by_degree[d];

			if(x->key > y->key)
				swap(&x, &y);

			LINK(y, x);
			roots_sort_by_degree[d] = nullptr;
			d++;
		}

		roots_sort_by_degree[d] = x;
    }

    _min = _roots.end();

    for (int i = 0; i < roots_sort_by_degree.size(); i++)
    	if(roots_sort_by_degree[i] != nullptr) {
    		if(_min == _roots.end())	
    			_roots.clear();

    		_roots.push_back(roots_sort_by_degree[i]);

    		if(_min == _roots.end() || roots_sort_by_degree[i]->key < (*_min)->key)
    			_min = --(_roots.end());

    	}

}

template<typename T> 
void FibonacciHeap<T>::swap(Node<T>** x, Node<T>** y) {
	Node<T>* temp = *x;
	*x = *y;
	*y = temp;
}

template<typename T> 
void FibonacciHeap<T>::LINK(Node<T>* y, Node<T>* x) {
	x->children.push_back(y);
	x->degree++;
	y->marked = false;

	_references[y->oid] = --((x->children).end());

	_roots.remove(y);
}


template<typename T> 
void FibonacciHeap<T>::FIB_HEAP_DECREASE_KEY(int node_id, int k) {
	Node<T>* x = *(_references[node_id]);

	x->key = k;

	if(x->parent != nullptr && x->key < x->parent->key) {
		CUT(x, x->parent);
		CASCADING_CUT(x->parent);
	}

	if(x->key < (*_min)->key) 
		_min = _references[node_id];
}

template<typename T> 
void FibonacciHeap<T>::CUT(Node<T>* x, Node<T>* y) {
	y->children.erase(_references[x->oid]);
	x->parent = nullptr;
	x->marked = false;

	_roots.push_back(x);

	_references[x->oid] = --(_roots.end());
}

template<typename T> 
void FibonacciHeap<T>::CASCADING_CUT(Node<T>* y) {
	Node<T>* z = y->parent;
	if(z != nullptr)
		if(!y->marked) {
			y->marked = true;
		} else {
			CUT(y, z);
			CASCADING_CUT(z);
		}
}

template<typename T> 
void FibonacciHeap<T>::FIB_HEAP_DELETE(int node_id) {
	FIB_HEAP_DECREASE_KEY(node_id, numeric_limits<int>::lowest());
	FIB_HEAP_EXTRACT_MIN();
}

template<typename T> 
int FibonacciHeap<T>::SIZE() {
	return _n;
}


#endif //FIBHEAP_H