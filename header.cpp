//
// Created by Тимур on 07.11.2022.
//
#include <iostream>
int oper (char x){
    int a = 8;
    switch (x) {
        case (' ') : {a = 0; break;}
        case ('/') : {a = 1; break;}
        case ('*') : {a = 2; break;}
        case ('-') : {a = 3; break;}
        case ('+') : {a = 4; break;}
        case ('(') : {a = 5; break;}
        case (')') : {a = 6; break;}
        default : break;
    }
    return a;
}
int find (int *sign, int b, int n){
    int ind = -1;
    for (int i = 0; i < n; ++i)
        if (sign[i] == b)
            ind = i;
    return ind;
}
int clean(int* sign, int i){
    int r = 1;
    while (sign[i + r] != 7)
        ++r;
    sign[i + r] = 0;
    r = -1;
    while (sign[i + r] != 7)
        --r;
    sign[i + r] = 0;
    sign[i] = 7;
    return (*sign);
}
int div (int* sign, int *num, int i){
    int r = 1;
    while (sign[i + r] != 7)
        ++r;
    num[i] = num[i + r];
    num[i + r] = 0;
    r = -1;
    while (sign[i + r] != 7)
        --r;
    num[i] = num[i + r] / num[i];
    num[i + r] = 0;
    return (*num);
}
int mul (int* sign, int *num, int i){
    int r = 1;
    while (sign[i + r] != 7)
        ++r;
    num[i] = num[i + r];
    num[i + r] = 0;
    r = -1;
    while (sign[i + r] != 7)
        --r;
    num[i] = num[i + r] * num[i];
    num[i + r] = 0;
    return (*num);
}
int sub (int* sign, int *num, int i){
    int r = 1;
    while (sign[i + r] != 7)
        ++r;
    num[i] = - num[i + r];
    num[i + r] = 0;
    r = -1;
    while (sign[i + r] != 7)
        --r;
    num[i] = num[i + r] + num[i];
    num[i + r] = 0;
    return (*num);
}
int add (int* sign, int *num, int i){
    int r = 1;
    while (sign[i + r] != 7)
        ++r;
    num[i] = num[i + r];
    num[i + r] = 0;
    r = -1;
    while (sign[i + r] != 7)
        --r;
    num[i] = num[i + r] + num[i];
    num[i + r] = 0;
    return (*num);
}
int actopn (int dop1, int dop2, int i){
    int a;
    switch (i) {
        case (1) : {a = dop1 / dop2; break;}
        case (2) : {a = dop1 * dop2; break;}
        case (3) : {a = dop1 - dop2; break;}
        case (4) : {a = dop1 + dop2; break;}
        default : {break;}
    }
    return a;
}
int exam (int* sign, int n){
    int ko = 0, kz = 0;
    if (sign[0] == 1 || sign[0] == 2){
        std::cerr << "Неправильное выражение. В начале '*' или '/' \n";
        return 0;
    }
    for (int i = 0; i < n; ++i){
        if ( (sign[i] > 4 || sign[i] < -2) && sign[i] !=7 ){
            std::cerr << "Неправильный оператор\n";
            return 0;
        }
        if ( sign[i] > 0 && sign[i] < 5 && sign[i + 1] > 0 && sign[i + 1] < 5 ){
            std::cerr << "Неправильный оператор\n";
            return 0;
        }
        if (sign[i] == 7 && sign[i + 1] == 7){
            std::cerr << "Неправильное выражение\n";
            return 0;
        }
        if (sign[i] == -1)
            ++ko;
        if (sign[i] == -2){
            if (ko == 0){
                std::cerr << "Неправильное выражение. ')' без '('\n";
                return 0;
            } else
                --ko;
        }
    }
    if (ko != 0){
        std::cerr << "Разное количество '()'\n";
        return 0;
    }
    return 1;
}
int examopn (int* sign, int n){
    int k = 0;
    for (int i = 0; i < n; ++i){
        if ( (sign[i] > 4 || sign[i] < 0) && sign[i] !=7 ){
            std::cerr << "Неправильный оператор\n";
            return 0;
        }
        if (sign[i] == 7) ++k;
        else {
            if (sign[i] != 0) --k;
            if (k < 0) {
                std::cerr << "Неправильное выражение\n";
                return 0;
            }
        }
    }
    if (k != 1){
        std::cerr << "Неправильное выражение\n";
        return 0;
    }
    return 1;
}