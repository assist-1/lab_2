#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;


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
            if ((c == '(')) {

            }
            else if ((c == ')')) {
                while ((sig.top() == '(')) == false) {
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
                if (((sig.top() == '*') || (sig.top() == '/'))) {
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
                    if ((((c == '*') || (c == '/'))) == false) {
                        while ((((sig.top() == '*') || (sig.top() == '/')) == false) && (sig.size() > 0) && (((sig.top() == '(') || (sig.top() == ')') == false)) {
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