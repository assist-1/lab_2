#ifndef CALCULATOR_HEADER_HPP
#define CALCULATOR_HEADER_HPP

#include <iostream>
#include <cstring>
#include <fstream>

struct Symbol {
    char operation; // для чисел поставим "0"
    int value; // для операций поствим 0
};

bool Calculate(Symbol *Operations, Symbol *Values, int &i, int &j);

int GetPriority(char ch);

int ConsoleForwardCalculate();

int FileForwardCalculate(char* filepath);

int ConsoleReverseCalculate();

int FileReverseCalculate(char* filepath);

#endif //CALCULATOR_HEADER_HPP
