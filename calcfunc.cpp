#include <iostream>

int STREAM_SIZE     = 256;
int NUMBERS_SIZE    = 256;
int OPERATIONS_SIZE = 256;

int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9')
		return 1;
	return 0;