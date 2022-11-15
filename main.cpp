#include <iostream>
#include <cstdio>
#include <cstring>
#include "functions.h"
using std::cout;
using std::endl;
using std::cerr;
const char* flag[3] = { "--forward", "--reverse","--file" };
int main(int argc, char** argv) {
    if (argc == 1) {
        cerr << "Error: there are no flags" << endl;
    }
    else if (argc == 2) {
        if (!(strcmp(argv[1], flag[0]))) {
            cout << "Enter in common form" << endl;
            read1();
            forward();
        }
        else if (!strcmp(argv[1], flag[1])) {
            cout << "Enter expression in reverse form" << endl;
            read1();
            reverse();
        }
        else cerr << "Wrong flags" << endl;
    }
    else if (argc == 4) {
        if (!strcmp(argv[2], flag[2])) {
            char* name = argv[3];
            if (read2(name) == 1) {
                cout << "Wrong file" << endl;
            }
            else if ((!strcmp(argv[1], flag[0]))) {
                forward();
            }
            else if (!strcmp(argv[1], flag[1])) {
                reverse();
            }
        }

        else {
            cerr << "Wrong flags" << endl;
        }
    }
    else {
        cerr << "Wrong flags" << endl;
    }
}
