#include "header.h"

int answ(int a, int b, char op){
    if (op == '+') return a+b;
    if (op == '-') return b-a;
    if (op == '*') return a*b;
    if (op == '/') return b/a;
    else return 0;
}
int oper(char p) {
    if (p == '+') return 2;
    if (p == '-') return -2;
    if (p == '*') return 3;
    if (p == '/') return -3;
    if (p == '(') return 1;
    return 0;
}