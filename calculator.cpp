#include <iostream>
#include <cstring>
#include <fstream>
#include "calculator.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    int i = 0, j = 0, n = 100;
    double *operands = new double[n], value, res;
    char *operators = new char[n], arg = ' ', end = ' ';
    bool first_flag = true;
    if (argc == 2 && (strcmp(argv[1], "--forward") == 0 || strcmp(argv[1], "--reverse") == 0)) {      //Считывание с консоли
        end = '\n';
        while (arg != end) {
            arg = cin.peek();  //Считываем("Смотрим") на элемент, но не откладываем его в память
            if (arg == ' ') {
                cin.ignore();
                continue;
            }
            if (arg >= '0' && arg <= '9') {
                cin >> value;   //Посмотрели на символ, он оказался числом, значит, нужно считать все число целиком (cin.peek смотрит только на первый символ
                operands[i] = value; //а не на все число) cin позволяет считать все число целиком.
                i += 1;
                continue;
            }
            if (arg == '+' || arg == '-' || arg == '*' || arg == '/' || arg == '(' || arg == ')' || arg == '^') {
                if (j == 0 || (abs(OperationType(arg)) > abs(OperationType(operators[j - 1]))) ||
                    OperationType(arg) == 1) { // Если считываемый знак первый в массиве знаков или его приоритет больше приоритета предыдущего,то:
                    if ((j == 0 || j > 0 && OperationType(arg) == -2 && OperationType(operators[j - 1]) == 1) &&
                        OperationType(arg) == -2 && strcmp(argv[1], "--forward") == 0) { //Работа с минусом
                        operands[i] = 0;
                        i += 1;
                        operators[j] = arg;
                        j += 1;
                    } else { // Для остальных знаков
                        operators[j] = arg;
                        j += 1;
                    }
                    cin.ignore();
                } else {
                    if (OperationType(arg) == -1) { // Нашли закрывающуюся скобку, выполняем действия, пока не найдем открывающуюся)
                        while (abs(OperationType(arg)) != abs(OperationType(operators[j - 1]))) {
                            res = MathOperations(operands[i - 2], operands[i - 1], OperationType(operators[j - 1]));
                            operands[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                        }
                        j -= 1;
                        cin.ignore();
                    } else {
                        while (first_flag && abs(OperationType(arg)) <= abs(OperationType(operators[j - 1]))) {
                            res = MathOperations(operands[i - 2], operands[i - 1], OperationType(operators[j - 1]));
                            operands[i - 2] = res;
                            j -= 1;
                            i -= 1;
                            if (j == 0) {
                                operators[j] = arg;
                                j += 1;
                                cin.ignore();
                                first_flag = false;
                            }
                        }
                    }

                }
                continue;
            }
        }

        if (j == 0) { // Если в массиве со знаками пусто, то выводим 0ой элемент массива с числами
            cout << operands[0] << endl;
        } else { //Если остались какие-то знаки, то выполняем их по порядку, пока не закончатся
            j -= 1;
            i -= 1;
            while (j != -1) {
                res = MathOperations(operands[i - 1], operands[i], OperationType(operators[j]));
                operands[i - 1] = res;
                j -= 1;
                i -= 1;
            }
            cout << operands[0] << endl;
        }
    } else if (argc >= 2 && strcmp("--file", argv[2]) == 0) { //Считываем с файла
        std::ifstream input(argv[3]);
        cin.rdbuf(input.rdbuf());      //изменяем буфер потока ввода с консоли на буфер потока ввода с файла
        end = EOF;
        while (arg != end) {
            arg = cin.peek();
            if (arg == ' ') {
                cin.ignore();
                continue;
            }
            if (arg >= '0' && arg <= '9') {
                cin >> value;
                operands[i] = value;
                i += 1;
                continue;
            }
            if (arg == '+' || arg == '-' || arg == '*' || arg == '/' || arg == '(' || arg == ')' || arg == '^') {
                if (j == 0 || (abs(OperationType(arg)) > abs(OperationType(operators[j - 1]))) ||
                    OperationType(arg) == 1) {
                    if ((j == 0 || j > 0 && OperationType(arg) == -2 && OperationType(operators[j - 1]) == 1) &&
                        OperationType(arg) == -2 &&
                        strcmp(argv[1], "--forward") == 0) {
                        operands[i] = 0;
                        i += 1;
                        operators[j] = arg;
                        j += 1;
                    } else {
                        operators[j] = arg;
                        j += 1;
                    }
                    cin.ignore();
                } else {
                    if (OperationType(arg) == -1) {
                        while (abs(OperationType(arg)) != abs(OperationType(operators[j - 1]))) {
                            res = MathOperations(operands[i - 2], operands[i - 1], OperationType(operators[j - 1]));
                            operands[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                        }
                        j -= 1;
                        cin.ignore();
                    } else {
                        while (first_flag && abs(OperationType(arg)) <= abs(OperationType(operators[j - 1]))) {
                            res = MathOperations(operands[i - 2], operands[i - 1], OperationType(operators[j - 1]));
                            operands[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                            if (j == 0) {
                                operators[j] = arg;
                                j += 1;
                                cin.ignore();
                                first_flag = false;
                            }
                        }
                    }

                }
                continue;
            }
        }

        if (j == 0) {
            cout << operands[0] << endl;
        } else {
            j -= 1;
            i -= 1;
            while (j != -1) {
                res = MathOperations(operands[i - 1], operands[i], OperationType(operators[j]));
                operands[i - 1] = res;
                j -= 1;
                i -= 1;
            }
            cout << operands[0] << endl;
        }
        input.close();
    }
    delete[] operands;
    delete[] operators;
}