#include"Lab2.h"
#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;




// 4 6 9 * + 6 +
// 4 + 6 * 9 + 6
// 64 
//file.txt
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    if (argc > 2) {
        std::cout << "������";
        return 0;
    }
    std::string str;
    if (!strcmp(argv[1], "--forward")) {
        std::cout << "������� ���������: " << std::endl;
        getline(cin, str);
        Forward(str);
    }
    else if (!strcmp(argv[1], "--reverse")) {
        std::cout << "������� ���������: " << std::endl;
        getline(cin, str);
        Reverse(str);
    }
    else if (!strcmp(argv[1], "--file")) {
        std::cout << "������� ���������: " << std::endl;
        getline(cin, str);
        ForwardFile(str);
    }
    else {
        std::cout << "�� ������� ���-�� �� ��))) " << std::endl;
    }
    return 0;
}

