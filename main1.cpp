#include <iostream>
#include <fstream>

#include "function.h"

int main(int argc, char *argv[]){
    double intermediate;
    for(int i = 0; i < 200; i++) {val[i] = 0; Sign[i] = '0'; hooks[i] = 0;}
    char str[200];
    char token[200];
    if (argc == 1) {
        std::cerr << "Enter flag " << std::endl;
        goto stop;
    }
    else if (argc >= 2 && std::string(argv[1]) == "--forward") {
        if(argc == 2) {

            std::cout
                    << "Enter an expression, note that all numbers and characters must be entered separated by commas. For example: 2 + ( 2 * 2 )"
                    << std::endl;
            std::cin.getline(str, 200, '\n');
        } else if (std::string(argv[2]) == "--file"){
            if(argc != 4) {
                std::cerr << "wrong number of arguments" << std::endl;
                goto stop;
            }
            else {
                std::ifstream file (argv[3]);
                file.getline(str,200, '\n');
            }
        }
        int i, j;
        for (i = 0;; i++) {
            for (j = 0; str[i] != ' ' && str[i]; j++, i++) {
                token[j] = str[i];
            }
            if (PrSigns(str[i - 1]) != 0 && countVal == 0){
                std::cerr << "Wrong expression" << std::endl;
                goto stop;
            }
            if (str[i - 1] == '(') {
                if (countVal != countSign) {
                    std::cerr << "Wrong expression" << std::endl;
                    goto stop;
                    flag = 1;
                }
                hooks[countHooks1] = countVal;
//                std::cout << countVal << " 4345" << std::endl;
                countHooks1++;
            }
            if (str[i - 1] == ')') {
                if (countVal - 1 != countSign) {
                    std::cerr << "Wrong expression" << std::endl;
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
//                    std::cout << hooks[countHooks1] << " " << countVal << " we ";

                }
                if(countVal == 0){
                    std::cerr << "Wrong expression" << std::endl;
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
//            for (int k = 0; k < 7; k++) {
//                std::cout << val[k] << " ^ " << Sign[k] << std::endl;
//            }
        }
        std::cout << std::endl;

        if (countVal - 1 != countSign) {
            std::cerr << "Wrong expression" << std::endl;
            goto stop;
        }
//    std::cout << counter << std::endl;
//        for (int k = 0; k < 10; k++) {
//            std::cout << val[k] << " " << Sign[k] << std::endl;
//        }
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
            std::cin.getline(str, 200, '\n');
        } else if (std::string(argv[2]) == "--file"){
            if(argc != 4) {
                std::cerr << "wrong number of arguments" << std::endl;
                goto stop;
            }
            else {
                std::ifstream file (argv[3]);
                file.getline(str,200, '\n');
            }
        }
        int i, j;
        for (i = 0;; i++) {
            for (j = 0; str[i] != ' ' && str[i]; j++, i++) {
                token[j] = str[i];
            }
            if (PrSigns(str[i - 1]) != 0 && countVal == 0){
                std::cerr << "Wrong expression" << std::endl;
                goto stop1;
            }
            if (PrSigns(str[i - 1]) != 0 && str[i - 2] == ' ') {
                if(countVal == 0){
                    std::cerr << "Wrong expression" << std::endl;
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
//            for (int k = 0; k < 7; k++) {
//                std::cout << val[k] << " ^ " << Sign[k] << std::endl;
//            }
        }
//        for (int k = 0; k < 10; k++) {
//            std::cout << val[k] << " " << Sign[k] << std::endl;
//        }
        StepReverse(countSign);
        if (flag == 0)
            std::cout << "Result: " << val[0] << std::endl;
        stop1:
        return 0;
    }
}