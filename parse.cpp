#include <fstream>
#include <iostream>
#include <cmath>


char Symbol = '\0';
int Digits[200];
char Ops[200];
int Digits_len = 0;
int Ops_len = 0;
bool number = false;  // flag indicating whether the length of current number is more than one symbol


int convert_to_int(char digit) {return digit - '0';}


int GetSymbol() {
    char s = getchar();

    if(s == '\n' ) {
        return 0;
    }   

    Symbol = s;
    return 1;
}


int precedence(char op){
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
    if (op == '^') return 2;
    if (op == '(') return 4;
	return 0;
}


int eval(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
}


void op() {
    number = false;
    if (Symbol == '+' ||
        Symbol == '-' ||
        Symbol == '*' ||
        Symbol == '/' ||
        Symbol == '^')
    {
    ++Ops_len;
    Ops[Ops_len] = Symbol;
    char op; int a, b;
    while (Ops_len && precedence(Ops[Ops_len]) >= precedence(Ops[Ops_len - 1]) && Digits_len > 1) {
        op = Ops[Ops_len];
        --Ops_len;
        b = Digits[Digits_len];
        --Digits_len;
        a = Digits[Digits_len];
        Digits[Digits_len] = eval(a, b, op);
    }
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
            while ((Ops[Ops_len] != '(') && Digits_len > 1) {
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


int main() {
    while (GetSymbol()) {
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


    std::cout << Digits[Digits_len] << std::endl;
    return 0;
    // return Digits[Digits_len];
}