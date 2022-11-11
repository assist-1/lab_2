#include <iostream>
#include <cstdio>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
const int LENSTR = 5555;
char exp[LENSTR];
void ReadFromCin(){
    cin.read(exp,LENSTR-1);
    int s = cin.gcount();
    exp[s] = '\0';
}
void ReadFromFile(char *name){
    std::fstream file;
    char sym;
    int i = 0;
    while (file >> sym){
        exp[i] = sym;
        i++;
    }
    file.close();
}
int IsDigit(char c){
    if (c >= '0' && c<='9') return 1;
    else return 0;
}
int IsOper(char c){
    if (c == '*' || c == '/' || c == '+' || c=='-') return 1;
    else return 0;
}
int CheckPriority(char c1, char c2){
    if ((c2 == '*' || c2 == '/') && ((c1 == '+') || (c1 == '-') || (c1 == '*') || (c1 == '/')) return 1;
    if ((c2 == '+' || c2 == '-')) && ((c1 == '+') || (c1 == '-')) return 1;
    else return -1;
}
int Calculation(int c1, int c2,char operation){
    if (operation == '*') return c1*c2;
    if (operation == '-') return c1-c2;
    if (operation == '+') return c1+c2;
    if (operation == '/') return c1/c2;
    else return 0;
}
s
