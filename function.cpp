#include <iostream>

#include "function.h"

int flag = 0;
int countVal = 0;
int countSign = 0;
int countHooks1 = 0;
int countHooks2 = 0;
double val[200];
char Sign[200];
int hooks [200];

int PrSigns (char b){
    if(b == '+' || b == '-')
        return 1;
    if(b == '*' || b == '/')
        return 2;
    else return 0;
}

bool Digit(char a) {
    if((( a >= '0' && a <= '9') || a == '.' || a == '-'))
        return true;
    return false;
}

bool Pr(char ar[200], int value){
    for(int i = 0; i < value;i++){
        if(!Digit(ar[i]))
            return false;
    }
    return true;
}
void CompareSign (char sign1, char sign2){
    if(PrSigns(sign2) < PrSigns(sign1) && countVal - 2 >= hooks[countHooks2]){
        if (sign1 == '*'){
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
}

void FinishStep(){
    while (countVal != 1){
        if (Sign[countSign - 1] == '*'){
            val[countVal - 2] = val[countVal - 2] * val[countVal - 1];
            countSign--; countVal--;
        }
        if (Sign[countSign - 1] == '/'){
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
        if (Sign[countSign - 1] == '+'){
            val[countVal - 2] = val[countVal - 2] + val[countVal - 1];
            countSign--; countVal--;
        }
        if (Sign[countSign - 1] == '-'){
            val[countVal - 2] = val[countVal - 2] - val[countVal - 1];
            countSign--; countVal--;
        }
    }
}

void endHooks(int end){
//    std::cout << "123 " << end << " " << countVal << std::endl;
    while (countVal - 2 >= end){
        if (Sign[countSign - 1] == '*'){
            val[countVal - 2] = val[countVal - 2] * val[countVal - 1];
            countSign--; countVal--;
        }
        if (Sign[countSign - 1] == '/'){
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
        if (Sign[countSign - 1] == '+'){
            val[countVal - 2] = val[countVal - 2] + val[countVal - 1];
            countSign--; countVal--;
        }
        if (Sign[countSign - 1] == '-'){
            val[countVal - 2] = val[countVal - 2] - val[countVal - 1];
            countSign--; countVal--;
        }
    }
}

void StepReverse(int End){
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