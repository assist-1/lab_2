#include <iostream>

#include "function.h"

int flag = 0;
int countVal = 0;
int countSign = 0;
int countHooks1 = 0;
int countHooks2 = 0;
int currentCountHooks1;
double val[200];
char Sign[200];
char str1[200];
char str2[200];
int hooks [200];

int PrSigns (char b){ //проверка на символ
    if(b == '+' || b == '-')
        return 1;
    if(b == '*' || b == '/')
        return 2;
    else return 0;
}

bool Digit(char a) { //проверка на цифру
    if((( a >= '0' && a <= '9') || a == '.' || a == '-'))
        return true;
    return false;
}

bool Pr(char ar[200], int value){ //проверяет токен на число
    for(int i = 0; i < value;i++){
        if(!Digit(ar[i]))
            return false;
    }
    return true;
}
void CompareSign (char sign1, char sign2){ //реализация приоритетности знаков
    if(PrSigns(sign2) < PrSigns(sign1)){
        if (sign1 == '*' ){
            val[countVal - 2] = val[countVal - 2] * val[countVal - 1];
            countSign--; countVal--;
        }
        if (sign1 == '/'){
            if(val[countVal - 1] != 0){
                val[countVal - 2] = val[countVal - 2] / val[countVal - 1];
                countSign--; countVal--;
            }
            else{
                flag = 1;
                std::cerr << "Error! Can't divide by zero";
            }
        }
    }
    if(sign1 == '-' && sign2 == '+'){
        val[countVal - 2] = val[countVal - 2] - val[countVal - 1];
        countSign--; countVal--;

    }
}

void FinishStep(){ //финальный этап, когда мы считали всю строчку выполняем последние преобразования
    while (countVal != 1){
        int countS1=countSign, countV1=countVal;
        for(int v = 1; v <= countS1;v++) {
            if (Sign[countS1 - v] == '*') {
                val[countV1 - v - 1] = val[countV1 - v - 1] * val[countV1 - v];
                countSign--;
                countVal--;

            }
            if (Sign[countS1 - v] == '/') {
                if (val[countV1 - v] != 0) {
                    val[countV1 - v - 1] = val[countV1 - v - 1] / val[countV1 - v];
                    countSign--;
                    countVal--;
                } else {
                    flag = 1;
                    std::cerr << "Error! Can't divide by zero";
                    break;
                }
            }
        }
        if(Sign[countSign - 1] == '-'){
            if(Sign[countSign - 2] == '-'){
                val[countVal - 2] = - val[countVal - 2] - val[countVal - 1];
                Sign[countSign - 2] = '+';
                countSign--; countVal--;
            } else {
                val[countVal - 2] = val[countVal - 2] - val[countVal - 1];
                countSign--; countVal--;
            }
        } else if(Sign[countSign - 1] == '+'){
            if(Sign[countSign - 2] == '-'){
                val[countVal - 2] = - val[countVal - 2] + val[countVal - 1];
                Sign[countSign - 2] = '+';
                countSign--; countVal--;
            } else {
                val[countVal - 2] = val[countVal - 2] + val[countVal - 1];
                countSign--; countVal--;
            }
        }
    }
}

void endHooks(int end){ //если встречаем закрывающуюся скобочку, то считаем всё выражение в скобочках
    while (countVal - 2 >= end){
        if (Sign[countSign - 1] == '*') {
            val[countVal - 2] = val[countVal - 2] * val[countVal - 1];
            countSign--;
            countVal--;
        }else if (Sign[countSign - 1] == '/') {
            if (val[countVal - 1] != 0) {
                val[countVal - 2] = val[countVal - 2] / val[countVal - 1];
                countSign--;
                countVal--;
            } else {
                flag = 1;
                std::cerr << "Error! Can't divide by zero";
                break;
            }
        } else if(Sign[countSign - 1] == '-'){
            if(Sign[countSign - 2] == '-' && countSign - 2 >= end){
                val[countVal - 2] = - val[countVal - 2] - val[countVal - 1];
                Sign[countSign - 2] = '+';
                countSign--; countVal--;
            } else {
                val[countVal - 2] = val[countVal - 2] - val[countVal - 1];
                countSign--; countVal--;
            }
        } else if(Sign[countSign - 1] == '+'){
            if(Sign[countSign - 2] == '-' && countSign - 2 >= end){
                val[countVal - 2] = - val[countVal - 2] + val[countVal - 1];
                Sign[countSign - 2] = '+';
                countSign--; countVal--;
            } else {
                val[countVal - 2] = val[countVal - 2] + val[countVal - 1];
                countSign--; countVal--;
            }
        }
    }
}

void StepReverse(int End){ //выполняет преобразования для ОПН
    while (countSign > 0){
        if (Sign[End - countSign] == '*'){
            val[countVal - 2] = val[countVal - 2] * val[countVal - 1];
            countSign--; countVal--;
        }
        if (Sign[End - countSign] == '/'){
            if(val[countVal - 1] != 0){
                val[countVal - 2] = val[countVal - 2] / val[countVal - 1];
                countSign--; countVal--;
            }
            else{
                flag = 1;
                std::cerr << "Error! Can't divide by zero";
                break;
            }
        }
        if (Sign[End - countSign] == '+'){
            val[countVal - 2] = val[countVal - 2] + val[countVal - 1];
            countSign--; countVal--;
        }
        if (Sign[End - countSign] == '-'){
            val[countVal - 2] = val[countVal - 2] - val[countVal - 1];
            countSign--; countVal--;
        }
    }
}
int PrSymbol(char a){ //проверка на знаки, числа, скобочки, и пробелы
    if((a >= '0' && a <= '9') || a=='.')
        return 1;
    else if(a == '*' || a == '/' || a == '+' || a == '-')
        return 2;
    else if(a == '(' || a == ')')
        return 3;
    else if(a == ' ')
        return 4;
    else
        return 0;
}
void Help(int flagR){ //преобразует исходную строчку в строчку, где каждый токен разделён пробелом
    int k = 0;
    for(int i = 0; i < 200; i++){
        str1[i] = 0;
    }
    int l = 0;
    if(flagR == 0){
        for(int r = 0; r < 200;r++) {
            if (str2[r] != ' ') {
                str1[l] = str2[r];
                l++;
            }
        }
    } else if (flagR == 1){
        for(int r = 0; r < 200;r++) {
            if (str2[r] != ' ' || (str2[r] == ' ' && str2[r+1] != ' ')) {
                str1[l] = str2[r];
                l++;
            }
        }
    }
    //
    if(str1[0] == '-' && PrSymbol(str1[1]) == 1) {
        str += str1[k];
        k++;
    }
    for(; k < 200; k++){
        if(str1[k] != 0) {
            if (PrSymbol(str1[k]) == 0){
                std::cerr << "Wrong expression1 " << std::endl;
                flag=1;
            }
            if (PrSymbol(str1[k]) == 1){
                str += str1[k];
                if(PrSymbol(str1[k + 1]) == 2 || PrSymbol(str1[k + 1]) == 3 || PrSymbol(str1[k + 1]) == 4){
                    str += " ";
                }
            } else if (PrSymbol(str1[k]) == 2){
                str += str1[k];
                if(PrSymbol(str1[k + 1]) == 2){
                    if(flagR == 0) {
                        std::cerr << "Wrong expression2" << std::endl;
                        flag = 1;
                    } else if(flagR == 1)
                        str += " ";
                }
                if(PrSymbol(str1[k + 1]) == 1 || PrSymbol(str1[k + 1]) == 3 || PrSymbol(str1[k + 1]) == 4){
                    if(PrSymbol(str1[k + 1]) == 1 && str1[k] == '-' && (str1[k - 1] == '(' || (str1[k - 1] == ' ' && str1[k - 2] == '('))){

                    } else {
                        str += " ";
                    }
                }
            } else if (PrSymbol(str1[k]) == 3){
                str += str1[k];
                if (PrSymbol(str1[k + 1]) == 3 || PrSymbol(str1[k + 1]) == 2){
                    if(((str1[k]) == ')' && (str1[k+1] == ')' || PrSymbol(str1[k+1]) == 2 || (PrSymbol(str1[k+2]) == 2)  && str1[k+1] == ' ') )
                       || (str1[k] == '(' && (str1[k+1] == '(' || (PrSymbol(str1[k+2]) == 1 && str1[k+1] == '-'))
                           || (PrSymbol(str1[k+3]) == 1 && str1[k+2] == '-' && str1[k+1] == ' '))){
                        str += " ";
                    } else {
                        std::cerr << "Wrong expression3" << std::endl;
                        flag=1;
                    }
                } else if(PrSymbol(str1[k + 1]) == 1 || PrSymbol(str1[k + 1]) == 4){
                    str += " ";
                }
            }
        }
    }
}
