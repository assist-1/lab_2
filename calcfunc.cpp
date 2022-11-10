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

void InfNotation() {
	char stream[STREAM_SIZE];
	int numbers[NUMBERS_SIZE];
	char operations[OPERATIONS_SIZE];
	int token_quantity   = 0;
	int index_stream     = 0;
	int index_numbers    = 0;
	int index_operations = 0;
	int number1, number2;
	std::cin >> stream;
	char token = stream[0];
	for(int i = 0; i < STREAM_SIZE; i++) { // считаем кол-во токенов
		if(stream[i] != '\0')              //
			token_quantity++;              //
		else                               //
			break;                         //
	}                                      //

	while(token = stream[index_stream++]) {
		if(IsDigit(token)) {
			number1 = token - '0';
			while()
		}
	}






}