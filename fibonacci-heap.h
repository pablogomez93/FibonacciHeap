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
	vector<Node<T>*> children;
	Node* parent;
};

template<typename T>
class FibonacciHeap {
	
	typedef CircularLinkedList<Node<T>*> node_list;

	public:
		//Operations for a mergeable heap:
		FibonacciHeap();
		void FIB_HEAP_INSERT(int key, T* val);
		T* FIB_HEAP_MINIMUM();
		T* FIB_HEAP_EXTRACT_MIN();
		//void FIB_HEAP_UNION(FibonacciHeap&);
		void FIB_HEAP_DECREASE_KEY(Node<T>&, int);
		void FIB_HEAP_DELETE(Node<T>&);	
		int SIZE();	

	private:
		int _n;
		Node<T>* _min;
		node_list _roots;
		typename node_list::iterator _iterToMinimum, _rightNode;
		void swap(Node<T>** x, Node<T>** y);
		void CONSOLIDATE();
		void LINK(Node<T>* y, Node<T>* x);
		void CUT(Node<T>* x, Node<T>* y);
		void CASCADING_CUT(Node<T>* y);

};


template<typename T> 
FibonacciHeap<T>::FibonacciHeap() {
	_min   = nullptr;
	_n     = 0;
	_roots = node_list();
}


template<typename T>
void FibonacciHeap<T>::FIB_HEAP_INSERT(int key, T* val) {
	Node<T>* newGuest = new Node<T>{key, false, val, 0, vector<Node<T>*>(0, nullptr), nullptr};

	/**
	 * Adding node to the roots list of the heap. 
	 */
	_roots.push_back(newGuest);

	/**
	 * Update minimum of the entire heap.
	 */
	if(_min == nullptr || _min->key > newGuest->key) {
		_min = newGuest;
		_iterToMinimum = --(_roots.end());
	}

	/**
	 * Increase the count of the elements current in the heap.
	 */
	_n++;	
}


template<typename T> 
T* FibonacciHeap<T>::FIB_HEAP_MINIMUM() {
	return (_min == nullptr) ? (T*) _min : _min->value;
}


template<typename T> 
T* FibonacciHeap<T>::FIB_HEAP_EXTRACT_MIN() {
	if(_min == nullptr)	return nullptr;


	T* backup_min = _min->value;
	/**
	 * Applying all children of the smallest node as roots of the heap
	 * cleaning its parent (it becomes null).
	 */
	for (int i = 0; i < _min->children.size(); ++i)	{
		_min->children[i]->parent = nullptr;
		_roots.push_back(_min->children[i]);
	}
	
	/**
	 * Removing the minimum node of the root_list.
	 */
	_rightNode = _roots.right(_iterToMinimum);
	_roots.erase(_iterToMinimum);
	_min = nullptr;

	if(_roots.size() > 0) {
		//Tenía un hermano, y está en el iterador _rightNode
		_min = *_rightNode;
		CONSOLIDATE();
	}

	_n--;
	
	return backup_min;
}

template<typename T> 
void FibonacciHeap<T>::CONSOLIDATE() {
	vector<Node<T>*> roots_sort_by_degree;
	roots_sort_by_degree.reserve(_n);

	for (int i = 0; i < _n-1; i++)
		roots_sort_by_degree.push_back(nullptr);

	int roots_list_size_copy = _roots.size();
    for (int i = 0; i < roots_list_size_copy; i++) {
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

    _min = nullptr;

    for (int i = 0; i < roots_sort_by_degree.size(); i++) {
    	if(roots_sort_by_degree[i] != nullptr) {
    		if(_min == nullptr)	_roots.clear();

    		_roots.push_back(roots_sort_by_degree[i]);

    		if(_min == nullptr || ((roots_sort_by_degree[i]->key) < (_min->key))) {
    			_iterToMinimum = --(_roots.end());
    			_min = *_iterToMinimum;
    		}

    	}
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

	_roots.remove(y);
}


template<typename T> 
void FibonacciHeap<T>::FIB_HEAP_DECREASE_KEY(Node<T>& x, int k) {
	x->key = k;
	Node<T>* y = x->parent;

	if(y != nullptr && x->key < y->key) {
		CUT(x, y);
		CASCADING_CUT(y);
	}

	if(x->key < _min->key)
		_min = x;
}

template<typename T> 
void FibonacciHeap<T>::CUT(Node<T>* x, Node<T>* y) {
	y->children.erase(x);
	_roots.push_back(x);
	x->parent = nullptr;
	x->marked = false;
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
void FibonacciHeap<T>::FIB_HEAP_DELETE(Node<T>& x) {
	FIB_HEAP_DECREASE_KEY(x, numeric_limits<int>::lowest());
	FIB_HEAP_EXTRACT_MIN();
}

template<typename T> 
int FibonacciHeap<T>::SIZE() {
	return _n;
}


#endif //FIBHEAP_H