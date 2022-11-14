#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stof;

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

fstack numb;

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

bool isPrior(char a) {
    if ((a == '*') || (a == '/'))
        return true;
    else return false;
}

bool isSign(char a) {
    if ((a == '*') || (a == '/') || (a == '+') || (a == '-'))
        return true;
    else
        return false;
}

float polska(string task)
{
    task += " ";
    string tmpn = "";
    for(char c:task){
        //cout << "now read: " << c << '\n';
        if((isNum(c))||(isNeg(c,tmpn)))
            tmpn += c;
        else{
            if ((c == ' ')&&(tmpn == "-")){
                float tmp2 = numb.top();
                numb.pop();
                float tmp1 = numb.top();
                numb.pop();
                numb.add(tmp1 - tmp2);
                tmpn = "";
                }
            if ((c == ' ')&&(tmpn != "")){
                numb.add(stof(tmpn));
                tmpn = "";
                }
            if(isSign(c)){
                    float tmp2 = numb.top();
                    numb.pop();
                    float tmp1 = numb.top();
                    numb.pop();
                    if (c == '+')
                        numb.add(tmp1 + tmp2);
                    else if (c == '-')
                        numb.add(tmp1 - tmp2);
                    else if (c == '*')
                        numb.add(tmp1 * tmp2);
                    else
                        numb.add(tmp1 / tmp2);
                }
        }
        //cout << "tmpn = " << tmpn << '\n';
        //cout << "top = " << numb.top() << '\n';
    }
    return numb.top();
}

int forward(string task)
{
    cstack sig;
    {
        string v;
        for (char c : task) if (c != ' ') v += c;
        task = v + "+0";
    }
    string tmpn = "";
    bool flag = false;
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
                    cout << "answer: " << forward(line) << '\n';
                }
            }
            f.close();
        }

        else if (flag == "--forward") {
            string task;
            getline(cin, task);
            cout << "answer: " << forward(task) << '\n';
        }

        else if (flag == "--reverse") {
            string task;
            getline(cin, task);
            cout << "answer: " << polska(task) << '\n';
        }
        return EXIT_SUCCESS;
    }
}