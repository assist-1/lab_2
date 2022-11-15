#include<iostream>
// #include<string>
// #include <fstream>
// using std::string;
// using std::ifstream;
// using std::cout;
// using std::cin;
const char * str;
int infix();
int opn();
char peek()
{
    return *str;
}

char get()
{
    return *str++;
}
int number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

int fac()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get();
        int result = infix();
        get();
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -fac();
    }
    return 0;
}

int term()
{
    int result = fac();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= fac();
        else
        {
            result /=fac();
        }
    return result;
}

int infix()
{
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

int opn()
{
    int result = 0;
    int a = fac();
    while(peek() != '='){
    get();
    int b = fac();
    get();
    switch (peek())
    {
    case '+':
        get();
        result = a + b;
        a = result;
        break;
    case '-':
        get();
        result = a - b;
        a = result;
        break;
    case '*':
        get();
        result = a * b;
        a = result;
        break;
    case '/':
        get();
        if (b == 0) {
        return -1;
        }
        else{
            result = a / b;
            a = result;
            break;
        }
    }
    }
    return result;
}