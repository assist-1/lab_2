#include <iostream>
#include <fstream>

#include "function.h"
std::string str;

int main(int argc, char *argv[]){
    double intermediate;
    for(int i = 0; i < 200; i++) {val[i] = 0; Sign[i] = '0'; hooks[i] = 200;}
    char token[200];
    if (argc == 1) { //проверка на существование флагов
        std::cerr << "Enter flag --reverse or --forward " << std::endl;
        goto stop;
    }
    else if (argc >= 2 && std::string(argv[1]) == "--forward") { //если флаг --forward
        if(argc == 2) { //ввод со строки
            std::cout
                    << "Enter an expression. For example: 2+(2*2)"
                    << std::endl;
            std::cin.getline(str2, 200, '\n');
            Help(0);
        } else if (std::string(argv[2]) == "--file"){ //ввод из файла
            if(argc != 4) {
                std::cerr << "wrong number of arguments" << std::endl;
                goto stop;
            }
            else {
                std::ifstream file (argv[3]);
                file.getline(str2,200, '\n');
                Help(0);
            }
        }
        int i, j;
        for (i = 0; str[i] != 0; i++) {
            for (j = 0; str[i] != ' ' && str[i] != 0; j++, i++) {
                token[j] = str[i];
            } //каждый раз заносим в массив token отдельные токены
            if (PrSigns(str[i - 1]) != 0 && countVal == 0){
                std::cerr << "Wrong expression4" << std::endl;
                goto stop;
            }
            if (str[i - 1] == '(') { //считываем открывающиеся скобки и заносим в массив hooks число символов, которое было при открытии
                if (countVal != countSign) {
                    std::cerr << "Wrong expression5" << std::endl;
                    goto stop;
                }
                hooks[countHooks1] = countVal;
                currentCountHooks1 = countVal;
                countHooks1++;
            }
            if (str[i - 1] == ')') { //считываем закрывающиеся скобки и вызываем функцию endHooks
                if (countVal - 1 != countSign) {
                    std::cerr << "Wrong expression6" << std::endl;
                    flag = 1;
                }
                for(int g=199;g>=0;g--){
                    if(hooks[g] != 200) {
                        currentCountHooks1 = hooks[g];
                        hooks[g] = 200;
                        break;
                    }
                }
                endHooks(currentCountHooks1);
                countHooks2++;
                for(int g=199;g>=0;g--){
                    if(hooks[g] != 200) {
                        currentCountHooks1 = hooks[g];
                        hooks[g] = 200;
                        break;
                    } else
                        currentCountHooks1=0;
                }
            }
            if (PrSigns(str[i - 1]) != 0 && str[i - 2] == ' ') { //считываем знак, сравниваем знак текущий и предыдущий, и в конце заносим новый знак в массив Sign
                if (countVal - 1 != countSign) {
                    std::cerr << "wrong number of characters" << std::endl;
                    goto stop;
                }
                if (countVal - 2 >= currentCountHooks1) {
                    CompareSign(Sign[countSign - 1], str[i - 1]);
                }
                if(countVal == 0){
                    std::cerr << "Wrong expression7" << std::endl;
                    flag = 1;
                }
                Sign[countSign] = str[i - 1];
                countSign++;

            }
            token[j] = '\0'; //ставим завершающий знак
            intermediate = atof(token); //функцией atof преобразуем массив char в int
            if ((token[j - 1] == '0' && token[j - 2] == ' ') || (j == 1 && token[j - 1] == '0')) { //отдельно разбираем случай с 0, так как при ошибки считывания atof возвращает 0
                val[countVal] = 0;
                countVal++;
            }
            if ((intermediate != 0 && Pr(token, j))) { //заносим в массив val
                val[countVal] = intermediate;
                countVal++;
            }
            if (flag == 1)
                goto stop;
            if (!str[i]) break;

        }
        if (countVal - 1 != countSign) { //проверка на правильность выражения
            std::cerr << "Wrong expression8" << std::endl;
               goto stop;
        }
        FinishStep();
        if (countHooks1 != countHooks2) { //проверка на правильность количества скобочек
            std::cerr << "wrong number of hooks";
        } else if (flag == 0)
            std::cout << "Result: " << val[0] << std::endl;
        stop:
        return 0;
    } else if (argc >= 2 && std::string(argv[1]) == "--reverse"){ //Обратно польская нотация
        if(argc == 2) { //считываем со строчки
            std::cout
                    << "Enter an expression. For example: 2 2 2 + *"
                    << std::endl;
            std::cin.getline(str2, 200, '\n');
            Help(1);
        } else if (std::string(argv[2]) == "--file"){ //считываем из файла
            if(argc != 4) {
                std::cerr << "wrong number of arguments" << std::endl;
                goto stop;
            }
            else {
                std::ifstream file (argv[3]);
                file.getline(str2,200, '\n');
                Help(1);
            }
        } else{
            std::cerr << "Enter flag --reverse or --forward " << std::endl;
            goto stop1;
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
                    goto stop1;
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