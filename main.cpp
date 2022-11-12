#include <iostream>
#include <fstream>
#include <string>
#include "forward.h"
#include "reverse.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

string line[100];

int main(int argc, char** argv) {
    if (argc == 1) {
        cerr << "Nothing was read\n";
        return EXIT_FAILURE;
    }

    else {
        string flag = argv[1];

        if (flag == "--file") {
            string adr = argv[2];
            string line;

            std::ifstream f(adr);
            if (f.is_open())
            {
                while (getline(f, line))
                {
                    cout << forward(line) << endl;
                }
            }
            f.close();
        }

        else if (flag == "--forward") {
            string task;
            getline(cin, task);
            cout << forward(task);
        }

        else if (flag == "--reverse") {
            string s;
            int n = 0, j = 0;
            getline(cin, s);
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ') {
                    line[j].assign(s, i - n, n);
                    j++;
                    n = 0;
                }
                else {
                    n++;
                }
            }
            line[j].assign(s, s.length() - 1, 1);
            cout << endl << OPN(j);
        }
        return EXIT_SUCCESS;
    }
}