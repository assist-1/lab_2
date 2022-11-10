#include <iostream>

int STREAM_SIZE     = 256;
int NUMBERS_SIZE    = 256;
int OPERATIONS_SIZE = 256;

int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9')
		return 1;
	return 0;

int IsOperation(char sybmol) {
	if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	return 0;
}

double Calculate(double x, char operation, double y) {
	switch(operation) {
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
		default:  return 0;
	}
}