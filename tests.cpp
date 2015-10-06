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
	assert(fib.insert(5, myStruct1).oid == 0);
	assert(fib.size() == 1);
	
	assert(fib.insert(-18, myStruct2).oid == 1);
	assert(fib.size() == 2);
	
	assert(fib.insert(8, myStruct3).oid == 2);
	assert(fib.size() == 3);
	
	assert(fib.insert(10, myStruct4).oid == 3);
	assert(fib.size() == 4);
	
	assert(fib.insert(-17, myStruct5).oid == 4);
	assert(fib.size() == 5);
	
	assert(fib.insert(56, myStruct6).oid == 5);
	assert(fib.size() == 6);
	
	assert(fib.insert(1, myStruct7).oid == 6);
	assert(fib.size() == 7);

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
	NodeData<Persona> a = fib.insert(5, myStruct1);
	NodeData<Persona> b = fib.insert(-18, myStruct2);
	NodeData<Persona> c = fib.insert(8, myStruct3);
	NodeData<Persona> d = fib.insert(10, myStruct4);
	NodeData<Persona> e = fib.insert(-17, myStruct5);
	NodeData<Persona> f = fib.insert(56, myStruct6);
	NodeData<Persona> g = fib.insert(1, myStruct7);

	assert(fib.get_id(a.address) == 0);
	assert(fib.get_id(b.address) == 1);
	assert(fib.get_id(c.address) == 2);
	assert(fib.get_id(d.address) == 3);
	assert(fib.get_id(e.address) == 4);
	assert(fib.get_id(f.address) == 5);
	assert(fib.get_id(g.address) == 6);

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
	fib.insert(5, myStruct1); 		assert(fib.size() == 1);
	fib.insert(-18, myStruct2);   	assert(fib.size() == 2);
	fib.insert(8, myStruct3);		assert(fib.size() == 3);
	fib.insert(10, myStruct4);		assert(fib.size() == 4);
	fib.insert(-17, myStruct5);	assert(fib.size() == 5);
	fib.insert(56, myStruct6);		assert(fib.size() == 6);
	fib.insert(1, myStruct7);		assert(fib.size() == 7);

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
	fib.insert(5, myStruct1);	assert(fib.minimum().id == 5);
	fib.insert(10, myStruct4);	assert(fib.minimum().id == 5);
	fib.insert(8, myStruct3);	assert(fib.minimum().id == 5);
	fib.insert(-18, myStruct2);	assert(fib.minimum().id == -18);
	fib.insert(-17, myStruct5);	assert(fib.minimum().id == -18);
	fib.insert(56, myStruct6);	assert(fib.minimum().id == -18);
	fib.insert(1, myStruct7);	assert(fib.minimum().id == -18);

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

	fib.insert(myStruct1.id, myStruct1);
	fib.insert(myStruct2.id, myStruct2);
	fib.insert(myStruct3.id, myStruct3);
	fib.insert(myStruct4.id, myStruct4);
	fib.insert(myStruct5.id, myStruct5);
	fib.insert(myStruct6.id, myStruct6);
	fib.insert(myStruct7.id, myStruct7);


	printf("%s", "[Test] EXTRACT_MINIMUM method: ");

	assert(fib.minimum().id == -18);
	
	result = fib.extract_min();
		assert(result.id == -18);
		assert(fib.minimum().id == -17);

	result = fib.extract_min();
		assert(result.id == -17);
		assert(fib.minimum().id == 1);

	result = fib.extract_min();
		assert(result.id == 1);
		assert(fib.minimum().id == 5);

	result = fib.extract_min();
		assert(result.id == 5);
		assert(fib.minimum().id == 10);

	result = fib.extract_min();
		assert(result.id == 10);
		assert(fib.minimum().id == 10);

	result = fib.extract_min();
		assert(result.id == 10);
		assert(fib.minimum().id == 56);

	result = fib.extract_min();
		assert(result.id == 56);

	printf("Success!\n");
};

void TEST_DECREASE_KEY() {
	Persona myStruct1{1, 'a'},
			myStruct2{2, 'b'},
			myStruct3{3, 'c'};
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	fib.insert(-10, myStruct1);
	fib.insert(1, myStruct2);
	fib.insert(-20, myStruct3);

	printf("%s", "[Test] DECREASE_KEY method: ");

	fib.node_up(0, -30);

	assert(fib.minimum().id == 1);
	
	printf("Success!\n");
};

void TEST_DELETE_NODE() {
	Persona myStruct1{1, 'a'},
			myStruct2{2, 'b'},
			myStruct3{3, 'c'},
			result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("[Test] DELETE_NODE method: ");

	fib.insert(-10, myStruct1);
	fib.insert(1, myStruct2);
	fib.insert(-20, myStruct3);

	assert(fib.minimum().id == 3);

	fib.delete_node(2);

	assert(fib.size() == 2);
	assert(fib.minimum().id == 1);

	result = fib.extract_min();

	assert(result.id == 1);
	assert(fib.size() == 1);
	assert(fib.minimum().id == 2);

	result = fib.extract_min();
	assert(result.id == 2);
	assert(fib.size() == 0);

	printf("Success!\n");
}

void recharge(FibonacciHeap<int>& Q, vector<int>& v) {
	random_device rd;
  	default_random_engine gen(rd());
  	uniform_int_distribution<int> d(0, 10000);
  	int size = v.size();

  	Q.clear();

  	assert(Q.size() == 0);
	for (int i = 0; i < size; ++i) {
		auto x = d(gen);
		v[size-1-i] = x;
		Q.insert(x, x);
		assert(Q.size() == i+1);
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
		assert(a[i] == Q.extract_min());
		if(Q.size())
			assert(a[i+1] == Q.minimum());
	}


	Q.clear();
	assert(Q.size() == 0);

	for (int i = 0; i < test_size; ++i)
		Q.insert(i, ( test_size/15000 <= i && i < test_size/10000 ? 10: -10 ));

	for (int i = test_size/15000; i < test_size/10000; ++i)
		Q.node_up(i, numeric_limits<int>::lowest());

	for (int i = test_size/15000; i < test_size/10000; ++i)
		assert(10 == Q.extract_min());

	for (int i = test_size/10000 - test_size/15000; i < test_size; ++i)
		assert(-10 == Q.extract_min());
	assert(Q.size() == 0);

	//Q.clear();

	assert(Q.insert(0, 50).oid == test_size);
	assert(Q.insert(11, 2).oid == test_size+1);
	assert(Q.insert(10, 3).oid == test_size+2);
	assert(Q.insert(10, 4).oid == test_size+3);

	assert(Q.extract_min() == 50);

	Q.node_up(test_size+1, 1);

	assert(Q.minimum() == 2);
	assert(Q.extract_min() == 2);
	assert(Q.minimum() == 3 || Q.minimum() == 4); //Node x


	//Q.clear();
	assert(Q.size() == 2);

	assert(Q.insert(0, 1).oid == test_size+4); //Min
	assert(Q.insert(numeric_limits<float>::max(), 2).oid == test_size+5); //Node a
	assert(Q.insert(numeric_limits<float>::max(), 30).oid == test_size+6); //Node b
	assert(Q.insert(numeric_limits<float>::max(), 4).oid == test_size+7); //Node c

	assert(Q.extract_min() == 1);

	assert(Q.size() == 5);

	auto min = Q.extract_min();
	assert(min == 3 || min == 4);

	assert(Q.size() == 4); //a(key max), b(key max), c(key max), x(key 10)

	//Min 3 ó 4 y despues estan los otros 3
	Q.node_up(test_size+5, 3338);
	Q.node_up(test_size+6, 430); //key = 430, value = 30
	Q.node_up(test_size+7, 4277);

	assert((min == 3 && Q.minimum() == 4)  ||  (min == 4 && Q.minimum() == 3));

	assert(Q.size() == 4);

	auto minBis = Q.extract_min();
	assert((min == 3 && minBis == 4)  ||  (min == 4 && minBis == 3));

	assert(Q.insert(1, 2).oid == test_size+8);
	assert(Q.insert(600, 3).oid == test_size+9);
	assert(Q.insert(600, 4).oid == test_size+10); 
	assert(Q.insert(0, 100).oid == test_size+11);
	assert(Q.insert(500, 2).oid == test_size+12);
	assert(Q.insert(500, 33).oid == test_size+13);
	assert(Q.insert(500, 4).oid == test_size+14);

	assert(Q.extract_min() == 100);
	assert(Q.extract_min() == 2);
	assert(Q.extract_min() == 30);

	// //Min 3 ó 4 y despues estan los otros 3
	Q.node_up(test_size+13, 435);

	assert(Q.extract_min() == 33);

	printf("Success!\n");
}

int main() {
	TEST_INSERT();
	TEST_GET_ID();
	TEST_SIZE();
	TEST_ASK_MINIMUM();
	TEST_EXTRACT_MINIMUM();
	TEST_DECREASE_KEY();
	TEST_DELETE_NODE();

	EXPENSIVE_TEST();

	printf("\nOK! All TEST passed!\n");
	return 0;
}