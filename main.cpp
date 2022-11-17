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

    //обработка выражения
    double *stack_nums = new double[200];
    char *stack_signs = new char[200];
    int nums_count=0, signs_count=0;
    if(notation == 1){
        //проверка правильности математического выражения
//        std::cout << check_forward(str, str_len) << std::endl;
        if(check_forward(str, str_len)){
            int d_begin=-1, d_end=-1;
            for(int i = 0; i < str_len; ++i){
                if(str[i] >= '0' && str[i] <='9' || str[i] == '.') {
                    if (d_begin == -1) {
                        d_begin = i;
                    }
                }
                else{
                    if(d_begin != -1){
                            d_end = i - 1;
                            char *new_double = new char[d_end - d_begin + 1];
                            for(int j=0; j <= d_end - d_begin; ++j){
                                new_double[j] = str[d_begin + j];
                            }
                            stack_nums[nums_count] = make_double(new_double, d_end - d_begin + 1);
                            ++nums_count;
                            delete []new_double;
                            d_begin = -1; d_end = -1;
                    }
                    else {
                        if(str[i] == '+' || str[i] == '-') {
                            if (i - 1 >= 0 && !(str[i] >= '0' && str[i] <= '9')) {
                                d_begin = i;
                            } else {
                                stack_signs[signs_count] = str[i];
                            }
                        }
                        else if(str[i] != ' '){
                            stack_signs[signs_count] = str[i];
                        }
                    }
                }
            }
        } else{
            std::cerr << "Your expression is wrong.";
        }


    } else if(notation == 2){
        int i = 2;
        std::cout << "Type an expression in RPN." << std::endl;
    }

    return 0;
}
