#include <iostream>
#include <string>
 
#ifndef POLISH_H
#define POLISH_H

using std::string;
using std::stof;

string line[100];

void SDV() {
    int j = 0;
    for (int i = 0; i < 100; i++) {
        if (line[i] != "") {
            line[j] = line[i];
            j++;
        }
    }for (int i = j; i < 100; i++) {
        line[i] = "";
    }
}

string get_string(float f) {
    return std::to_string(f);
}

float OPN(int b) {
    if (b == 0) {
        return stof(line[0]);
    }for (int i = 0; i <= b; i++) {
        if (line[i] == "+") {
            line[i] = std::to_string(stof(line[i - 2]) + stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            SDV();
            return OPN(b - 2);
        }
        else if (line[i] == "-") {
            line[i] = std::to_string(stof(line[i - 2]) - stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            SDV();
            return OPN(b - 2);
        }
        else if (line[i] == "*") {
            line[i] = std::to_string(stof(line[i - 2]) * stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            SDV();
            return OPN(b - 2);
        }
        else if (line[i] == "/") {
            line[i] = std::to_string(stof(line[i - 2]) / stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            SDV();
            return OPN(b - 2);
        }
    }
}
#endif

