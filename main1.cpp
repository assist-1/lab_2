#include <iostream>
#include <fstream>

#include "function.h"
std::string str;

int main(int argc, char *argv[]){
    double intermediate;
    for(int i = 0; i < 200; i++) {val[i] = 0; Sign[i] = '0'; hooks[i] = 0;}
    char token[200];
    if (argc == 1) {
        std::cerr << "Enter flag --reverse or --forward " << std::endl;
        goto stop;
    }
    else if (argc >= 2 && std::string(argv[1]) == "--forward") {
        if(argc == 2) {
            std::cout
                    << "Enter an expression, note that all numbers and characters must be entered separated by commas. For example: 2 + ( 2 * 2 )"
                    << std::endl;
            std::cin.getline(str1, 200, '\n');
            Help(0);
        } else if (std::string(argv[2]) == "--file"){
            if(argc != 4) {
                std::cerr << "wrong number of arguments" << std::endl;
                goto stop;
            }
            else {
                std::ifstream file (argv[3]);
                file.getline(str1,200, '\n');
                Help(0);
            }
        }
        int i, j;
        for (i = 0; str[i] != 0; i++) {
            for (j = 0; str[i] != ' ' && str[i] != 0; j++, i++) {
                token[j] = str[i];
            }
            if (PrSigns(str[i - 1]) != 0 && countVal == 0){
                std::cerr << "Wrong expression4" << std::endl;
                goto stop;
            }
            if (str[i - 1] == '(') {
                if (countVal != countSign) {
                    std::cerr << "Wrong expression5" << std::endl;
                    goto stop;
                }
                hooks[countHooks1] = countVal;
                countHooks1++;
            }
            if (str[i - 1] == ')') {
                if (countVal - 1 != countSign) {
                    std::cerr << "Wrong expression6" << std::endl;
                    flag = 1;
                }
                endHooks(hooks[countHooks1 - countHooks2 - 1]);
                countHooks2++;
            }
            if (PrSigns(str[i - 1]) != 0 && str[i - 2] == ' ') {
                if (countVal - 1 != countSign) {
                    std::cerr << "wrong number of characters" << std::endl;
                    goto stop;
                }
                if (countVal - 2 >= hooks[countHooks1 - 1] || countHooks1 == countHooks2) {
                    CompareSign(Sign[countSign - 1], str[i - 1]);
                }
                if(countVal == 0){
                    std::cerr << "Wrong expression7" << std::endl;
                    flag = 1;
                }
                Sign[countSign] = str[i - 1];
                countSign++;

            }
            token[j] = '\0';
            intermediate = atof(token);
            if ((token[j - 1] == '0' && token[j - 2] == ' ') || (j == 1 && token[j - 1] == '0')) {
                val[countVal] = 0;
                countVal++;
            }
            if ((intermediate != 0 && Pr(token, j))) {
                val[countVal] = intermediate;
                countVal++;
            }
            if (flag == 1)
                goto stop;
            if (!str[i]) break;
        }
        if (countVal - 1 != countSign) {
            std::cerr << "Wrong expression8" << std::endl;
            goto stop;
        }
        FinishStep();
        if (countHooks1 != countHooks2) {
            std::cerr << "wrong number of hooks";
        } else if (flag == 0)
            std::cout << "Result: " << val[0] << std::endl;
        stop:
        return 0;
    } else if (argc >= 2 && std::string(argv[1]) == "--reverse"){
        if(argc == 2) {

            std::cout
                    << "Enter an expression, note that all numbers and characters must be entered separated by commas. For example: 2 2 2 + *"
                    << std::endl;
            std::cin.getline(str1, 200, '\n');
            Help(1);
        } else if (std::string(argv[2]) == "--file"){
            if(argc != 4) {
                std::cerr << "wrong number of arguments" << std::endl;
                goto stop;
            }
            else {
                std::ifstream file (argv[3]);
                file.getline(str1,200, '\n');
                Help(1);
            }
        }
        int i, j;
        for (i = 0;; i++) {
            for (j = 0; str[i] != ' ' && str[i]; j++, i++) {
                token[j] = str[i];
            }
            if (PrSigns(str[i - 1]) != 0 && countVal == 0){
                std::cerr << "Wrong expression9" << std::endl;
                goto stop1;
            }
            if (PrSigns(str[i - 1]) != 0 && str[i - 2] == ' ') {
                if(countVal == 0){
                    std::cerr << "Wrong expression10" << std::endl;
                    flag = 1;
                }
                Sign[countSign] = str[i - 1];
                countSign++;
            }
            token[j] = '\0';
            intermediate = atof(token);
            if ((token[j - 1] == '0' && token[j - 2] == ' ') || (j == 1 && token[j - 1] == '0')) {
                StepReverse(countSign);
                val[countVal] = 0;
                countVal++;
            }
            if ((intermediate != 0 && Pr(token, j))) {
                StepReverse(countSign);
                val[countVal] = intermediate;
                countVal++;
            }
            if (flag == 1)
                goto stop;
            if (!str[i]) break;
        }
        StepReverse(countSign);
        if (countVal - 1 != countSign) {
            std::cerr << "Wrong expression8" << std::endl;
            goto stop1;
        }
        if (flag == 0)
            std::cout << "Result: " << val[0] << std::endl;
        stop1:
        return 0;
    } else
        std::cerr << "Enter flag --reverse or --forward " << std::endl;
    return 0;
}