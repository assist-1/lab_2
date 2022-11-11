#include <iostream>

int STREAM_SIZE     = 256; // размер стека элементов потока
int NUMBERS_SIZE    = 256; // размер стека с числами
int OPERATIONS_SIZE = 256; // размер стека с операциями

char stream[STREAM_SIZE];

void Help() {
	std::cout << "-----------------------------------INSTRUCTION------------------------------" << std::endl;
	std::cout << "You need to enter: ./'prog_name' [1] [2] [3]"                                 << std::endl;
	std::cout << "[1] flags about notation (necessarily): '--forward' '--reverse' "             << std::endl;
	std::cout << "[2] flag about reading (not necessarily): '--file' (from console by default)" << std::endl;
	std::cout << "[3] file name (if entered --file)"                                            << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\n\n";
}

int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9')
		return 1;
	return 0;
}

int IsOperation(char symbol) {
	if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	return 0;
}

int GetPriority(char operation) {
	switch(operation) {
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
		default:  return 0;
	}
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

void ReadingFromConsole() {
	std::cin >> stream;
	int token_quantity = 0;
	for(int i = 0; i < STREAM_SIZE; i++) {
		if(stream[i] != '\0')
			token_quantity++;
		else
			break;
	}
	stream[token_quantity] = '\0';
}

void ReadingFromFile() {
	std::fstream file;
	char symbol;
	int i = 0;
	while(file >> symbol) {
		stream[i] = symbol;
		i++;
	}
	file.close();
}


double InfNotation() {
	double numbers[NUMBERS_SIZE];
	char   operations[OPERATIONS_SIZE];
	int    index_stream     = 0;
	int    index_numbers    = 0;
	int    index_operations = 0;
	int    number1, number2;
	
	std::cin >> stream;

	char token = stream[0];
	for(int i = 0; i < STREAM_SIZE; i++) { // 
		if(stream[i] != '\0')              //
			token_quantity++;              // считаем кол-во токенов
		else                               //
			break;                         //
	}                                      //

	while(token = stream[index_stream++]) { // считываем токен с потока
		if(IsDigit(token)) {        // если токен - цифра,
			number1 = token - '0';  // то берем ее как число
			while(IsDigit(stream[index_stream++])) {     // проверям, есть ли дальше цифры,
				number1 = number1 * 10 + (token - '0');  // если есть, значит число двух и более значное, добавляем следующую цифру в свой разряд
			}
			numbers[index_numbers++] = number1; // получившееся число помещаем в "стек" чисел
		}

		else if(IsOperation(token)) {
			while(index_operations != 0 && GetPriority(token) <= GetPriority(operations[index_operations--])) {
				operation = operations[index_operations];
				number1 = numbers[index_numbers--];
				number2 = numbers[index_numbers];
				numbers[index_numbers++] = Calculate(number1, operation, number2);
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
				numbers[index_numbers++] = Calculate(number1, operation, number2);
			}
			index_operations--;
		}

		while(index_operations != 0) {
			operation = operations[--index_operations];
			number1 = numbers[--index_numbers];
			number2 = numbers[--index_numbers];
			numbers[index_numbers++] = Calculate(number1, operation, number2);
		}
		index_numbers--;
		
		return numbers[index_numbers];
	}
}

double PolNotation() {
	
}