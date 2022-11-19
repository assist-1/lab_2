#include <fstream>
#include <iostream>
#include <cmath>


char Symbol = '\0';
int Digits[200];
char Ops[200];
int Digits_len = 0;
int Ops_len = 0;
bool number = false;
std::ifstream input("input.txt");


int convert_to_int(char digit) {return digit - '0';}


int GetSymbol(bool from_file) {
    char s;
    if (from_file) s = input.get();
    else s = getchar();

    if(s == EOF || s == '\n') return 0;

    Symbol = s;
    return 1;
}


int precedence(char op){
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
    if (op == '^') return 2;
	return 0;
}


int eval(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}


void op() {
    number = false;
    if (Symbol == '+' ||
        Symbol == '-' ||
        Symbol == '*' ||
        Symbol == '/' ||
        Symbol == '^')
    {
    char op; int a, b;
    while (Ops_len && precedence(Ops[Ops_len]) >= precedence(Symbol) && Digits_len > 1) {
        op = Ops[Ops_len];
        --Ops_len;
        b = Digits[Digits_len];
        --Digits_len;
        a = Digits[Digits_len];
        Digits[Digits_len] = eval(a, b, op);
    }
    ++Ops_len;
    Ops[Ops_len] = Symbol;
    }
}


void parenthesis() {
    number = false;
    switch (Symbol) {
        case '(': 
            ++Ops_len;
            Ops[Ops_len] = Symbol;
            break;
        case ')':
            char op; int a, b; 
            while ((Ops[Ops_len] != '(')) {
                op = Ops[Ops_len];
                --Ops_len;
                b = Digits[Digits_len];
                --Digits_len;
                a = Digits[Digits_len];
                Digits[Digits_len] = eval(a, b, op);
            }
            --Ops_len;

    }
}


void digit() {
    if (number) {
        Digits[Digits_len] = Digits[Digits_len] * 10 + convert_to_int(Symbol);
    }
    else {
        Digits_len++;
        Digits[Digits_len] = convert_to_int(Symbol);
        number = true;
    }
}


int parse(bool from_file) {
    if (from_file) {
        if (!input) {
            std::cerr << "Unable to open input file" << std::endl;
            return -1;
        }
    }

    while (GetSymbol(from_file)) {
    if (isdigit(Symbol)) {
        digit();
    } 
    else if ((Symbol == '(') || (Symbol == ')')) {
        parenthesis();   
    } 
    else {
        op();
    }
    }

    char op; int a, b;
    while (Ops_len) {
        op = Ops[Ops_len];
        --Ops_len;
        b = Digits[Digits_len];
        --Digits_len;
        a = Digits[Digits_len];
        Digits[Digits_len] = eval(a, b, op);
    }

    if (from_file) input.close();

    return Digits[Digits_len];
}