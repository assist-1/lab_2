#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include "forward.h"
#include "reverse.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::string;
using std::getline;
using std::copy;

#define flag1 "-c"
#define flag2 "-f"
#define flag3 "--forward"
#define flag4 "--reverse"

int forward();
int reverse();

int main(int argc, char* argv[]){
    string raw_data;
    if (argc > 2 && argc < 5){
        if(strcmp(flag1, argv[1]) == 0){
            if (strcmp(flag3, argv[2]) == 0){
                cout << ">>> Введите выражение: ";
                cin >> raw_data;
                ch =raw_data.c_str();
                int answer = forward();
                cout << ">>> Ответ: " << answer;
            }
            else if(strcmp(flag4, argv[2]) == 0){
                cout << ">>> Введите выражение: ";
                getline(cin, raw_data);
                char * temp = new char[raw_data.size() + 1];
                copy(raw_data.begin(), raw_data.end(), temp);
                temp[raw_data.size()] = '\0';
                ch = temp;
                int answer = reverse();
                cout << ">>> Ответ: " <<  answer;
                delete[] temp;
            }
        }
        else if (strcmp(flag2, argv[1]) == 0){
            if (strcmp(flag3, argv[2]) == 0){
                ifstream datafile (argv[3]);
                if (datafile.is_open()){
                    cout << ">>> Выражение считано с файла " << '[' << argv[3] << ']' << endl;
                    while (getline(datafile,raw_data)){
                        ch = const_cast<char*>(raw_data.c_str());
                        int answer = forward();
                        cout << ">>> Ответ: " << answer << std::endl;
                    }
                datafile.close();
                }
                else cout << "Невозможно открыть файл";
            }
            else if (strcmp(flag4, argv[2]) == 0){
                ifstream datafile (argv[3]);
                if (datafile.is_open()){
                    cout << ">>> Выражение считано с файла " << '[' << argv[3] << ']' << endl;
                    while (getline(datafile,raw_data)){
                        char * temp = new char[raw_data.size() + 1];
                        std::copy(raw_data.begin(), raw_data.end(), temp);
                        temp[raw_data.size()] = '\0';
                        ch = temp;
                        int answer = reverse();
                        cout << ">>> Ответ: " << answer << std::endl;
                        delete[] temp;
                    }
                    datafile.close();
                }
                else cout << ">>> Невозможно открыть файл";
            }
        }
    }
    else{
        cout << ">>> Некорректный ввод";
    }
    return 0;
}
