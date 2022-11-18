#include <iostream>
#include <cstring>

using namespace std;

char* AddStr(char* s1, char* s2, int n) {
    char* sre = new char[strlen(s1) + strlen(s2) + 1];
    strncpy(sre, s2, n);
    strcat(sre, " ");
    strcat(sre, s1);
    return sre;
}

int main() 
{
    const char* str = "Hello my beautiful world";
    char* strch = new char[strlen(str) + 1];
    strcpy(strch, str);
    char* output = new char[strlen(str) + 1];
    int i = 0;
    while (i < strlen(strch)) {
        if (strch[i] != ' ') {
            i++;
            continue;
        }
        
        output = AddStr(output, strch, i);
        strch += i + 1;
        i = 0;
    }
    output = AddStr(output, strch, strlen(strch));

    cout << output<< endl;
    return 0;
}