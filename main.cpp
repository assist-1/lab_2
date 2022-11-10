#include <string>
#include <iostream>
#include <cstring>
#include "forward.h"
#include "reverse.h"
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::string;
using std::getline;

#define flag1 "--forward"
#define flag2 "--reverse"
#define flag3 "-c"
#define flag4 "-f"

extern const char* str;

int main(int argc, char* argv[]){
    string line;
    cin >> line;
    if (argc > 4){
        cout << "Wrong input!";
        return 0;
    }
    else{
        if (strcmp(argv[1], flag3) == 0){
            if (strcmp(argv[2], flag1) == 0){
                str = line.c_str();
                int result = expression();
                cout << result << endl;
            }
            else if (strcmp(argv[2], flag2) == 0){
                str = line.c_str();
                int result = opn();
                cout << result;
            }
            else{
                cout << "Wrong input!";
            }
        }
        else if (strcmp(argv[1], flag4) == 0){
            ifstream dataf(argv[3]);
            if (!dataf.is_open()){
                cout << "File can't be opened!";
            }
            else{
                if (strcmp(argv[2], flag1) == 0){
                    while (getline(dataf,line))
                   {
                    str = const_cast<char*>(line.c_str());
                    int result = expression();
                    cout << result << std::endl;
                   }
                    dataf.close();
                }
                else if (strcmp(argv[2], flag2) == 0){
                    getline(dataf, line);
                    char * writable = new char[line.size() + 1];
                    std::copy(line.begin(), line.end(), writable);
                    writable[line.size()] = '\0';
                    str = writable;
                    int result = opn();
                    cout << result << std::endl;
                    delete[] writable;
                    dataf.close();
                }
                else{
                    cout << "Wrong input1!";
                }
            }
        }
        else{
             cout << "Wrong input!";
        }
    }
    return 0;
}
