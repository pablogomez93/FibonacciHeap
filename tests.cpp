#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <assert.h>
#include "fibonacci-heap.h"

using namespace std;
using namespace Fibonacci_Heap;

struct Persona {
	int id;
	char name;
};

void TEST_INSERT() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'};
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("\n%s", "[Test] INSERT method: ");
	assert(fib.FIB_HEAP_INSERT(5, myStruct1).oid == 0);
	assert(fib.FIB_HEAP_SIZE() == 1);
	
	assert(fib.FIB_HEAP_INSERT(-18, myStruct2).oid == 1);
	assert(fib.FIB_HEAP_SIZE() == 2);
	
	assert(fib.FIB_HEAP_INSERT(8, myStruct3).oid == 2);
	assert(fib.FIB_HEAP_SIZE() == 3);
	
	assert(fib.FIB_HEAP_INSERT(10, myStruct4).oid == 3);
	assert(fib.FIB_HEAP_SIZE() == 4);
	
	assert(fib.FIB_HEAP_INSERT(-17, myStruct5).oid == 4);
	assert(fib.FIB_HEAP_SIZE() == 5);
	
	assert(fib.FIB_HEAP_INSERT(56, myStruct6).oid == 5);
	assert(fib.FIB_HEAP_SIZE() == 6);
	
	assert(fib.FIB_HEAP_INSERT(1, myStruct7).oid == 6);
	assert(fib.FIB_HEAP_SIZE() == 7);

	printf("Success!\n");
};


void TEST_GET_ID() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'};
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("%s", "[Test] GET_ID method: ");
	NodeData<Persona> a = fib.FIB_HEAP_INSERT(5, myStruct1);
	NodeData<Persona> b = fib.FIB_HEAP_INSERT(-18, myStruct2);
	NodeData<Persona> c = fib.FIB_HEAP_INSERT(8, myStruct3);
	NodeData<Persona> d = fib.FIB_HEAP_INSERT(10, myStruct4);
	NodeData<Persona> e = fib.FIB_HEAP_INSERT(-17, myStruct5);
	NodeData<Persona> f = fib.FIB_HEAP_INSERT(56, myStruct6);
	NodeData<Persona> g = fib.FIB_HEAP_INSERT(1, myStruct7);

	assert(fib.FIB_GET_ID(a.address) == 0);
	assert(fib.FIB_GET_ID(b.address) == 1);
	assert(fib.FIB_GET_ID(c.address) == 2);
	assert(fib.FIB_GET_ID(d.address) == 3);
	assert(fib.FIB_GET_ID(e.address) == 4);
	assert(fib.FIB_GET_ID(f.address) == 5);
	assert(fib.FIB_GET_ID(g.address) == 6);

	printf("Success!\n");
};

void TEST_SIZE() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'};
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("%s", "[Test] SIZE method: ");
	fib.FIB_HEAP_INSERT(5, myStruct1); 		assert(fib.FIB_HEAP_SIZE() == 1);
	fib.FIB_HEAP_INSERT(-18, myStruct2);   	assert(fib.FIB_HEAP_SIZE() == 2);
	fib.FIB_HEAP_INSERT(8, myStruct3);		assert(fib.FIB_HEAP_SIZE() == 3);
	fib.FIB_HEAP_INSERT(10, myStruct4);		assert(fib.FIB_HEAP_SIZE() == 4);
	fib.FIB_HEAP_INSERT(-17, myStruct5);	assert(fib.FIB_HEAP_SIZE() == 5);
	fib.FIB_HEAP_INSERT(56, myStruct6);		assert(fib.FIB_HEAP_SIZE() == 6);
	fib.FIB_HEAP_INSERT(1, myStruct7);		assert(fib.FIB_HEAP_SIZE() == 7);

	printf("Success!\n");
};


void TEST_ASK_MINIMUM() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'};
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();
	
	printf("%s", "[Test] MINIMUM method: ");
	fib.FIB_HEAP_INSERT(5, myStruct1);		assert(fib.FIB_HEAP_MINIMUM().id == 5);
	fib.FIB_HEAP_INSERT(10, myStruct4);	assert(fib.FIB_HEAP_MINIMUM().id == 5);
	fib.FIB_HEAP_INSERT(8, myStruct3);		assert(fib.FIB_HEAP_MINIMUM().id == 5);
	fib.FIB_HEAP_INSERT(-18, myStruct2);	assert(fib.FIB_HEAP_MINIMUM().id == -18);
	fib.FIB_HEAP_INSERT(-17, myStruct5);	assert(fib.FIB_HEAP_MINIMUM().id == -18);
	fib.FIB_HEAP_INSERT(56, myStruct6);	assert(fib.FIB_HEAP_MINIMUM().id == -18);
	fib.FIB_HEAP_INSERT(1, myStruct7);		assert(fib.FIB_HEAP_MINIMUM().id == -18);

	printf("Success!\n");

};

void TEST_EXTRACT_MINIMUM() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{10, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'},
			result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	fib.FIB_HEAP_INSERT(myStruct1.id, myStruct1);
	fib.FIB_HEAP_INSERT(myStruct2.id, myStruct2);
	fib.FIB_HEAP_INSERT(myStruct3.id, myStruct3);
	fib.FIB_HEAP_INSERT(myStruct4.id, myStruct4);
	fib.FIB_HEAP_INSERT(myStruct5.id, myStruct5);
	fib.FIB_HEAP_INSERT(myStruct6.id, myStruct6);
	fib.FIB_HEAP_INSERT(myStruct7.id, myStruct7);


	printf("%s", "[Test] EXTRACT_MINIMUM method: ");

	assert(fib.FIB_HEAP_MINIMUM().id == -18);
	
	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == -18);
		assert(fib.FIB_HEAP_MINIMUM().id == -17);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == -17);
		assert(fib.FIB_HEAP_MINIMUM().id == 1);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == 1);
		assert(fib.FIB_HEAP_MINIMUM().id == 5);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == 5);
		assert(fib.FIB_HEAP_MINIMUM().id == 10);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == 10);
		assert(fib.FIB_HEAP_MINIMUM().id == 10);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == 10);
		assert(fib.FIB_HEAP_MINIMUM().id == 56);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result.id == 56);

	printf("Success!\n");
};

void TEST_DECREASE_KEY() {
	Persona myStruct1{1, 'a'},
			myStruct2{2, 'b'},
			myStruct3{3, 'c'};
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	fib.FIB_HEAP_INSERT(-10, myStruct1);
	fib.FIB_HEAP_INSERT(1, myStruct2);
	fib.FIB_HEAP_INSERT(-20, myStruct3);

	printf("%s", "[Test] DECREASE_KEY method: ");

	fib.FIB_HEAP_DECREASE_KEY(0, -30);

	assert(fib.FIB_HEAP_MINIMUM().id == 1);
	
	printf("Success!\n");
};

void TEST_DELETE() {
	Persona myStruct1{1, 'a'},
			myStruct2{2, 'b'},
			myStruct3{3, 'c'},
			result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("[Test] DELETE method: ");

	fib.FIB_HEAP_INSERT(-10, myStruct1);
	fib.FIB_HEAP_INSERT(1, myStruct2);
	fib.FIB_HEAP_INSERT(-20, myStruct3);

	assert(fib.FIB_HEAP_MINIMUM().id == 3);

	fib.FIB_HEAP_DELETE(2);

	assert(fib.FIB_HEAP_SIZE() == 2);
	assert(fib.FIB_HEAP_MINIMUM().id == 1);

	result = fib.FIB_HEAP_EXTRACT_MIN();

	assert(result.id == 1);
	assert(fib.FIB_HEAP_SIZE() == 1);
	assert(fib.FIB_HEAP_MINIMUM().id == 2);

	result = fib.FIB_HEAP_EXTRACT_MIN();
	assert(result.id == 2);
	assert(fib.FIB_HEAP_SIZE() == 0);

	printf("Success!\n");
}

void recharge(FibonacciHeap<int>& Q, vector<int>& v) {
	random_device rd;
  	default_random_engine gen(rd());
  	uniform_int_distribution<int> d(0, 10000);
  	int size = v.size();

  	Q.FIB_HEAP_CLEAR();

  	assert(Q.FIB_HEAP_SIZE() == 0);
	for (int i = 0; i < size; ++i) {
		auto x = d(gen);
		v[size-1-i] = x;
		Q.FIB_HEAP_INSERT(x, x);
		assert(Q.FIB_HEAP_SIZE() == i+1);
	}

	sort(v.begin(), v.end());
}

void EXPENSIVE_TEST() {
	printf("[Expensive Test]: ");

	FibonacciHeap<int> Q;
	uint test_size = 500000;
	vector<int> a(test_size, 0);
	
	recharge(Q, a);

	for (uint i = 0; i < test_size; ++i) {
		assert(a[i] == Q.FIB_HEAP_EXTRACT_MIN());
		if(Q.FIB_HEAP_SIZE())
			assert(a[i+1] == Q.FIB_HEAP_MINIMUM());
	}


	Q.FIB_HEAP_CLEAR();

	for (int i = 0; i < test_size; ++i)
		Q.FIB_HEAP_INSERT(i, ( test_size/15000 <= i && i < test_size/10000 ? 10: -10 ));

	for (int i = test_size/15000; i < test_size/10000; ++i)
		Q.FIB_HEAP_DECREASE_KEY(i, numeric_limits<int>::lowest());

	for (int i = test_size/15000; i < test_size/10000; ++i)
		assert(10 == Q.FIB_HEAP_EXTRACT_MIN());

	for (int i = test_size/10000 - test_size/15000; i < test_size; ++i)
		assert(-10 == Q.FIB_HEAP_EXTRACT_MIN());

	assert(Q.FIB_HEAP_SIZE() == 0);

	printf("Success!\n");
}

int main() {
	TEST_INSERT();
	TEST_GET_ID();
	TEST_SIZE();
	TEST_ASK_MINIMUM();
	TEST_EXTRACT_MINIMUM();
	TEST_DECREASE_KEY();
	TEST_DELETE();

	EXPENSIVE_TEST();

	printf("\nOK! All TEST passed!\n");
	return 0;
}