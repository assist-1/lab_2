#include <iostream>

double make_double(char str_double[],int len){
    double a = 0;
    int before_dot = 0, dot = 0;
    int l=0;
    int first = 0;
    if(str_double[0] == '-' || str_double[0]=='+') first = 1;
    for(int i=first; i < len; ++i){
        if(str_double[i] == '.'){
            dot = i;
            before_dot = l;
            l = 0;
        } else{
            ++l;
        }
        if(before_dot == 0){
            before_dot = l;
        }
    }
    double rate = 1;
    for(int i = 1; i < before_dot; ++i){
        rate *= 10;
    }
    for(int i = first; i < len; ++i){
        switch (str_double[i]) {
            case '0':
                a += rate * 0;
                break;
            case '1':
                a += rate * 1;
                break;
            case '2':
                a += rate * 2;
                break;
            case '3':
                a += rate * 3;
                break;
            case '4':
                a += rate * 4;
                break;
            case '5':
                a += rate * 5;
                break;
            case '6':
                a += rate * 6;
                break;
            case '7':
                a += rate * 7;
                break;
            case '8':
                a += rate * 8;
                break;
            case '9':
                a += rate * 9;
                break;
        }
        if(i != dot) rate /= 10;
    }
    if(str_double[0] == '-') a *= -1;
    return a;
}


int priority(char symbol){
    switch (symbol){
        case '(':
            return -1;
        case ')':
            return -1;
        case '*':
            return 1;
        case '/':
            return 1;
        case '-':
            return 2;
        case '+':
            return 2;
    }
    return 0;
}


double make_operation(double a, double b, char symbol){
    switch (symbol){
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '-':
            return a - b;
        case '+':
            return a + b;
    }
    return -1;
}

bool check_forward(char expression[], const int len){
    int *types = new int[200];
    int types_count = 0; types[types_count] = 0;
    int close_brackets=0, open_brackets=0;
    int dot = 0;
    for(int i = 0; i < len; ++i){
        if(expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.'){
            if(types[types_count] != 1){
                if(expression[i] >= '0' && expression[i] <= '9'){
                    ++types_count;
                    types[types_count] = 1;
                    dot = 0;
                } else{
                    return false;
                }
            } else{
                if(expression[i] == '.'){
                    ++dot;
                }
                if(dot > 1){
                    return false;
                }
            }
        }
        else if(expression[i] == '-' or expression[i] == '+'){
            if(types[types_count - 1] == 4 && types[types_count] == 5 || types[types_count] == 4){
                return false;
            }
            if(i + 1 < len){
                if(expression[i + 1] >= '0' && expression[i + 1] <= '9' || expression[i + 1] == '.'){
                    if(expression[i + 1] >= '0' && expression[i + 1] <= '9') {
                        if(types[types_count] != 1){
                            if(types[types_count] == 2 || types[types_count] == 5 && types[types_count - 1] == 2 || types[types_count] == 0){
                                ++types_count;
                                types[types_count] = 1;
                                dot = 0;
                            } else{
                                return false;
                            }
                        } else{
                            ++types_count;
                            types[types_count] = 4;
                        }
                    } else{
                        return false;
                    }
                } else{
                    ++types_count;
                    types[types_count] = 4;
                }
            }
        }
        else if(expression[i] == '*' or expression[i] == '/'){
            if(types[types_count - 1] == 4){
                return false;
            } else{
                ++types_count;
                types[types_count] = 4;
            }
        }
        else if(expression[i] == '('){
            ++open_brackets;
            ++types_count;
            types[types_count] = 2;
        }
        else if(expression[i] == ')'){
            ++close_brackets;
            ++types_count;
            types[types_count] = 3;
        }
        else if(expression[i] == ' '){
            ++types_count;
            types[types_count] = 5;
        }
        else{
            return false;
        }

        if(close_brackets > open_brackets){
            return false;
        }
    }
    if(close_brackets != open_brackets){
        return false;
    }

    if(types[1] == 4 || types_count == 4) {
        return false;
    }
    for(int i = 2; i < types_count; ++i){
        if(types[i] == 1 && types[i - 2] == 1 && types[i - 1] == 5){
            return false;
        }
    }
    delete []types;
    return true;
}

