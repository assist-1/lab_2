#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "func.h"

void printHelloWorld() {
	std::cout << "Hello, world!" << std::endl;
}

int main(int argc, char** argv) {
	bool cnslEntr = true;
	bool PolishNotation = false;
	for (int i=0;i<argc;i++){
		if (strcmp("--file",argv[i])==0) cnslEntr=false;
		if (strcmp("--reverse",argv[i])==0) PolishNotation=true; 
	}
	std::string input;
	std::vector<std::string> text;
	if (cnslEntr){
		input = consoleEnter();
	}
	else {
		input = fileEnter();
	}
	convertToStrArray(text,input);
	std::vector<std::string>  temp;
	if (!PolishNotation){
		convertToPolishNotation(text,temp);
		calcPolishNotation(temp);
	}
	else {
		calcPolishNotation(text);
	}
	return 0;
}
