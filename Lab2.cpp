#include <iostream>
#include <fstream>
#include "Lab2.h"
int flag_file;
int main()
{
    char s[40];
    float answer = -1000000000;
    std::cout << "ЕСЛИ ХОТИТЕ СЧИТАТЬ ИЗ ФАЙЛА, ВВЕДИТЕ \"--file\", В ПРОТИВНОМ СЛУЧАЕ \"no\"" << std::endl;
    std::cin >> s;
    if (s[0] == 'n' && s[1] == 'o' && s[2] == '\0') {
        flag_file = 0;
        std::cout << "ВВЕДИТЕ ФЛАГ" << std::endl;
        std::cin >> s;
        if (s[0] == '-' && s[1] == '-' && s[2] == 'r' && s[3] == 'e' && s[4] == 'v' && s[5] == 'e' && s[6] == 'r' && s[7] == 's' && s[8] == 'e' && s[9] == '\0') {
            std::cout << "ВВЕДИТЕ ВЫРАЖЕНИЕ С ПРОБЕЛАМИ В ОБРАТНОЙ ПОЛЬСКОЙ НОТАЦИИ И ПОСТАВЬТЕ В КОНЦЕ ВЫРАЖЕНИЯ \'=\'" << std::endl;
            answer = OPN();
        }
        else if (s[0] == '-' && s[1] == '-' && s[2] == 'f' && s[3] == 'o' && s[4] == 'r' && s[5] == 'w' && s[6] == 'a' && s[7] == 'r' && s[8] == 'd' && s[9] == '\0') {
            std::cout << "ВВЕДИТЕ ВЫРАЖЕНИЕ С ПРОБЕЛАМИ И ПОСТАВЬТЕ В КОНЦЕ ВЫРАЖЕНИЯ \'=\'" << std::endl;
            answer = pr();
        }
        else {
            std::cout << "ERROR! Flag is not correct" << std::endl;
        }
    }
    else if (s[0] == '-' && s[1] == '-' && s[2] == 'f' && s[3] == 'i' && s[4] == 'l' && s[5] == 'e' && s[6] == '\0') {
        flag_file = 1;
        std::ifstream file;
        file.open("flag.txt");
        file >> s;
        if (s[0] == '-' && s[1] == '-' && s[2] == 'r' && s[3] == 'e' && s[4] == 'v' && s[5] == 'e' && s[6] == 'r' && s[7] == 's' && s[8] == 'e'/* && s[9] == '\0'*/) {
            answer = OPN();
        }
        else if (s[0] == '-' && s[1] == '-' && s[2] == 'f' && s[3] == 'o' && s[4] == 'r' && s[5] == 'w' && s[6] == 'a' && s[7] == 'r' && s[8] == 'd'/* && s[9] == '\0'*/) {
            answer = pr();
        }
        else {
            std::cout << "ERROR! Flag is not correct" << std::endl;
        }
        file.close();

    }
    else {
        std::cout << "ERROR! Flag is not correct" << std::endl;

    }
    if (answer > -1000000000) { std::cout << answer << std::endl; }
    return 0;
}