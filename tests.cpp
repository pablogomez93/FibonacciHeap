#include <iostream>
#include "fibonacci-heap.h"

using namespace std;

struct Persona {
	int id;
	char name;
};

void TEST_INSERT_ELEMENTS() {
	Persona myStruct1{5, 'a'},
			myStruct2{-18, 'b'},
			myStruct3{8, 'c'},
			myStruct4{10, 'd'},
			myStruct5{-17, 'e'},
			myStruct6{56, 'f'},
			myStruct7{1, 'g'},
			*result;
	FibonacciHeap<Persona> fib = FibonacciHeap<Persona>();

	fib.FIB_HEAP_INSERT(5, &myStruct1);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);
	fib.FIB_HEAP_INSERT(8, &myStruct3);
	fib.FIB_HEAP_INSERT(10, &myStruct4);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);
	fib.FIB_HEAP_INSERT(56, &myStruct6);
	fib.FIB_HEAP_INSERT(1, &myStruct7);
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

	printf("\n%s\n", "Test de size:");
	fib.FIB_HEAP_INSERT(5, &myStruct1);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);
	fib.FIB_HEAP_INSERT(8, &myStruct3);
	fib.FIB_HEAP_INSERT(10, &myStruct4);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);
	fib.FIB_HEAP_INSERT(56, &myStruct6);
	fib.FIB_HEAP_INSERT(1, &myStruct7);
	printf("Size: %d\n\n", fib.SIZE());
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
	fib.FIB_HEAP_INSERT(5, &myStruct1);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);
	fib.FIB_HEAP_INSERT(8, &myStruct3);
	fib.FIB_HEAP_INSERT(10, &myStruct4);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);
	fib.FIB_HEAP_INSERT(56, &myStruct6);
	fib.FIB_HEAP_INSERT(1, &myStruct7);

	printf("%s\n", "Test de get minumum:");
	result = fib.FIB_HEAP_MINIMUM();
	printf("%d\n\n\n", result->id);

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
	fib.FIB_HEAP_INSERT(5, &myStruct1);
	fib.FIB_HEAP_INSERT(-18, &myStruct2);
	fib.FIB_HEAP_INSERT(8, &myStruct3);
	fib.FIB_HEAP_INSERT(10, &myStruct4);
	fib.FIB_HEAP_INSERT(-17, &myStruct5);
	fib.FIB_HEAP_INSERT(56, &myStruct6);
	fib.FIB_HEAP_INSERT(1, &myStruct7);

	printf("%s\n", "Test de extract minumum 1:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
	printf("MINIMO QUE QUEDO: %d\n\n\n", fib.FIB_HEAP_MINIMUM()->id);

	printf("%s\n", "Test de extract minumum 2:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
	printf("MINIMO QUE QUEDO: %d\n\n\n", fib.FIB_HEAP_MINIMUM()->id);

	printf("%s\n", "Test de extract minumum 3:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
	printf("MINIMO QUE QUEDO: %d\n\n\n", fib.FIB_HEAP_MINIMUM()->id);

	printf("%s\n", "Test de extract minumum 4:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
	printf("MINIMO QUE QUEDO: %d\n\n\n", fib.FIB_HEAP_MINIMUM()->id);

	printf("%s\n", "Test de extract minumum 5:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
	printf("MINIMO QUE QUEDO: %d\n\n\n", fib.FIB_HEAP_MINIMUM()->id);

	printf("%s\n", "Test de extract minumum 6:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
	printf("MINIMO QUE QUEDO: %d\n\n\n", fib.FIB_HEAP_MINIMUM()->id);

	printf("%s\n", "Test de extract minumum 7:");
	result = fib.FIB_HEAP_EXTRACT_MIN();
	printf("MINIMO EXTRAIDO : %d\n", result->id);
};

void TEST_DELETE() {

};

void TEST_DECREASE_KEY() {

};

int main() {
	TEST_INSERT_ELEMENTS();
	TEST_SIZE();
	TEST_ASK_MINIMUM();
	TEST_EXTRACT_MINIMUM();
	TEST_DELETE();
	TEST_DECREASE_KEY();

	return 0;
}