#include <iostream>
#include <cstring>
#include <fstream>
#include "function.h"

using std::cin;
using std::cout;

int main(int argc, char **argv) {
    int*  sign = new int [200];
    int*  num = new int [200];
    int n = 0;
    if (EnterCheck(argc) == 0)
        return 0;
    if (EnterExp(argv) == 0)
        return 0;
    if (argc == 3) {
        if (strcmp(argv[1], "--file") == 1)
            std::cerr << "Wrong command, try again";
        char x;
        std::ifstream fin("input.txt");
        int i = 0;
        while (!fin.eof()) {
            x = fin.peek();
            if ( x >= '0' && x <= '9'){
                fin >> num[i];
                sign[i] = 7;
            } else {
                sign[i] = Operator(x);
                num[i] = 0;
                fin.ignore();
            }
            if (x != ' ') ++i;
        }
        fin.close();
        n = i;
    }
    if (argc == 2) {
        cout << "Enter the expression" << std::endl;
        int i = 0;
        while (1){
            char x = cin.peek();
            if (x == '\n') break;
            if ( x >= '0' && x <= '9' ){
                cin >> num[i];
                sign[i] = 7;
            } else {
                sign[i] = Operator(x);
                num[i] = 0;
                cin.ignore();
            }
            if (x != ' ') ++i;
        }
        n = i;
    }
    if (strcmp(argv[1], "--forward") == 0) {
        cout << Resultfor(sign, num, n);
    }
    if (strcmp(argv[1], "--reverse") == 0) {
        cout << Resultrev(sign, num, n);
    }
    delete []sign;
    delete []num;
}