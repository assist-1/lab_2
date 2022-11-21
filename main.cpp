#include <iostream>
#include <cstring>
#include <fstream>
#include "calc_lib.h"

int main(int argc, char **argv) {
    int notation=0, read_file=0;

    // обработка всех аргументов
    if(argc == 1) {
        std::cerr << "Not enough arguments." << std::endl
                  << "Use --forward to calculate or --reverse to calculate in RPN." << std::endl
                  << "To read the expression from file use --file and type the filename" << std::endl;
        return 1;
    } else{
        if(strcmp(argv[1], "--forward") == 0) {
            notation = 1;
        } else if(strcmp(argv[1], "--reverse") == 0) {
            notation = 2;
        } else{
            std::cerr << "Unexpected argument." << std::endl;
            return 1;
        }

        if(argc == 3){
            if(strcmp(argv[2], "--file") == 0){
                read_file = 1;
            } else{
                std::cerr << "Unexpected argument." << std::endl;
                return 1;
            }
        } else if(argc > 3){
            std::cerr << "Too many arguments." << std::endl;
            return 1;
        }
    }

    // считывания выражения
    char *str = new char[200];
    int str_len = 0;
    if(read_file){
        std::ifstream file_in("input.txt");
        noskipws(file_in);
        while(file_in >> str[str_len]){
            if(file_in.peek() == ' ' && str[str_len] == ' '){
                continue;
            }
            ++str_len;
            if(file_in.peek() == '\n') break;
        }
    } else{
        noskipws(std::cin);
        while(std::cin >> str[str_len]) {
            if(std::cin.peek() == ' ' && str[str_len] == ' '){
                continue;
            }
            ++str_len;
            if(std::cin.peek() == '\n') break;
        }
    }

    //обработка прямой нотации
    if(notation == 1){
        //проверка правильности математического выражения
        if(check_forward(str, str_len)){
           std::cout << "Your expression is right.\n";
        } else{
            std::cerr << "Your expression is wrong.\n";
        }

    //обработка польской нотации
    } else if(notation == 2){
        if(check_reverse(str, str_len)){
            std::cout << calculate_reverse(str, str_len);
        }
        else{
            std::cerr << "Your expression is wrong.\n";
        }
    }
    return 0;
}