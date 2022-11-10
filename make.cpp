#include "Header.h"
#include <iostream>
#include <cstring>

int main(int argc, char ** argv) {
	if ((strcmp(argv[1], "--reverse") == 0 && strcmp(argv[2], "--file") == 0) || (strcmp(argv[2], "--reverse") == 0 && strcmp(argv[1], "--file") == 0)) Reverse1();
	else if (strcmp(argv[1], "--reverse") == 0) Reverse();
	if ((strcmp(argv[1], "--forward") == 0 && strcmp(argv[2], "--file") == 0) || (strcmp(argv[2], "--forward") == 0 && strcmp(argv[1], "--file") == 0)) Forward1();
	else if (strcmp(argv[1], "--forward") == 0) Forward();
	if ((strcmp(argv[1], "--reverse") != 0 && strcmp(argv[2], "--reverse") != 0 ) && (strcmp(argv[2], "--forward") != 0 && strcmp(argv[1], "--forward") != 0))
		std::cout << "Error"<< std::endl;
	return 0;
}