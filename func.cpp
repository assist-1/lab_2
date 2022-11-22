#include <iostream>
#include <fstream>
#include "Lab2.h"
float num[1000];
char op[1000];
char s;
float k = -1000000000;
int j = -1;
int i = -1;
int flag = 0;

int isdigit(char x) {
    if (x >= '0' && x <= '9') {
        return 1;
    }
    return 0;
}

int isar(char x) {
    if (x == '*' || x == '/' || x == '+' || x == '-') {
        return 1;
    }
    return 0;
}

int tonum(char x) {
    switch (x) {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
    return -1;
}

int cleanfor2() {
    while (j > -1 && i > 0 && op[j] != '-' && op[j] != '+') {
        if (i > 0) {
            if (op[j] == '*') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] * num[i];
            }
            else if (op[j] == '/') {
                op[j] = ' ';
                if (num[i] != 0) {
                    num[i - 1] = num[i - 1] / num[i];
                }
                else {
                    std::cout << "ERROR! Division by zero" << std::endl;
                    return -1000000000;
                }
            }
            k = num[i - 1];
            num[i] = 0;
            i -= 1;
        }
        else {
            std::cout << "ERROR" << std::endl;
            return -1000000000;
        }
        j -= 1;
    }
    return 0;
}

int cleanfor1() {
    while (j > -1 && i > 0 && op[j] != '(') {
        if (i > 0) {
            if (op[j] == '*') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] * num[i];
            }
            else if (op[j] == '+') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] + num[i];
            }
            else if (op[j] == '-') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] - num[i];
            }
            else if (op[j] == '/') {
                op[j] = ' ';
                if (num[i] != 0) {
                    num[i - 1] = num[i - 1] / num[i];
                }
                else {
                    std::cout << "ERROR! Division by zero" << std::endl;
                    return -1000000000;
                }
            }
            k = num[i - 1];
            num[i] = 0;
            i -= 1;
        }
        else {
            std::cout << "ERROR" << std::endl;
            return -1000000000;
        }
        j -= 1;
    }
    return 0;
}

int cleanforscb223() {
    while (op[j] != '(') {
        if (i > 0) {
            if (op[j] == '*') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] * num[i];
            }
            else if (op[j] == '+') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] + num[i];
            }
            else if (op[j] == '-') {
                op[j] = ' ';
                num[i - 1] = num[i - 1] - num[i];
            }
            else if (op[j] == '/') {
                op[j] = ' ';
                if (num[i] != 0) {
                    num[i - 1] = num[i - 1] / num[i];
                }
                else {
                    std::cout << "ERROR! Division by zero" << std::endl;
                    return -1000000000;
                }
            }
            k = num[i - 1];
            num[i] = 0;
            i -= 1;
        }
        else {
            std::cout << "ERROR" << std::endl;
            return -1000000000;
        }
        j -= 1;
    }
    return 0;
}

std::ifstream file2;

float pr() {
    file2.open("calcul.txt");
    if (flag_file == 0) { s = getchar(); }
    else if (flag_file == 1) {
        s = file2.get(); 
    }
    while (s != '=') {
        if (isdigit(s)) {
            if (flag == 0) {
                flag = 1;
                num[++i] = (float)tonum(s);
            }
            else {
                num[i] = num[i] * 10 + (float)tonum(s);
            }
        }
        else if (s == ' ' || isar(s) || s == '(' || s == ')') {
            flag = 0;
            if (s == '(') {
                op[++j] = s;
            }
            else if (isar(s)) {
                if (j < 0) {
                    j = 0;
                    op[j] = s;
                }
                else {
                    if (s == '*' || s == '/') {
                        if (op[j] == '+' || op[j] == '-') {
                            op[++j] = s;
                        }
                        else {
                            cleanfor2();
                            op[++j] = s;
                        }
                    }
                    else {
                        if (op[j] == '(') {
                            op[++j] = s;
                        }
                        else {
                            cleanfor1();
                            op[++j] = s;
                        }
                    }
                }
            }
            else if (s == ')') {
                cleanforscb223();
                op[j] = ' ';
                j -= 1;
            }
        }
        if (flag_file == 0) { s = getchar(); }
        else if (flag_file == 1) {
            s = file2.get();
        }
        if (s == '=') {
            cleanfor1();
        }
    }
    file2.close();
    return k;
}
float OPN() {
    file2.open("calcul.txt");
    if (flag_file == 0) { s = getchar(); }
    else if (flag_file == 1) {
        s = file2.get();
    }
    while (s != '=') {
        if (isdigit(s)) {
            if (flag == 0) {
                flag = 1;
                num[++i] = (float)tonum(s);
            }
            else if (flag == 1) {
                num[i] = num[i] * 10 + (float)tonum(s);
            }
        }
        else if (s == ' ') {
            flag = 0;
        }
        else if (isar(s)) {
            if (i > 0) {
                if (s == '*') {
                    num[i - 1] = num[i - 1] * num[i];
                }
                else if (s == '+') {
                    num[i - 1] = num[i - 1] + num[i];
                }
                else if (s == '-') {
                    num[i - 1] = num[i - 1] - num[i];
                }
                else if (s == '/') {
                    if (num[i] != 0) {
                        num[i - 1] = num[i - 1] / num[i];
                    }
                    else {
                        std::cout << "ERROR! Division by zero" << std::endl;
                        return -1000000000;
                    }
                }
                k = num[i - 1];
                num[i] = 0;
                i -= 1;
            }
            else {
                std::cout << "ERROR" << std::endl;
                return -1000000000;
            }
        }
        if (flag_file == 0) { s = getchar(); }
        else if (flag_file == 1) {
            s = file2.get();
        }
    }
    file2.close();
    return k;
}