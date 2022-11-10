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

float OPN(int b) {
    if (b == 0) {
        return stof(line[0]);
    }for (int i = 0; i <= b; i++) {
        if (line[i] == "+") {
            line[i] = std::to_string(stof(line[i - 2]) + stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return OPN(b - 2);
        }
        else if (line[i] == "-") {
            line[i] = std::to_string(stof(line[i - 2]) - stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return OPN(b - 2);
        }
        else if (line[i] == "*") {
            line[i] = std::to_string(stof(line[i - 2]) * stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return OPN(b - 2);
        }
        else if (line[i] == "/") {
            line[i] = std::to_string(stof(line[i - 2]) / stof(line[i - 1]));
            line[i - 2] = "";
            line[i - 1] = "";
            remake();
            return OPN(b - 2);
        }
    }
}

class flopstack {
private:
    int i = 0;
    float task[1000];
public:
    flopstack() {

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

class chastack {
private:
    int i = 0;
    char task[1000];
public:
    chastack() {

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

bool isPrior(char a) {
    if ((a == '*') || (a == '/'))
        return true;
    else return false;
}


int forward(string task)
{
    flopstack numb;
    chastack sig;
    {
        string v;
        for (char c : task) if (c != ' ') v += c;
        task = v + "+0";
    }
    string tmpn = "";
    for (char c : task) {
        if ((isNum(c)) || (isNeg(c, tmpn))) {
            tmpn = tmpn + c;
        }
        else {
            if (tmpn != "") {
                numb.add(stof(tmpn));
                tmpn = "";
            }
            if (isOpened(c)) {

            }
            else if (isClosed(c)) {
                while (isOpened(sig.top()) == false) {
                    float tmp1, tmp2;
                    tmp2 = numb.top();
                    numb.pop();
                    tmp1 = numb.top();
                    numb.pop();
                    if (sig.top() == '*')
                        numb.add(tmp1 * tmp2);
                    else if (sig.top() == '/')
                        numb.add(tmp1 / tmp2);
                    else if (sig.top() == '+')
                        numb.add(tmp1 + tmp2);
                    else
                        numb.add(tmp1 - tmp2);
                    sig.pop();
                }
                sig.pop();
            }
            else if (sig.size() > 0) {
                if (isPrior(sig.top())) {
                    float tmp1, tmp2;
                    tmp2 = numb.top();
                    numb.pop();
                    tmp1 = numb.top();
                    numb.pop();;
                    if (sig.top() == '*')
                        numb.add(tmp1 * tmp2);
                    else
                        numb.add(tmp1 / tmp2);
                    sig.pop();
                }
                else {
                    if (isPrior(c) == false) {
                        while ((isPrior(sig.top()) == false) && (sig.size() > 0) && (isBracket(sig.top()) == false)) {
                            float tmp1, tmp2;
                            tmp2 = numb.top();
                            numb.pop();
                            tmp1 = numb.top();
                            numb.pop();
                            if (sig.top() == '+')
                                numb.add(tmp1 + tmp2);
                            else
                                numb.add(tmp1 - tmp2);
                            sig.pop();

                        }
                    }
                }
            }
            if (c != ')')
                sig.add(c);
        }
    }
    numb.add(stof(tmpn));
    while (sig.size() > 0) {
        char sign = sig.top();
        sig.pop();
        float tmp1, tmp2;
        tmp2 = numb.top();
        numb.pop();
        tmp1 = numb.top();
        numb.pop();
        if (sign == '*')
            numb.add(tmp1 * tmp2);
        else if (sign == '/')
            numb.add(tmp1 / tmp2);
        else if (sign == '+')
            numb.add(tmp1 + tmp2);
        else
            numb.add(tmp1 - tmp2);
    }
    return numb.top();
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
            cout << OPN(j) << endl;
        }
        return EXIT_SUCCESS;
    }
}