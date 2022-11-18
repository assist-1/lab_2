#include <iostream>
#include <stack>
using namespace std;

double Evaluate(string postf) {
	postf += ' ';
	stack<double> st;
	double tmp = 0;
	int cl = 0;
	bool p = false; 
	double dap = 0.1;
	for (int i = 0; i < postf.length(); i++) {
		char c = postf[i];
		if (!p && ((c >= '0') && (c <= '9'))) {
			tmp = 10*tmp + (c - '0');
			cl++;
			}
		if (p && ((c >= '0') && (c <= '9'))) {
			tmp = tmp + dap * (c - '0');
			dap *= 0.1;
			}
		if (c == '.') {
			if (p) {
				cout << "Wrong number" << '\n';
				return 0;
				}
			p = !p;
			}
		if (c == ' ') {
			if (cl > 0) {
				st.push(tmp);
				tmp = 0;
				cl = 0;
				p = false;
				dap = 0.1;
				}
			}
		if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
			if (cl > 0) {
				st.push(tmp);
				tmp = 0;
				cl = 0;
				}
			double x = st.top();
			st.pop();
			double y = st.top();
			st.pop();
			double z;
			if (c == '+') {
				z = x + y;
				}
			if (c == '-') {
				z = y - x;
				}
			if (c == '*') {
				z = x * y;
				}
			if (c == '/') {
				z = y / x;
				}
			st.push(z);
			}
		}
	return st.top();
}
