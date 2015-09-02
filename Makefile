all:
	@gcc fibonacci.c -o fibonaccic
	@g++ fibonacci.cpp -o fibonaccicpp

clear:
	@rm fibonaccic
	@rm fibonaccicpp
