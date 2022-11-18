#include <iostream>
#include <stack>
#include "convert.h"

using namespace std;

string AddZeros(string s) {
	string output = "";
	s += ' ';
	bool b = true;
    for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (b && ((c == '+') || (c == '-'))) {
			output += '(';
			output += '0';
			output += c;
			i++;
			while ((s[i]>='0' && s[i]<='9') || (s[i]=='.')) {
				output += s[i];
				i++;
				}
			output += ')';
			b = false;
			i--;
			continue;
			}
		b = false;
		if ((c == '(') || (c == '+') || (c == '-') || (c == '*') || (c == '/')) {
			b = true;
			}
		output += c;

		}
	return output;
}

string Convert2postfix(string ss) {
	ss = AddZeros(ss);
    int n = 1;
    string tmp = "";
    string result = "";
    stack<char> st;
    for (int i = 0; i < ss.length(); i++) {
        char c = ss[i];
        if (c == ' ') {
            continue;
        }
        if ((c >= '0') && (c <= '9') || (c == '.')) {
            tmp += c;
        } else {
            if (tmp.length() > 0) {
                result += tmp + " ";
                tmp = "";
                }
        }

        if ((c == '*') || (c == '/')) {
			while (!st.empty()) {
				char cc = st.top();
				if ((cc == '/') || (cc == '*')) {
					st.pop();
					result += cc;
					result += ' ';
				} else {
					break;
				}
			}
            st.push(c);
        }
        if ((c == '+') || (c == '-')) {
            while(!st.empty()) {
                char cc = st.top();
				if ((cc == '*') || (cc == '/') || (cc == '+') || (cc == '-')) {
                    st.pop();
                    result += cc;
					result += ' ';
                } else {
                    break;
                }
            }
            st.push(c);
        }
        if (c == '(') {
            st.push(c);
        }
        if (c == ')') {
            while(!st.empty()) {
                char cc = st.top();
                if (cc != '(') {
                    st.pop();
                    result += cc;
                } else {
                    st.pop();
                    break;
                }
            }
        }

    }
    result += tmp;
    while (!st.empty()) {
        result += st.top();
		result += ' ';
        st.pop();
    }
    return result;
}

