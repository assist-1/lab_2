#include <iostream>
#include <cstring>

struct Stack {
	char c;
	Stack *next;
};

void reverse(char* m, int l);
void forward(char *m);
int initialization(char** argv, int file, char* m);
int Priority(char c);
Stack *InChar(Stack *p, char s);
Stack *OutChar(Stack *p, char *s);
int lenght(char *m);

int main(int argc, char** argv) {
	int file = 0;
	int metod = 0;
	char m[1024];
	int l = 0;
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if ((std::strcmp(argv[i], "--file")) == 0) {
				file = 1;
			}
			else if ((std::strcmp(argv[i], "--reverse")) == 0) {
				metod = 1;
			}
			else if ((std::strcmp(argv[i], "--forward")) == 0) {
				metod = 2;
			}
		}
		else if (file) {
			file = i;
		}
	}
	if (metod == 1) {
		if (initialization(argv, file, m)) {
			std::cout << "Input: " << m << std::endl;
			l = lenght(m);
			reverse(m, l);
		}
	}
	else if (metod == 2) {
		if (initialization(argv, file, m)) {
			std::cout << "Input: " << m << std::endl;
			forward(m);
		}
	}
	else {
		std::cout << "Input error 1: Incorrect flags" << "\n"<<std::endl;
	}
	return 0;
}

int initialization(char** argv, int file, char* m) {
	int j = 0;
	if (file != 0) {
		FILE* fp;
		if ((fp = fopen(argv[file], "r")) == NULL) {
			std::cout << "File doesn't exist" << "\n" << std::endl;
		}
		else {
			while ((m[j] = fgetc(fp)) != EOF) {
				j++;
			}
			m[j] = '\0';
			fclose(fp);
		}
	} else {
		std::cin.getline(m, 1024);
		j = 1;
	}
	return j;
}

void forward(char *m) {
	Stack *t;
	Stack *Op = NULL;
	char a, Out[128];
	int k = 0, l = 0;
	while (m[k] != '\0') {
		if (m[k] >= '0' && m[k] <= '9') {
			while (m[k] >= '0' && m[k] <= '9') {
				Out[l++] = m[k];
				k++;
			}
			k--;
			Out[l++] = ' ';
		}
		else if (m[k] == '(') {
			Op = InChar(Op, m[k]);
		}
		else if (m[k] == ')') {
			while ((Op->c) != '(') {
				Op = OutChar(Op, &a);
				if (Op == NULL) {
					a = '\0';
				}
				Out[l++] = a;
				Out[l++] = ' ';
			}
			t = Op;
			Op = Op ->next;
			delete t;
		}
		else if (m[k] == '+' || m[k] == '-' || m[k] == '*' || m[k] == '/') {
			while (Op != NULL && Priority(Op->c) >= Priority(m[k])) {
				Op = OutChar(Op, &a);
				Out[l++] = a;
				Out[l++] = ' ';
			}
			Op = InChar(Op, m[k]);
		}
		k++;
	}
	while (Op != NULL) {
		Op = OutChar(Op, &a);
		Out[l++] = a;
		if (Op != NULL) {
			Out[l++] = ' ';
		}
	}
	Out[l] = '\0';
	reverse(Out, l);
}

void reverse(char *m, int l) {
	std::cout << "Polish: " << m << std::endl;
	double Res[4];
	int k = 0;
	double rez = 0;
	double prom = 0;
	int buf = 0;
	int math = 0;
	for (int i = 0; i < l; i++) {
		if (m[i] >= '0' && m[i] <= '9') {
			buf = i;
			while (m[buf+1] >= '0' && m[buf+1] <= '9') {
				buf++;
			}
			prom = m[buf] - 48;
			i = buf;
			while (m[buf-1] >= '0' && m[buf-1] <= '9') {
				math = m[buf-1] - 48;
				for (int p = 0; p < i - buf + 1; p++) {
					math = 10 * math;
				}
				prom = prom + math;
				buf--;
			}
			Res[k++] = prom;
		} 
		else if (m[i] == '+' || m[i] == '-' || m[i] == '*' || m[i] == '/') {
			switch(m[i]) {
				case '+': rez = Res[k - 2] + Res[k-1]; break;
				case '-': rez = Res[k - 2] - Res[k-1]; break;
				case '*': rez = Res[k - 2] * Res[k-1]; break;
				case '/': rez = Res[k - 2] / Res[k-1]; break;
			}
			Res[k-2] = rez;
			k = k - 1;
		}
	}
	std::cout << "Result: ";
	std::cout.precision(10);
	std::cout << rez << "\n" << std::endl; 
}

int Priority(char c) {
	int prior = 0;
	switch (c) {
		case '*':
			prior = 3;
			break;
		case '/':
			prior = 3;
			break;
		case '+':
			prior = 2;
			break;
		case '-':
			prior = 2;
			break;
		case '(':
			prior = 1;
			break;
	}
	return prior;
}

Stack* InChar(Stack *p, char s) {
	Stack *t = new Stack;
	t->c = s;
	t->next = p;
	return t;
}

Stack* OutChar(Stack *p, char *s) {
	Stack *t = p;
	*s = p->c;
	p = p->next;
	delete t;
	return p;
}

int lenght(char *m) {
	int len = 0, i = 0;
	while (m[i++] != '\0') {
		len++;
	}
	return len;
}