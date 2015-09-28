#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include "fibonacci-heap.h"

using namespace std;

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
			myStruct7{1, 'g'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("\n%s", "[Test] INSERT method: ");
	assert(fib.FIB_HEAP_INSERT(5, &myStruct1) == 0);
	assert(fib.SIZE() == 1);
	
	assert(fib.FIB_HEAP_INSERT(-18, &myStruct2) == 1);
	assert(fib.SIZE() == 2);
	
	assert(fib.FIB_HEAP_INSERT(8, &myStruct3) == 2);
	assert(fib.SIZE() == 3);
	
	assert(fib.FIB_HEAP_INSERT(10, &myStruct4) == 3);
	assert(fib.SIZE() == 4);
	
	assert(fib.FIB_HEAP_INSERT(-17, &myStruct5) == 4);
	assert(fib.SIZE() == 5);
	
	assert(fib.FIB_HEAP_INSERT(56, &myStruct6) == 5);
	assert(fib.SIZE() == 6);
	
	assert(fib.FIB_HEAP_INSERT(1, &myStruct7) == 6);
	assert(fib.SIZE() == 7);

	printf("Success!\n");
};

void TEST_GET_ID() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("%s", "[Test] GET_ID method: ");
	fib.FIB_HEAP_INSERT(5, &myStruct1);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);
	fib.FIB_HEAP_INSERT(8, &myStruct3);
	fib.FIB_HEAP_INSERT(10, &myStruct4);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);
	fib.FIB_HEAP_INSERT(56, &myStruct6);
	fib.FIB_HEAP_INSERT(1, &myStruct7);

	assert(fib.FIB_GET_ID(&myStruct1) == 0);
	assert(fib.FIB_GET_ID(&myStruct2) == 1);
	assert(fib.FIB_GET_ID(&myStruct3) == 2);
	assert(fib.FIB_GET_ID(&myStruct4) == 3);
	assert(fib.FIB_GET_ID(&myStruct5) == 4);
	assert(fib.FIB_GET_ID(&myStruct6) == 5);
	assert(fib.FIB_GET_ID(&myStruct7) == 6);

	printf("Success!\n");
};

void TEST_SIZE() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("%s", "[Test] SIZE method: ");
	fib.FIB_HEAP_INSERT(5, &myStruct1); 	assert(fib.SIZE() == 1);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);   assert(fib.SIZE() == 2);
	fib.FIB_HEAP_INSERT(8, &myStruct3);		assert(fib.SIZE() == 3);
	fib.FIB_HEAP_INSERT(10, &myStruct4);	assert(fib.SIZE() == 4);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);	assert(fib.SIZE() == 5);
	fib.FIB_HEAP_INSERT(56, &myStruct6);	assert(fib.SIZE() == 6);
	fib.FIB_HEAP_INSERT(1, &myStruct7);		assert(fib.SIZE() == 7);

	printf("Success!\n");
};


void TEST_ASK_MINIMUM() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();
	
	printf("%s", "[Test] MINIMUM method: ");
	fib.FIB_HEAP_INSERT(5, &myStruct1);		assert(fib.FIB_HEAP_MINIMUM()->id == 5);
	fib.FIB_HEAP_INSERT(10, &myStruct4);	assert(fib.FIB_HEAP_MINIMUM()->id == 5);
	fib.FIB_HEAP_INSERT(8, &myStruct3);		assert(fib.FIB_HEAP_MINIMUM()->id == 5);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);	assert(fib.FIB_HEAP_MINIMUM()->id == -18);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);	assert(fib.FIB_HEAP_MINIMUM()->id == -18);
	fib.FIB_HEAP_INSERT(56, &myStruct6);	assert(fib.FIB_HEAP_MINIMUM()->id == -18);
	fib.FIB_HEAP_INSERT(1, &myStruct7);		assert(fib.FIB_HEAP_MINIMUM()->id == -18);

	printf("Success!\n");

};

void TEST_EXTRACT_MINIMUM() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	fib.FIB_HEAP_INSERT(myStruct1.id, &myStruct1);
	fib.FIB_HEAP_INSERT(myStruct2.id, &myStruct2);
	fib.FIB_HEAP_INSERT(myStruct3.id, &myStruct3);
	fib.FIB_HEAP_INSERT(myStruct4.id, &myStruct4);
	fib.FIB_HEAP_INSERT(myStruct5.id, &myStruct5);
	fib.FIB_HEAP_INSERT(myStruct6.id, &myStruct6);
	fib.FIB_HEAP_INSERT(myStruct7.id, &myStruct7);


	printf("%s", "[Test] EXTRACT_MINIMUM method: ");
	
	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == -18);
		assert(fib.FIB_HEAP_MINIMUM()->id == -17);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == -17);
		assert(fib.FIB_HEAP_MINIMUM()->id == 1);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == 1);
		assert(fib.FIB_HEAP_MINIMUM()->id == 5);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == 5);
		assert(fib.FIB_HEAP_MINIMUM()->id == 8);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == 8);
		assert(fib.FIB_HEAP_MINIMUM()->id == 10);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == 10);
		assert(fib.FIB_HEAP_MINIMUM()->id == 56);

	result = fib.FIB_HEAP_EXTRACT_MIN();
		assert(result->id == 56);
		assert(fib.FIB_HEAP_MINIMUM() == nullptr);

	printf("Success!\n");
};

void TEST_DECREASE_KEY() {
	Persona myStruct1{1, 'a'},
			myStruct2{2, 'b'},
			myStruct3{3, 'c'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	fib.FIB_HEAP_INSERT(-10, &myStruct1);
	fib.FIB_HEAP_INSERT(1, &myStruct2);
	fib.FIB_HEAP_INSERT(-20, &myStruct3);

	printf("%s", "[Test] DECREASE_KEY method: ");

	fib.FIB_HEAP_DECREASE_KEY(0, -30);

	assert(fib.FIB_HEAP_MINIMUM()->id == 1);
	
	printf("Success!\n");
};

void TEST_DELETE() {
	Persona myStruct1{1, 'a'},
			myStruct2{2, 'b'},
			myStruct3{3, 'c'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	printf("%s", "[Test] DELETE method: ");

	fib.FIB_HEAP_INSERT(-10, &myStruct1);
	fib.FIB_HEAP_INSERT(1, &myStruct2);
	fib.FIB_HEAP_INSERT(-20, &myStruct3);

	assert(fib.FIB_HEAP_MINIMUM()->id == 3);

	fib.FIB_HEAP_DELETE(2);

	assert(fib.SIZE() == 2);
	assert(fib.FIB_HEAP_MINIMUM()->id == 1);

	result = fib.FIB_HEAP_EXTRACT_MIN();

	assert(result->id == 1);
	assert(fib.SIZE() == 1);
	assert(fib.FIB_HEAP_MINIMUM()->id == 2);

	result = fib.FIB_HEAP_EXTRACT_MIN();
	assert(result->id == 2);
	assert(fib.SIZE() == 0);

	printf("Success!\n");
}

void EXPENSIVE_TEST() {

}

int main() {
	TEST_INSERT();
	TEST_GET_ID();
	TEST_SIZE();
	TEST_ASK_MINIMUM();
	TEST_EXTRACT_MINIMUM();
	TEST_DELETE();
	TEST_DECREASE_KEY();
	TEST_DELETE();

	EXPENSIVE_TEST();

	printf("\nOK! All TEST passed!\n");
	return 0;
}