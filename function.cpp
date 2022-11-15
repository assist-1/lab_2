#include <iostream>
#include <cstring>

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

int Resultfor(int* sign, int* num, int n){
    if (!Check(sign, n))
        return 0;
    int i = 0, flag = 0;
    while (sign[i] != 4 && sign[i] != 3 && flag == 0 && i < n) {
        if (sign[i] == 7) {
            flag = 1;
            break;
        } else
            ++i;
    }
    if (flag == 0) {
        int i1 = 0;
        while (sign[i1] != 7) ++i1;
        if (sign[i] == 4)
            num[i1] = (-1) * num[i1];
        sign[i] = 0;
    }
    while ( find (sign, -1, n) != -1) {
        int i1 = find(sign, -1, n), i2 = i1, k = i1;
        int *numsk = new int[200];
        int *signsk = new int[200];
        for (int i = 0; sign[k] != -2; ++i) {
            numsk[i] = num[k];
            signsk[i] = sign[k];
            ++k;
            ++i2;
        }
        signsk[i2 - i1 + 1] = 0; numsk[i2 - i1 + 1] = 0;
        signsk[0] = 0; numsk[0] = 0;
        int j = 0, flag = 0;
        while (signsk[j] != 4 && signsk[j] != 3 && flag == 0 && j < n) {
            if (signsk[j] == 7) flag = 1;
            ++j;
        }
        if (flag == 0) {
            int j1 = 0;
            while (signsk[j1] != 7) ++j1;
            if (signsk[j] == 4)
                numsk[j1] = (-1) * numsk[j1];
            signsk[j] = 0;
        }
        while ( find (signsk, 1, n) != -1){
            int i2 = find (signsk, 1, n);
            *numsk = del(signsk, numsk, i2);
            *signsk = chist(signsk, i2);
        }
        while ( find (signsk, 2, n) != -1){
            int i2 = find (signsk, 2, n);
            *numsk = umn(signsk, numsk, i2);
            *signsk = chist(signsk, i2);
        }
        while ( find (signsk, 4, n) != -1){
            int i2 = find (signsk, 4, n);
            *numsk = minus(signsk, numsk, i2);
            *signsk = chist(signsk, i2);
        }
        while ( find (signsk, 3, n) != -1){
            int i2 = find (signsk, 3, n);
            *numsk = plus(signsk, numsk, i2);
            *signsk = chist(signsk, i2);
        }
        int ivlog = 0;
        for (int i = i1; i <= i2 ; ++i){
            sign[i] = signsk[ivlog];
            num[i] = numsk[ivlog];
            ++ivlog;
        }
        memset(signsk, 0, sizeof(signsk));
        memset(numsk, 0, sizeof(numsk));
        delete []numsk;
        delete []signsk;
    }
    while ( find (sign, 1, n) != -1){
        int i2 = find (sign, 1, n);
        *num = del(sign, num, i2);
        *sign = chist(sign, i2);
    }
    while ( find (sign, 2, n) != -1){
        int i2 = find (sign, 2, n);
        *num = umn(sign, num, i2);
        *sign = chist(sign, i2);
    }
    while ( find (sign, 4, n) != -1){
        int i2 = find (sign, 4, n);
        *num = minus(sign, num, i2);
        *sign = chist(sign, i2);
    }
    while ( find (sign, 3, n) != -1){
        int i2 = find (sign, 3, n);
        *num = plus(sign, num, i2);
        *sign = chist(sign, i2);
    }
    int result = 0;
    flag = 0;
    for (int i = 0; i < n; ++i){
        if (sign[i] == 7) {
            if (flag == 0) {
                result = num[i];
                flag = 1;
            } else {
                std::cerr << "Wrong expression\n";
                return 0;
            }
        } else
        if (sign[i] != 0) {
            std::cerr << "Wrong expression\n";
            return 0;
        }
    }
    return result;
}

int Resultrev (int* sign, int* num, int n) {
    if (Checkrev(sign, n) == 0){
        return 0;
    }
    for (int i = 0; i < n; ++i){
        if (sign[i] != 0 && sign[i] != 7){
            int dop1 = 0, dop2 = 0;
            for (int j = i - 1; j >= 0; --j)
                if (sign[j] == 7) {
                    dop1 = num[j];
                    num[j] = 0;
                    sign[j] = 0;
                    break;
                }
            for (int j = i - 1; j >= 0; --j)
                if (sign[j] == 7) {
                    dop2 = num[j];
                    sign[j] = 0;
                    num[j] = 0;
                    break;
                }
            num[i] = deistrev (dop2, dop1, sign[i]);
            sign[i] = 7;
        }
    }
    int result = 0, flag = 0;
    for (int i = 0; i < n; ++i){
        if (sign[i] == 7) {
            if (flag == 0) {
                result = num[i];
                flag = 1;
            } else {
                std::cerr << "Wrong expression\n";
                return 0;
            }
        } else
            if (sign[i] != 0) {
                std::cerr << "Wrong expression\n";
                return 0;
            }
    }
    return result;
}

int EnterCheck (int argc) {
    if ( (argc < 2) || (argc > 3) ){
        std::cerr << "Enter the '--forward' if you want to calculate straight the forward expression and '--reverse' if you want to calculate the reverse expression\n" << "Enter the '--file' if you want to take data from the file\nPlease, try again\n";
        return 0;
    }
    return 1;
}

int EnterExp (char** argv){
    if ((strcmp(argv[1], "--forward") == 1 && strcmp(argv[1], "--reverse")) == 1) {
        std::cerr << "Wrong command, try again";
        return 0;
    }
    return 1;
}