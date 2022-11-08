#include <iostream>

#include "function.h"

int flag = 0;
int countVal = 0;
int countSign = 0;
int countHooks1 = 0;
int countHooks2 = 0;
double val[200];
char Sign[200];
char str1[200];
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
int PrSymbol(char a){
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
void Help(int flagR){
    int k = 0;
    for(int i = 0; i < 200; i++){
        str[i] = 0;
    }
    if(str1[0] == '-' && PrSymbol(str1[1]) == 1) {
        str += str1[k];
        k++;
    }
    for(; k < 199; k++){
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
                       || (str1[k] == '(' && (PrSymbol(str1[k+2]) == 1 && str1[k+1] == '-')
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
