#include <iostream>
#include <cstdio>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
const int lengs = 300;
char vyr[lengs];
void read1() {
    cin.read(vyr, lengs - 1);
    int s = cin.gcount();
    vyr[s] = '\0';
}
int read2(char* name) {
    ifstream file(name);
    char sym;
    int i = 0;
    if (file.is_open()) {
        while (file >> sym) {
            vyr[i] = sym;
            i++;
        }
        file.close();
        return 0;
    }
    return 1;

}
int digit(char c) {
    if (c >= '0' && c <= '9') return 1;
    return 0;
}
int oper(char c) {
    if (c == '*' || c == '/' || c == '+' || c == '-') return 1;
    return 0;
}
int priority(char c1, char c2) {
    if ((c2 == '*' || c2 == '/') && (c1 == '+' || c1 == '-')) return 1;
    else if ((c2 == '*' || c2 == '/') && (c1 == '*' || c1 == '/')) return 1;
    else if ((c2 == '+' || c2 == '-') && (c1 == '+' || c1 == '-')) return 1;
    else return 0;
}
int answer(int c1, int c2, char operation) {
    if (operation == '*') return c1 * c2;
    if (operation == '-') return c1 - c2;
    if (operation == '+') return c1 + c2;
    if (operation == '/') return c1 / c2;
    else return -1;
}
int zero(char a) {
    if (a == '0') { return 1; }
    else { return 0; }
}

int forward() {
    char syms[600];
    int nums[600];
    int c1, c2;
    char operation;
    int inums = 0, isyms = 0;
    int ivyr = 0;
    char token = vyr[0];
    while (token = vyr[ivyr]) {
        ivyr++;
        if (vyr[ivyr - 1] == '/' && zero(vyr[ivyr])) {
            std::cerr << "Error: division by zero" << endl;
            exit(1);
        }
        if (digit(token)) {
            c1 = token - '0';
            while (digit(vyr[ivyr])) {
                token = vyr[ivyr];
                ivyr++;
                c1 = 10 * c1 + token - '0';
            }
            nums[inums] = c1;
            inums++;
        }
        else if (oper(token)) {
            while (isyms != 0 && priority(token, syms[isyms - 1])) {
                isyms--;
                operation = syms[isyms];
                inums--;
                c1 = nums[inums];
                inums--;
                c2 = nums[inums];
                nums[inums] = answer(c2, c1, operation);
                inums++;
            }
            syms[isyms] = token;
            isyms++;
        }
        else if (token == '(') {
            syms[isyms] = token;
            isyms++;
        }
        else if (token == ')') {
            while (syms[isyms - 1] != '(') {
                isyms--;
                operation = syms[isyms];
                inums--;
                c1 = nums[inums];
                inums--;
                c2 = nums[inums];
                nums[inums] = answer(c2, c1, operation);
                inums++;
            }
            isyms--;
        }
    }
    while (isyms != 0) {
        isyms--;
        operation = syms[isyms];
        inums--;
        c1 = nums[inums];
        inums--;
        c2 = nums[inums];
        nums[inums] = answer(c2, c1, operation);
        inums++;
    }
    cout << "The answer is " << nums[--inums] << endl;
    return 0;
}
int reverse() {
    int nums[600];
    int c1, c2;
    char operation;
    int inums = 0, isyms = 0;
    int ivyr = 0;
    char token = vyr[0];
    while (token = vyr[ivyr]) {
        ivyr++;
        if (digit(token)) {
            c1 = token - '0';
            nums[inums] = c1;
            inums++;
        }
        if (oper(token)) {
            operation = token;
            inums--;
            c1 = nums[inums];
            inums--;
            c2 = nums[inums];
            nums[inums] = answer(c2, c1, operation);
            inums++;
        }
    }
    cout << "The answer is " << nums[0] << endl;
    return 0;
}
