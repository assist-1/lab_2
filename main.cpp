#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;
using std::cerr;
int main(int argc,char **argv){
    if (argc == 1){
        cerr << "Error: you don't enter flag" << endl;
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
    }
    else if (argc == 4){
        if (argv[2] == "--file") {
            char *namefile = argv[3];
            }
            if ReadFromFile(namefile){
                if (argv[1] == "--forward"){
                    cout << "Enter in common form" << endl;
                    Forward();
                }
                if (argv[2] == "--reverse"){
                    cout << "Enter in Pollish form" << endl;
                    Reverse();
                }
            }
    }
}
