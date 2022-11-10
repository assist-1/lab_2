#include "forward.h"
#include <iostream>

using std::cout;

extern char* str;

char peek(){
    return *str;
}

char get(){
    return *str++;
}

int number(){
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9'){
        result = 10*result + get() - '0';
    }
    return result;
}

int factor(){
    if (peek() >= '0' && peek() <= '9'){
        return number();
    }
    else if (peek() == '('){
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-'){
        get();
        return -factor();
    }
    return 0; // error
}

int term(){
    int result = factor();
    while (peek() == '*' || peek() == '/'){
        if (get() == '*'){
            result *= factor();
        }
        else{
            result /= factor();
        }
    }
    return result;
}

int expression(){
    int result = term();
    while (peek() == '+' || peek() == '-'){
        if (get() == '+'){
            result += term();
        }
        else{
            result -= term();
        }
    }
    return result;
}
