#include <iostream>
#include <cstdio>
#include "func.h"
#include <cstring>
using std::cout;
using std::endl;
using std::cerr;
const char* flag[3] = {"--forward", "--reverse","--file"};
int main(int argc,char **argv){
    if (argc == 1){
        cerr << "Error: you don't enter flag" << endl;
        Options();
    }
    else if (argc == 2){
        if (!(strcmp(argv[1],flag[0]))) {
            cout << "Enter in common form" << endl;
            ReadFromCin();
            Forward();
        }
        else if (!strcmp(argv[1],flag[1])){
            cout << "Enter in Pollish form" << endl;
            ReadFromCin();
            Reverse();
        }
        else cerr << "You entered wrong flag" << endl;
        Options();
    }
    else if (argc == 4){
        if (!strcmp(argv[2],flag[2])) {
            char *namefile = argv[3];

            if (ReadFromFile(namefile) == 1){
                cout << "Wrong file read" << endl;
                }
            else if ((!strcmp(argv[1],flag[0]))){
                    Forward();
                }
            else if (!strcmp(argv[1],flag[1])){
                    Reverse();
                }
            }

        else {
            cerr << "Wrong flags" << endl;
            Options();
        }
    }
    else {
        cerr << "Wrong flags" << endl;
        Options();
    }
}
