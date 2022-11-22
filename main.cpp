//
// Created by Тимур on 18.10.2022.
//
#include "header.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
int main(int argc, char **argv) {
    int *num = new int[300];
    int *sign = new int[400];
    int n = 0;
    cout << argc;
    if (argc != 2 && argc != 3) {
        cout << "Неправильное количество аргументов";
        return 0;
    }
    if (strcmp(argv[1], "--forward") != 0 && strcmp(argv[1], "--reverse") != 0) {
        cout << "Неправильный аргумент";
        return 0;
    }
    if (argc == 3) {
        if (strcmp(argv[1], "--file") == 1)
            std::cerr << "Неправильная команда";
        char x;
        std::ifstream fin("/Users/timur/Desktop/input.txt");
        int i = 0;
        while (!fin.eof()) {
            x = fin.peek();
            if (x >= '0' && x <= '9') {
                fin >> num[i];
                sign[i] = 7;
            } else {
                sign[i] = oper(x);
                num[i] = 0;
                fin.ignore();
            }
            if (x != ' ') ++i;
        }
        fin.close();
        n = i;
    }
    if (argc == 2) {
        cout << "Введите выражение" << std::endl;
        int i = 0;
        while (1) {
            char x = cin.peek();
            if (x == '\n') break;
            if (x >= '0' && x <= '9') {
                cin >> num[i];
                sign[i] = 7;
            } else {
                sign[i] = oper(x);
                num[i] = 0;
                cin.ignore();
            }
            if (x != ' ') ++i;
        }
        n = i;
        for (int i = 0; i < n; ++i) {
            cout << num[i] << "\n";
        }
        if (strcmp(argv[1], "--reverse") == 0){
            if (examopn(sign, n) == 0){
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
                    num[i] = actopn (dop2, dop1, sign[i]);
                    sign[i] = 7;
                }
            }
        }
        if (strcmp(argv[1], "--forward") == 0) {
            if (!exam(sign, n))
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
                if (sign[i] == 3)
                    num[i1] = (-1) * num[i1];
                sign[i] = 0;
            }
            while (find(sign, 5, n) != -1) {
                int i1 = find(sign, 5, n), i2 = i1, k = i1;
                int *numsk = new int[300];
                int *signsk = new int[300];
                for (int i = 0; sign[k] != 6; ++i) {
                    numsk[i] = num[k];
                    signsk[i] = sign[k];
                    ++k;
                    ++i2;
                }
                signsk[i2 - i1 + 1] = 0;
                numsk[i2 - i1 + 1] = 0;
                signsk[0] = 0;
                numsk[0] = 0;
                int j = 0, flag = 0;
                while (signsk[j] != 4 && signsk[j] != 3 && flag == 0 && j < n) {
                    if (signsk[j] == 7) flag = 1;
                    ++j;
                }
                if (flag == 0) {
                    int j1 = 0;
                    while (signsk[j1] != 7) ++j1;
                    if (signsk[j] == 3)
                        numsk[j1] = (-1) * numsk[j1];
                    signsk[j] = 0;
                }
                while (find(signsk, 1, n) != -1) {
                    int i2 = find(signsk, 1, n);
                    *numsk = div(signsk, numsk, i2);
                    *signsk = clean(signsk, i2);
                }
                while (find(signsk, 2, n) != -1) {
                    int i2 = find(signsk, 2, n);
                    *numsk = mul(signsk, numsk, i2);
                    *signsk = clean(signsk, i2);
                }
                while (find(signsk, 3, n) != -1) {
                    int i2 = find(signsk, 3, n);
                    *numsk = sub(signsk, numsk, i2);
                    *signsk = clean(signsk, i2);
                }
                while (find(signsk, 4, n) != -1) {
                    int i2 = find(signsk, 4, n);
                    *numsk = add(signsk, numsk, i2);
                    *signsk = clean(signsk, i2);
                }
                int ivlog = 0;
                for (int i = i1; i <= i2; ++i) {
                    sign[i] = signsk[ivlog];
                    num[i] = numsk[ivlog];
                    ++ivlog;
                }

                for (int i = 0; i < i2 - i1 + 1; ++i) {
                    numsk[i] = signsk[i] = 0;
                }
                delete[]numsk;
                delete[]signsk;
            }
            while (find(sign, 1, n) != -1) {
                int i2 = find(sign, 1, n);
                *num = div(sign, num, i2);
                *sign = clean(sign, i2);
            }
            while (find(sign, 2, n) != -1) {
                int i2 = find(sign, 2, n);
                *num = mul(sign, num, i2);
                *sign = clean(sign, i2);
            }
            while (find(sign, 3, n) != -1) {
                int i2 = find(sign, 3, n);
                *num = sub(sign, num, i2);
                *sign = clean(sign, i2);
            }
            while (find(sign, 4, n) != -1) {
                int i2 = find(sign, 4, n);
                *num = add(sign, num, i2);
                *sign = clean(sign, i2);
            }
        }
    }
    int result = 0, flag = 0;
    for (int i = 0; i < n; ++i){
        if (sign[i] == 7) {
            if (flag == 0) {
                result = num[i];
                flag = 1;
            } else {
                std::cerr << "Неправильное выражение\n";
                return 0;
            }
        } else
        if (sign[i] != 0) {
            std::cerr << "Неправильное выражение\n";
            return 0;
        }
    }
    cout << "Результат выражения: " << result << "\n";
    delete []num;
    delete []sign;
}