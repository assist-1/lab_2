#include <iostream>
#include <fstream>
#include <cstring>
#include "Lab2.h"
int flag_file;
int main(int argc, char* argv[])
{
    char s[40];
    float answer = -1000000000;
    if (argc == 3) {
        if (!strcmp(argv[1], "--file") && !strcmp(argv[2], "--forward") || !strcmp(argv[1], "--forward") && !strcmp(argv[2], "--file")) {
            flag_file = 1;
            answer = pr();
        }
        else if (!strcmp(argv[1], "--file") && !strcmp(argv[2], "--reverse") || !strcmp(argv[1], "--reverse") && !strcmp(argv[2], "--file")) {
            flag_file = 1;
            answer = OPN();;
        }
        else {
            std::cout << "ERROR! Flag is not correct" << std::endl;
        }
    }
    else if (argc == 2) {
        if (!strcmp(argv[1], "--forward")) {
            std::cout << "ВВЕДИТЕ ВЫРАЖЕНИЕ С ПРОБЕЛАМИ И ПОСТАВЬТЕ В КОНЦЕ ВЫРАЖЕНИЯ \'=\'" << std::endl;
            answer = pr();
        }
        else if (!strcmp(argv[1], "--reverse")) {
            std::cout << "ВВЕДИТЕ ВЫРАЖЕНИЕ С ПРОБЕЛАМИ В ОБРАТНОЙ ПОЛЬСКОЙ НОТАЦИИ И ПОСТАВЬТЕ В КОНЦЕ ВЫРАЖЕНИЯ \'=\'" << std::endl;
            answer = OPN();
        }
        else {
            std::cout << "ERROR! Flag is not correct" << std::endl;
        }
    }
    else {
        std::cout << "ERROR! Too many flags or not enough" << std::endl;
    }
    if (answer > -1000000000) { std::cout << answer << std::endl; }
    return 0;
}
