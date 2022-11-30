#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "calcfunc.h"

int main(int argc, char ** argv) {
	const char * flags[5] = {"--forward", "--reverse", "--console", "--file", "--help"};

	if(argc == 1) {
		std::cerr << "###_ERROR: flag not found_###"                                              << std::endl;
		std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
		exit(1);
	}
	else if(argc == 2) {
		if(!(strcmp(argv[1], flags[4]))) {
			Help();
		}
		else if(!(strcmp(argv[1], flags[0])) || !(strcmp(argv[1], flags[1]))) {
			std::cerr << "###_ERROR: flag about reading not entered_###"                              << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
		else {
			std::cerr << "###_ERROR: flag entered incorrectly_###"                                    << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
	}
	else if(argc == 3) {
		if(!(strcmp(argv[2], flags[2]))) {
			if(!(strcmp(argv[1], flags[0]))) {
				std::cout << "Please enter your task in Infix Notation:" << std::endl;
				ReadingFromConsole();
				InfNotation();
			}
			else if(!(strcmp(argv[1], flags[1]))) {
				std::cout << "Please enter your task in Polish Notation:" << std::endl;
				ReadingFromConsole();
				PolNotation();
			}
			else {
				std::cerr << "###_ERROR: flag entered incorrectly_###"                                    << std::endl;
				std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
				exit(1);
			}
		}
		else if(!(strcmp(argv[2], flags[3]))) {
			std::cerr << "###_ERROR: file name not entered_###"                                       << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
		else {
			std::cerr << "###_ERROR: flag entered incorrectly_###"                                    << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
	}
	else if(argc == 4) {
		if(!(strcmp(argv[2], flags[3]))) {
			char *namefile = argv[3];
			char *flag = argv[1];
			if(!(strcmp(argv[1], flags[0])) || !(strcmp(argv[1], flags[1])))
				ReadingFromFile(namefile, flag);
			else {
				std::cerr << "###_ERROR: flag entered incorrectly_###"                                    << std::endl;
				std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
				exit(1);
			}
		}
		else {
			std::cerr << "###_ERROR: flag entered incorrectly_###"                                    << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "###_ERROR: flag entered incorrectly_###"                                    << std::endl;
		std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
		exit(1);
	}
}