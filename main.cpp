#include <iostream>
#include <fstream>
#include "Functions.h"

int main(int argc, char **argv) {
    if ((argc < 2) || (argc > 3)) {
        std::cerr << "Enter the '--forward' or '--reverse' \n";
        return 0;
    }
    if ((strcmp(argv[1], "--forward") == 1 && strcmp(argv[1], "--reverse")) == 1) {
        std::cerr << "Wrong command, try again \n";
        return 0;
    }

    if (argc == 3){
        if (strcmp(argv[1], "--file") == 1)
            std::cerr << "Wrong command, try again";
        char Ch;
        std::ifstream fin;
        fin.open("/Users/semyonzotov/laba2/test.txt ");
        double value;
        bool flag = true;
        Stack<Term> Stack_value;
        Stack<Term> Stack_operate;
        Term obj;
        while (!fin.eof()) {
            Ch = fin.peek();
            if (Ch == '\n' || Ch == EOF)break;
            if (Ch == ' ') {
                fin.ignore();
                continue;
            }
            if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) {
                fin >> value;
                obj.type = '0';
                obj.value = value;
                Stack_value.Push(obj);
                flag = false;
                continue;
            }
            if (Ch == '+' || Ch == '-' && flag == true || Ch == '*' || Ch == '/') {
                if (Stack_operate.Size() == 0) {
                    obj.type = Ch;
                    obj.value = 0;
                    Stack_operate.Push(obj);
                    fin.ignore();
                    continue;
                }
                if (Stack_operate.Size() != 0 && Value(Ch) > Value(Stack_operate.Top().type)) {
                    obj.type = Ch;
                    obj.value = 0;
                    Stack_operate.Push(obj);
                    fin.ignore();
                    continue;
                }
                if (Stack_operate.Size() != 0 && Value(Ch) <= Value(Stack_operate.Top().type)) {
                    if (Oper(Stack_value, Stack_operate, obj) == false) {
                        return 0;
                    }
                    continue;
                }
            }
            if (Ch == '(') {
                obj.type = Ch;
                obj.value = 0;
                Stack_operate.Push(obj);
                fin.ignore();
                continue;
            }
            if (Ch == ')') {
                while (Stack_operate.Top().type != '(') {
                    if (Oper(Stack_value, Stack_operate, obj) == false) {
                        return 0;
                    } else continue;
                }
                Stack_operate.Pop();
                fin.ignore();
                continue;
            } else {
                std::cout << "Wrong expression!\n";
                return 0;
            }
        }
        while (Stack_operate.Size() != 0) {
            if (Oper(Stack_value, Stack_operate, obj) == false) {
                return 0;
            }
            else continue;
        }
        std::cout << Stack_value.Top().value << std::endl;
        return 0;
        fin.close();
    }

    if (strcmp(argv[1], "--forward") == 0) {
        char Ch;
        double value;
        bool flag = 1;
        Stack<Term> Stack_value;
        Stack<Term> Stack_operate;
        Term obj;
        while (true) {
            Ch = std::cin.peek();
            if (Ch == '\n' || Ch == EOF)break;
            if (Ch == ' ') {
                std::cin.ignore();
                continue;
            }
            if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) {
                std::cin >> value;
                obj.type = '0';
                obj.value = value;
                Stack_value.Push(obj);
                flag = 0;
                continue;
            }
            if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/') {
                if (Stack_operate.Size() == 0) {
                    obj.type = Ch;
                    obj.value = 0;
                    Stack_operate.Push(obj);
                    std::cin.ignore();
                    continue;
                }
                if (Stack_operate.Size() != 0 && Value(Ch) > Value(Stack_operate.Top().type)) {
                    obj.type = Ch;
                    obj.value = 0;
                    Stack_operate.Push(obj);
                    std::cin.ignore();
                    continue;
                }
                if (Stack_operate.Size() != 0 && Value(Ch) <= Value(Stack_operate.Top().type)) {
                    if (Oper(Stack_value, Stack_operate, obj) == false) {
                        return 0;
                    }
                    continue;
                }
            }
            if (Ch == '(') {
                obj.type = Ch;
                obj.value = 0;
                Stack_operate.Push(obj);
                std::cin.ignore();
                continue;
            }
            if (Ch == ')') {
                while (Stack_operate.Top().type != '(') {
                    if (Oper(Stack_value, Stack_operate, obj) == false) {
                        return 0;
                    } else continue;
                }
                Stack_operate.Pop();
                std::cin.ignore();
                continue;
            } else {
                std::cout << "Wrong expression!\n";
                return 0;
            }
        }
        while (Stack_operate.Size() != 0) {
            if (Oper(Stack_value, Stack_operate, obj) == false) {
                return 0;
            }
            else continue;
        }
        std::cout << Stack_value.Top().value << std::endl;
        return 0;
    }
    if (strcmp(argv[1], "--reverse") == 0) {
        Stack<double> stack;
        bool flag = true;
        char Ch;
        do{
            while(Ch = std::cin.peek(), Ch == ' ' || Ch == '\t') {
                std::cin.ignore();
            }
            if(Ch == EOF || Ch == '\n' || Ch == '=') {
                break;
            }
            else {
                double m;
                std::cin >> m;
                if(std::cin.fail()) {
                    double s1, s2;
                    s2 = stack.Top();
                    stack.Pop();
                    s1 = stack.Top();
                    stack.Pop();
                    switch (Ch) {
                        case '+':
                            s1 += s2;
                            break;
                        case '-':
                            s1 -= s2;
                            break;
                        case '*':
                            s1 *= s2;
                            break;
                        case '/':
                            s1 /= s2;
                            break;
                        default:
                            break;
                    }
                    stack.Push(s1);
                    std::cin.clear();
                    if(Ch=std::cin.peek(), Ch!=EOF && Ch!= '\n'){
                        std::cin.get();
                    }
                }
                else {
                    stack.Push(m);
                }
            }
        } while(flag);

        std::cout << stack.Top() << std::endl;

        return 0;
    }
}