#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "calcfunc.h"

int main(int argc, char ** argv) {
	const char * flags[5] = {"--forward", "--reverse", "--console", "--file", "--help"};

	if(argc == 1) {  // Если введено только название файла
		std::cerr << "###_ERROR: flag not found_###" << std::endl;
		std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
		exit(1);
	}
	else if(argc == 2) { //Если введено название файла и один флаг, то это должен быть --help
		if(!(strcmp(argv[1], flags[4]))) { //Если --help, то заебись
			Help();
		}
		else if(!(strcmp(argv[1], flags[0])) || !(strcmp(argv[1], flags[1]))) {
			std::cerr << "###_ERROR: flag about reading not entered_###" 					          << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
		else { // Иначе ошибка в флаге или названии файла
			std::cerr << "###_ERROR: flag entered incorrectly_###" 					                  << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
	}
	else if(argc == 3) { // Если введено 2 флага, то это должна быть нотация и чтение с консоли
		if(!(strcmp(argv[2], flags[2]))) { // Если выбрано чтение с консоли, то проверяем нотацию
			if(!(strcmp(argv[1], flags[0]))) { // Если инфиксная, то ебашим инфиксную
				std::cout << "Please enter your task in Infix Notation:" << std::endl;
				ReadingFromConsole();
				InfNotation();
			}
			else if(!(strcmp(argv[1], flags[1]))) { //Иначе если польская, ебашим польскую
				std::cout << "Please enter your task in Polish Notation:" << std::endl;
				ReadingFromConsole();
				PolNotation();
			}
			else { //Иначе введен неправильно флаг или название файла
				std::cerr << "###_ERROR: flag entered incorrectly_###" 					                  << std::endl;
				std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
				exit(1);
			}
		}
		else if(!(strcmp(argv[2], flags[3]))) { //Если чел решил написать --file, то он забыл написать название файла, ругаем его за это
			std::cerr << "###_ERROR: file name not entered_###"                                       << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
		else { //Иначе чел опять неправильно что-то ввел
			std::cerr << "###_ERROR: flag entered incorrectly_###" 		                 			  << std::endl;
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
				std::cerr << "###_ERROR: flag entered incorrectly_###" 		                			  << std::endl;
				std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
				exit(1);
			}
		}
		else {
			std::cerr << "###_ERROR: flag entered incorrectly_###" 				                	  << std::endl;
			std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "###_ERROR: flag entered incorrectly_###" 					                  << std::endl;
		std::cerr << "###_You can entered '--help' after program name for instruction output_###" << std::endl;
		exit(1);
	}
}