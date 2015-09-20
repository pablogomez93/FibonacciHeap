all:
	@g++ -std=c++11 tests.cpp -o fibonaccih

runtests:
	./fibonaccih

clear:
	@rm fibonaccih
