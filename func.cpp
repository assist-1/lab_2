#include <iostream>
#include <cstdio>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
const int LENSTR = 200;
char exp[LENSTR];
char SymStack[500]; // стек символов
int ValStack[500];  // стек значений
int iVal = 0, iSym = 0;   // счётчик в стеке
int iexp = 0; // счетчик массива входного потока
void Options() {
    cout << endl;
    cout << "USAGE: ./prog [ (--forward, --reverse)> --file <namefile>  ]\n";
    std::cout << "\n------------------------------------Flags -----------------------------------\n\n";
    cout << "--forward  -------  Enter in common form" << endl;
    cout << "--reverse  -------  Enter in Pollish form" << endl;
    cout << "--file     -------  Enter form file";
    cout << "\n\n";
}
void ReadFromCin(){
    cin.read(exp,LENSTR-1);
    int s = cin.gcount();
    exp[s] = '\0';
}
int ReadFromFile(char *name){
    ifstream file(name);
    char sym;
    int i = 0;
    if (file.is_open()){
        while (file >> sym){
            exp[i] = sym;
            i++;
        }
        file.close();
        return 0;
    }
    return 1;

}
int IsDigit(char c){
    if (c >= '0' && c<='9') return 1;
    return 0;
}
int IsOper(char c){
    if (c == '*' || c == '/' || c == '+' || c=='-') return 1;
    return 0;
}
int CheckPriority(char c1, char c2){
    if ((c2 == '*' || c2 == '/') && (c1 == '+' || c1 == '-')) return 1;
    else if ((c2 == '*' || c2 == '/') && (c1 == '*' || c1 == '/')) return 1;
    else if ((c2 == '+' || c2 == '-') && (c1 == '+' || c1 == '-')) return 1;
    else return 0;
}
int Calculation(int c1, int c2,char operation){
    if (operation == '*') return c1*c2;
    if (operation == '-') return c1-c2;
    if (operation == '+') return c1+c2;
    if (operation == '/') return c1/c2;
    else return -1;
}
int Forward(){
    char SymStack[500]; // стек символов
    int ValStack[500];  // стек значений
    int c1, c2;    //промежуточные переменные
    char operation;  //
    int iVal = 0, iSym = 0;   // счётчик в стеке
    int iexp = 0; // счетчик массива входного потока
    char token = exp[0];   // текущий элемент
    while (token = exp[iexp]){    //пока существует токен
        iexp++;
        if (IsDigit(token)){  //если токен - цифра, то записываем символ и учитываем случай,
            c1 = token - '0'; //  когда итоговое значение более 1 знака

            while (IsDigit(exp[iexp])){
                token = exp[iexp];
                iexp++;
                c1 = 10*c1 + token - '0';
        }
            ValStack[iVal] = c1;  //итоговое значение записываем в стэк
            iVal++;
        }
        else if (IsOper(token)){  // если токен - это операция, то мы,
            while (iSym !=0 && CheckPriority(token,SymStack[iSym - 1])){ //при условии меньшего приоритета по отношению к последней
                    iSym--;   // выполняем операцию, которая была в стеке с двумя предыдущими числами
                    operation = SymStack[iSym];
                    iVal--;
                    c1 = ValStack[iVal];
                    iVal--;
                    c2 = ValStack[iVal];
                    ValStack[iVal] = Calculation(c2,c1,operation);
                    iVal++;
            }
            SymStack[iSym] = token;  // А иначе просто записываем токен в стек
            iSym++;
        }
        else if (token == '('){ //Если встретилась левая скобка, то записываем в стек
            SymStack[iSym] = token;
            iSym++;
        }
        else if (token == ')'){ //Если встретилась правая скобка
            while(SymStack[iSym-1] !='('){ // И пока не было последним элементом левая скобка, то считаем выражение
                iSym--;
                operation = SymStack[iSym];
                iVal--;
                c1 = ValStack[iVal];
                iVal--;
                c2 = ValStack[iVal];
                ValStack[iVal] = Calculation(c2,c1,operation);
                iVal++;
            }
            iSym--;
        }
    }
    while (iSym!=0){ //Если в стеке символов еще  есть операция, то выполняем ее с последними 2мя числами в стеке и
        iSym--;   //результат записываем в стек значений
        operation = SymStack[iSym];
        iVal--;
        c1 = ValStack[iVal];
        iVal--;
        c2 = ValStack[iVal];
        ValStack[iVal] = Calculation(c2,c1,operation);
        iVal++;
    }
    cout << "The result is " << ValStack[--iVal] << endl;
    return 0;
}
int Reverse(){
    int c1,c2;
    char operation;
    int iexp = 0;
    c1 = exp[iexp] - '0';
    iexp++;
    while (IsDigit(exp[iexp])){
        c1 = c1*10 + exp[iexp] - '0';
        iexp++;
    }
    while (exp[iexp]){
        if (!IsDigit(exp[iexp])){
            iexp++;
            continue;
        }
        c2 = exp[iexp] - '0';
        iexp++;
        while (IsDigit(exp[iexp])){
            c2 = c2*10 + exp[iexp] - '0';
        }
        while (!IsOper(exp[iexp])){
            iexp++;
        }
        operation = exp[iexp];
        iexp++;
        c1 = Calculation(c1,c2,operation);
    }
    cout << "The result is " << c1 << endl;
    return 0;
}
