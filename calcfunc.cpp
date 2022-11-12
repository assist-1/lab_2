#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

const int STREAM_SIZE     = 64; // размер массива элементов потока
const int NUMBERS_SIZE    = 64; // размер массива с числами
const int OPERATIONS_SIZE = 64; // размер массива с операциями
const char * notations[2] = {"--forward", "--reverse"};

char   stream[STREAM_SIZE];
double numbers[NUMBERS_SIZE];
char   operations[OPERATIONS_SIZE];
int    index_stream     = 0;
int    index_numbers    = 0;
int    index_operations = 0;
double number1, number2;
char   token;
char   operation;

void Help() {
	std::cout << "\n";
	std::cout << "################################_INSTRUCTION_###############################" << std::endl;
	std::cout << "You need to enter: ./'program_name' [1] [2] [3]"                              << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "[1] flags about notation (necessarily): '--forward' '--reverse' '--help'"     << std::endl;
	std::cout << "[2] flag about reading (not necessarily): '--file' (from console by default)" << std::endl;
	std::cout << "[3] file name (if entered --file)"                                            << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "############################################################################" << std::endl;
	std::cout << "\n\n";
}

int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9')
		return 1;
	return 0;
}

int IsOperation(char symbol) {
	if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
		return 1;
	return 0;
}

int GetPriority(char operation) {
	switch(operation) {
		case '^': return 3;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
		default:  return 0;
	}
}

double Calculate(double x, char operation, double y) {
	switch(operation) {
		case '^': return pow(x, y);
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/':
			if(y == 0) {
				std::cerr << "Error: division by zero is not allowed" << std::endl;
				exit(1);
			} 
			return x / y;
		default:  return 0;
	}
}

void ReadingFromConsole() {
	std::cin.getline(stream, STREAM_SIZE - 1);
}

int NoSpace() {
	while(!IsDigit(stream[index_stream]) && !IsOperation(stream[index_stream])) {
		if(int(stream[index_stream]) == 32)
			index_stream++;
		if(int(stream[index_stream]) == 0)
			return 1;
	}
	return 0;
}

void InfNotation() {
	while(token = stream[index_stream++]) {

		if(IsDigit(token)) {    
			number1 = token - '0'; 
			while(IsDigit(stream[index_stream])) {
				token = stream[index_stream++];
				number1 = number1 * 10 + (token - '0');
			}
			numbers[index_numbers++] = number1;
		}

		else if(IsOperation(token)) {
			while(index_operations != 0 && GetPriority(token) <= GetPriority(operations[index_operations - 1])) {
				operation = operations[--index_operations];
				number1 = numbers[--index_numbers];
				number2 = numbers[--index_numbers];
				numbers[index_numbers++] = Calculate(number2, operation, number1);
			}
			operations[index_operations++] = token;
		}
		
		else if(token == '(')
			operations[index_operations++] = token;
		
		else if(token == ')') {
			while(operations[index_operations - 1] != '(') {
				operation = operations[--index_operations];
				number1 = numbers[--index_numbers];
				number2 = numbers[--index_numbers];
				numbers[index_numbers++] = Calculate(number2, operation, number1);
			}
			index_operations--;
		}
	}
	while(index_operations != 0) {
		operation = operations[--index_operations];
		number1 = numbers[--index_numbers];
		number2 = numbers[--index_numbers];
		numbers[index_numbers++] = Calculate(number2, operation, number1);
	}
	std::cout << "Result: " << numbers[--index_numbers] << std::endl;
}

void PolNotation() {
	while(token = stream[index_stream++]) {
		if(IsDigit(token)) {    
			number1 = token - '0'; 
			while(IsDigit(stream[index_stream])) {
				token = stream[index_stream++];
				number1 = number1 * 10 + (token - '0');
			}
			numbers[index_numbers++] = number1;
			NoSpace();
		}
		else if(IsOperation(token)) {
			number1 = numbers[--index_numbers];
			number2 = numbers[--index_numbers];
			numbers[index_numbers++] = Calculate(number2, token, number1);
			NoSpace();
		}
		if(NoSpace())
			break;
	}
	std::cout << "Result: " << numbers[--index_numbers] << std::endl;
}

void ReadingFromFile(char *namefile, char *flag) {
	std::ifstream in(namefile);
	if(in.is_open()) {
		int i = 1;
		while(in.getline(stream, STREAM_SIZE - 1)) {
			std::cout << i << ") ";
			if(!(strcmp(flag, notations[0])))
				InfNotation();
			else
				PolNotation();
			i++;
		}
	}
	else {
		std::cerr << "###_ERROR: file couldn't be opened_###" << std::endl;
		exit(1);
	}
}