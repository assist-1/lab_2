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

class fstack {
private:
    int i = 0;
    float task[1000];
public:
    fstack() {

    }

    void add(float a) {
        task[i] = a;
        ++i;
    }

    void pop() {
        task[i - 1] = 0;
        --i;
    }

    float top() {
        return task[i - 1];
    }

    int size() {
        return i;
    }
};

class cstack {
private:
    int i = 0;
    char task[1000];
public:
    cstack() {

    }

    void add(char a) {
        task[i] = a;
        ++i;
    }

    void pop() {
        task[i - 1] = 0;
        --i;
    }

    char top() {
        return task[i - 1];
    }

    int size() {
        return i;
    }
};

bool isOpened(char a) {
    if (a == '(')
        return true;
    return false;
}

bool isClosed(char a) {
    if (a == ')')
        return true;
    return false;
}


bool isNum(char a) {
    if ((a >= '0') && (a <= '9'))
        return true;
    else
        return false;
}

bool isNeg(char a, string b) {
    if ((a == '-') && (b == "")) {
        return true;
    }
    else
        return false;
}

bool isBracket(char a) {
    if ((a == '(') || (a == ')'))
        return true;
    return false;
}

bool func(char a) {
    if ((a == '*') || (a == '/'))
        return true;
    else return false;
}

bool operation(char a) {
    if ((a == '*') || (a == '/') || (a == '+') || (a == '-'))
        return true;
    else
        return false;
}

int forward(string task)
{
    fstack stackfl;
    cstack stackchar;
    {
        string a;
        for (char c : task) if (c != ' ') a += c;
        task = a + "+0";
    }
    string tmpn = "";
    for (char c : task) {
        if ((isNum(c)) || (isNeg(c, tmpn))) {
            tmpn = tmpn + c;
        }
        else {
            if (tmpn != "") {
                stackfl.add(stof(tmpn));
                tmpn = "";
            }
            if (isOpened(c)) {

            }
            else if (isClosed(c)) {
                while (isOpened(stackchar.top()) == false) {
                    float tmp1, tmp2;
                    tmp2 = stackfl.top();
                    stackfl.pop();
                    tmp1 = stackfl.top();
                    stackfl.pop();
                    if (stackchar.top() == '*')
                        stackfl.add(tmp1 * tmp2);
                    else if (stackchar.top() == '/')
                        stackfl.add(tmp1 / tmp2);
                    else if (stackchar.top() == '+')
                        stackfl.add(tmp1 + tmp2);
                    else
                        stackfl.add(tmp1 - tmp2);
                    stackchar.pop();
                }
                stackchar.pop();
            }
            else if (stackchar.size() > 0) {
                if (func(stackchar.top())) {
                    float tmp1, tmp2;
                    tmp2 = stackfl.top();
                    stackfl.pop();
                    tmp1 = stackfl.top();
                    stackfl.pop();;
                    if (stackchar.top() == '*')
                        stackfl.add(tmp1 * tmp2);
                    else
                        stackfl.add(tmp1 / tmp2);
                    stackchar.pop();
                }
                else {
                    if (func(c) == false) {
                        while ((func(stackchar.top()) == false) && (stackchar.size() > 0) && (isBracket(stackchar.top()) == false)) {
                            float tmp1, tmp2;
                            tmp2 = stackfl.top();
                            stackfl.pop();
                            tmp1 = stackfl.top();
                            stackfl.pop();
                            if (stackchar.top() == '+')
                                stackfl.add(tmp1 + tmp2);
                            else
                                stackfl.add(tmp1 - tmp2);
                            stackchar.pop();

                        }
                    }
                }
            }
            if (c != ')')
                stackchar.add(c);
        }
    }
    stackfl.add(stof(tmpn));
    while (stackchar.size() > 0) {
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
            cout << Polish(j) << endl;
        }
        return EXIT_SUCCESS;
    }
}