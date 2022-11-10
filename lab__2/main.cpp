#include "header.h"

int main(int argc, char **argv) {
    char sign = ' ';
    int ch, n = 0, p = 0, k;
    int *num = new int[100];
    char *op = new char[100];
    bool fl = 1;
    if (argc == 1) {
        std::cerr << "Please enter your input type: \"--forward\" or \"--reverse\". If "
                     "you want to read from file, enter \"--file\"." << "\n";
        return EXIT_FAILURE;
    } else if (argc == 2 && strcmp(argv[1], "--forward") == 0 || strcmp(argv[1], "--reverse") == 0) {
        std::cout << "Enter your expression \n";
        while (sign != '\n') {
            sign = cin.peek();
            if (sign == ' ') {
                cin.ignore();
                continue;
            }
            if ((sign >= '0' && sign <= '9') || (sign == '-' && fl == 1)) {
                cin >> ch;
                num[n] = ch;
                // std::cout << num[n] << "\n";
                ++n;
                fl = 0;
                continue;
            }
            if (sign == '+' || (sign == '-' && fl == 0) || sign == '*' || sign == '/' ) {
                if (p == 0 || (p != 0 && abs(oper(sign)) > abs(oper(op[p - 1])))) {
                    op[p] = sign;
                    ++p;
                    cin.ignore();
                    continue;
                }
                if (p != 0 && abs(oper(sign)) <= abs(oper(op[p - 1]))) {
                    k = answ(num[n - 1], num[n - 2], op[p - 1]);
                    num[n - 2] = k;
                    --n;
                    --p;
                }
            }
            if (sign == '(') {
                op[p] = sign;
                ++p;
                fl = 1;
                cin.ignore();
                continue;
            }
            if (sign == ')') {
                while (oper(op[p - 1]) != 1) {
                    k = answ(num[n - 1], num[n - 2], op[p - 1]);
                    num[n - 2] = k;
                    --n;
                    --p;
                }
                --p;
                cin.ignore();
                continue;
            }
        }
        while (p != 0) {
            k = answ(num[n - 1], num[n - 2], op[p-1]);
            num[n - 2] = k;
            --n;
            --p;
        }
        std::cout << num[0] << "\n";
    } else if (argc >= 2 && strcmp("--file", argv[2]) == 0) {
        char end = ' ';
        std::ifstream inp(argv[3]);
        cin.rdbuf(inp.rdbuf());
        end = EOF;
        while (sign != end) {
            sign = cin.peek();
            if (sign == ' ') {
                cin.ignore();
                continue;
            }
            if ((sign >= '0' && sign <= '9') || (sign == '-' && fl == 1)) {
                cin >> ch;
                num[n] = ch;
                std::cout << num[n] << "\n";
                ++n;
                fl = 0;
                continue;
            }
            if (sign == '+' || (sign == '-' && fl == 0) || sign == '*' || sign == '/' ) {
                if (p == 0 || (p != 0 && abs(oper(sign)) > abs(oper(op[p - 1])))) {
                    op[p] = sign;
                    ++p;
                    cin.ignore();
                    continue;
                }
                if (p != 0 && abs(oper(sign)) <= abs(oper(op[p - 1]))) {
                    k = answ(num[n - 1], num[n - 2], op[p - 1]);
                    num[n - 2] = k;
                    --n;
                    --p;
                }
            }
            if (sign == '(') {
                op[p] = sign;
                ++p;
                cin.ignore();
                continue;
                fl = 1;
            }
            if (sign == ')') {
                while (oper(op[p - 1]) != 1) {
                    k = answ(num[n - 1], num[n - 2], op[p - 1]);
                    num[n - 2] = k;
                    --n;
                    --p;
                }
                --p;
                cin.ignore();
                continue;
            }
        }
        while (p != 0) {
            k = answ(num[n - 1], num[n - 2], op[p-1]);
            num[n - 2] = k;
            --n;
            --p;
        }
        std::cout << num[0] << "\n";
    }
    delete[] num;
    delete[] op;
    return 0;
}