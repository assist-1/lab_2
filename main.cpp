#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "calcfunc.h"
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char ** argv) {
	const char * flags[4] = {"--forward", "--reverse", "--help", "--file"};

	if(argc == 1) {
		cerr << "Error: flag not found" << endl;
		Help();
		exit(1);
	}
	else if(argc == 2) {
		if(!(strcmp(argv[1], flags[0]))) {
			cout << "Please enter your task in Infix Notation:" << endl;
			ReadFromConsole();
			InfNotation();
		}
		else if(!(strcmp(argv[1], flags[1]))) {
			cout << "Please enter your task in Polish Notation:" << endl;
			ReadFromConsole();
			//PolNotation();
		}
		else if(!(strcmp(argv[1], flags[2])))
			Help();
		else {
			cerr << "Error: flag entered incorrectly" << endl;
			Help();
			exit(1);
		}
	}
	else if(argc == 4) {
		if(!(strcmp(argv[2], flags[3]))) {
			char *namefile = argv[3];
			if(ReadFromFile(namefile)) {
				if(!(argv[1], flags[0])) {
					InfNotation();
				}
				else if(!(strcmp(argv[1], flags[1]))) {
					//PolNotation();
				}
			}
		}
		else {
			cerr << "Error: flag entered incorrectly" << endl;
			Help();
			exit(1);
		}
	}
	else {
		cerr << "Error: flag entered incorrectly" << endl;
		Help();
		exit(1);
	}

}