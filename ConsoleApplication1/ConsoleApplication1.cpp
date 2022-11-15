#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stof;

string line[100];

void remake() {
    int j = 0;
    for (int i = 0; i < 100; i++) {
        if (line[i] != "") {
            line[j] = line[i];
            j++;
        }
    }for (int i = j; i < 100; i++) {
        line[i] = "";
    }
}

string get_string(float f) {
    return std::to_string(f);
}

float Polish(int b) {
    if (b == 0) {
        return stof(line[0]);
    }for (int i = 0; i <= b; i++) {
        if (line[i] == "+") {
            line[i] = get_string(stof(line[i - 2]) + stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return Polish(b - 2);
        }
        else if (line[i] == "-") {
            line[i] = get_string(stof(line[i - 2]) - stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return Polish(b - 2);
        }
        else if (line[i] == "*") {
            line[i] = get_string(stof(line[i - 2]) * stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return Polish(b - 2);
        }
        else if (line[i] == "/") {
            line[i] = get_string(stof(line[i - 2]) / stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return Polish(b - 2);
        }
    }
}

class fl_stack {
private:
    int i = 0;
    float list[1000];
public:
    fl_stack() {

    }

    void add(float a) {
        list[i] = a;
        ++i;
    }

    void pop() {
        list[i - 1] = 0;
        --i;
    }

    float top() {
        return list[i - 1];
    }

    int size() {
        return i;
    }
};

class ch_stack {
private:
    int i = 0;
    char list[1000];
public:
    ch_stack() {

    }

    void add(char a) {
        list[i] = a;
        ++i;
    }

    void pop() {
        list[i - 1] = 0;
        --i;
    }

    char top() {
        return list[i - 1];
    }

    int size() {
        return i;
    }
};

fl_stack stackfl;
ch_stack stackchar;

void doing() {
    char sign = stackchar.top();
    stackchar.pop();
    float tmp1, tmp2;
    tmp2 = stackfl.top();
    stackfl.pop();
    tmp1 = stackfl.top();
    stackfl.pop();
    if (sign == '*')
        stackfl.add(tmp1 * tmp2);
    else if (sign == '/')
        stackfl.add(tmp1 / tmp2);
    else if (sign == '+')
        stackfl.add(tmp1 + tmp2);
    else
        stackfl.add(tmp1 - tmp2);
}

int forward(string line){
    {
        string a;
        for (char s : line) if (s != ' ') a += s;
        line = a + "+0";
    }
    string temp = "";
    for (char s : line) {
        if ((s <= '9' && s >= '0') || (s == '-' && temp == "")) {
            temp = temp + s;
        }
        else {
            if (temp != "") {
                stackfl.add(stof(temp));
                temp = "";
            }
            if (s == ')') {
                while (stackchar.top() != '(') {
                    doing();
                }
                stackchar.pop();
            }
            else if (stackchar.size() > 0) {
                if ((stackchar.top() == '*' || stackchar.top() == '/') && s != '(') {
                    doing();
                }
                else {
                    while ((stackchar.top() != '*' && stackchar.top() != '/') && (stackchar.size() > 0) && 
                        (stackchar.top() != '(' && stackchar.top() != ')')) {
                        doing();
                        }
                }
            }
            if (s != ')')
                stackchar.add(s);
        }
    }
    stackfl.add(stof(temp));
    while (stackchar.size() > 0) {
        doing();
    }
    return stackfl.top();
}

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
            string line;
            getline(cin, line);
            cout << forward(line);
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
            cout << Polish(j) << endl;
        }
        return EXIT_SUCCESS;
    }
}