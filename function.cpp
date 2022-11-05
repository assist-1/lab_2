#include <iostream>

int Operator (char x){
    int a = 12;
    switch (x) {
        case (' ') : {a = 0; break;}
        case ('/') : {a = 1; break;}
        case ('*') : {a = 2; break;}
        case ('+') : {a = 3; break;}
        case ('-') : {a = 4; break;}
        case ('(') : {a = -1; break;}
        case (')') : {a = -2; break;}
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

int chist(int* sign, int i){
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

int del (int* sign, int *num, int i){
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

int umn (int* sign, int *num, int i){
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

int minus (int* sign, int *num, int i){
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

int plus (int* sign, int *num, int i){
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

int deistrev (int dop1, int dop2, int i){
    int a;
    switch (i) {
        case (1) : {a = dop1 / dop2; break;}
        case (2) : {a = dop1 * dop2; break;}
        case (3) : {a = dop1 + dop2; break;}
        case (4) : {a = dop1 - dop2; break;}
        default : {break;}
    }
    return a;
}

int Check (int* sign, int n){
    int ko = 0, kz = 0;
    if (sign[0] == 1 || sign[0] == 2){
        std::cerr << "Wrong expression. '*' or '/' in the beginning\n";
        return 0;
    }
    for (int i = 0; i < n; ++i){
        if ( (sign[i] > 4 || sign[i] < -2) && sign[i] !=7 ){
            std::cerr << "Wrong operator. Try again\n";
            return 0;
        }
        if ( sign[i] > 0 && sign[i] < 5 && sign[i + 1] > 0 && sign[i + 1] < 5 ){
            std::cerr << "Wrong operation. Try again\n";
            return 0;
        }
        if (sign[i] == 7 && sign[i + 1] == 7){
            std::cerr << "Wrong expression\n";
            return 0;
        }
        if (sign[i] == -1)
            ++ko;
        if (sign[i] == -2){
            if (ko == 0){
                std::cerr << "Wrong expression. ')' without '('\n";
                return 0;
            } else
                --ko;
        }
    }
    if (ko != 0){
        std::cerr << "Different quality of '()'\n";
        return 0;
    }
    return 1;
}

int Checkrev (int* sign, int n){
    int k = 0;
    for (int i = 0; i < n; ++i){
        if ( (sign[i] > 4 || sign[i] < 0) && sign[i] !=7 ){
            std::cerr << "Wrong operator. Try again\n";
            return 0;
        }
        if (sign[i] == 7) ++k;
        else {
            if (sign[i] != 0) --k;
            if (k < 0) {
                std::cerr << "Wrong expression. Try again\n";
                return 0;
            }
        }
    }
    if (k != 1){
        std::cerr << "Wrong expression. Try again\n";
        return 0;
    }
    return 1;
}