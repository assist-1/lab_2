#include "reverse.h"
#include "forward.h"

const char* str;

int opn(){
    int result = 0;
    int a = number();
    while(peek() != '='){
        get();
        int b = number();
        get();
        switch (peek()){
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
