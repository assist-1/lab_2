#include<iostream>
#include<string>
#include <fstream>
#include "cac.h"
using std::string;
using std::ifstream;
using std::cout;
using std::cin;

int infix();
int opn();
int main(int argc, char* argv[])
{
    string line;
    string flag1 = "--forward";
    string flag2 = "--reverse";
    string flag3 = "--file";
    if (argc != 1){
    if(!flag1.compare(argv[1]))
    {
        cin >> line;
        str = line.c_str();
        int result = infix();
        cout << result;
    }
    else if (!flag2.compare(argv[1]))
    {
        getline(cin, line);
        char * writable = new char[line.size() + 1];
        std::copy(line.begin(), line.end(), writable);
        writable[line.size()] = '\0';
        str = writable;
        int result = opn();
        cout << result;
        delete[] writable;
    }
    else if (!flag3.compare(argv[1]))
    {
          ifstream myfile (argv[3]);
          if(!flag1.compare(argv[2]))
            {
            if (myfile.is_open())
            {
                 while (getline(myfile,line))
                {
                 str = const_cast<char*>(line.c_str());
                 int result = infix();
                 cout << result << std::endl;
                }
                 myfile.close();
            }
            else cout << "Unable to open file";
            }
          else if (!flag2.compare(argv[2]))
            {
             if (myfile.is_open())
            {
                 while (getline(myfile,line))
                {
                 char * writable = new char[line.size() + 1];
                 std::copy(line.begin(), line.end(), writable);
                 writable[line.size()] = '\0';
                 str = writable;
                 int result = opn();
                 cout << result << std::endl;
                 delete[] writable;
                }
                 myfile.close();
            }
            else cout << "Unable to open file";
            }
    }
    }
    else
    {
        cout <<"Nothing was read";
    }
    return 0;
}
