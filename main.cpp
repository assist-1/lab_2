#include <iostream>
#include <cstdio>
#include <func.h>
using std::cout;
using std::endl;
using std::cerr;
int main(int argc,char **argv){
    if (argc == 1){
        cerr << "Error: you don't enter flag" << endl;
        Options();
    }
    else if (argc == 2){
        if (argv[1] == "--forward") {
            cout << "Enter in common form" << endl;
            ReadFromCin();
            Forward();
        }
        if (argv[1] == "--reverse"){
            cout << "Enter in Pollish form" << endl;
            ReadFromCin();
            Reverse();
        }
        else cerr << "You entered wrong flag" << endl;
        Options();
    }
    else if (argc == 4){
        if (argv[2] == "--file") {
            char *namefile = argv[3];

            if (ReadFromFile(namefile)){
                if (argv[1] == "--forward"){
                    Forward();
                }
                if (argv[1] == "--reverse"){
                    Reverse();
                }
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
