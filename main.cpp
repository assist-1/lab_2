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
		cerr << "###_ERROR: flag not found_###" << endl;
		Help();
		exit(1);
	}
	else if(argc == 2) {
		if(!(strcmp(argv[1], flags[0]))) {
			cout << "Please enter your task in Infix Notation:" << endl;
			ReadingFromConsole();
			InfNotation();
		}
		else if(!(strcmp(argv[1], flags[1]))) {
			cout << "Please enter your task in Polish Notation:" << endl;
			ReadingFromConsole();
			PolNotation();
		}
		else if(!(strcmp(argv[1], flags[2])))
			Help();
		else {
			cerr << "###_ERROR: flag entered incorrectly_###" << endl;
			Help();
			exit(1);
		}
	}
	else if(argc == 4) {
		if(!(strcmp(argv[2], flags[2]))) {

			char *namefile = argv[3];
			if(ReadingFromFile(namefile)) {
				if(!(argv[1], flags[0])) {
					InfNotation();
				}
				else if(!(strcmp(argv[1], flags[1]))) {
					PolNotation();
				}
			}
		}
		else {
			cerr << "###_ERROR: flag entered incorrectly_###" << endl;
			Help();
			exit(1);
		}
	}
	else {
		cerr << "###_ERROR: flag entered incorrectly_###" << endl;
		Help();
		exit(1);
	}
}