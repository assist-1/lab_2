#include <iostream>

using std::cout;
using std::endl;																	// ./a.out   --flag --file name
using std::cerr;																		  0          1     2     3

int main(int argc, char ** argv) {
	if(argc == 1) {
		cerr << "Error: flag not found" << endl;
	}
	else if(argc == 2) {
		if(argv[1] == "--forward") {
			cout << "Please enter your task in Infix Notation:" << endl;
			ReadFromConsole();
			InfNotation();
		}
		else if(argv[1] == "--reverse") {
			cout << "Please enter your task in Polish Notation:" << endl;
			ReadFromConsole();
			//PolishNotation();
		}
		else
			cout << "Error: flag entered incorrectly" << endl;
	}
	else if(argc == 4) {
		if(argv[2] == "--file") {
			char *namefile = argv[3];
		}
		if Read
	}
}