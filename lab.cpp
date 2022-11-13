#include <iostream>
#include <math.h>

struct Stack {
	char c;
	Stack *next;
};

void reverse(char* m, int l);
void forward(char *m);
void initialization(char** argv, int file, char* m);
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
			if (argv[i][3] == 'i') {
				file = 1;
			}
			else if (argv[i][2] == 'r') {
				metod = 1;
			}
			else if (argv[i][3] == 'o') {
				metod = 2;
			}
		}
		else if (file) {
			file = i;
		}
	}
	if (metod == 1) {
		initialization(argv, file, m);
		l = lenght(m);
		std::cout << "Input: " << m << std::endl;
		reverse(m, l);
	}
	else if (metod == 2) {
		initialization(argv, file, m);
		std::cout << "Input: " << m << std::endl;
		forward(m);
	}
	else {
		std::cout << "Input error 1" << std::endl;
	}
	return 0;
}

void initialization(char** argv, int file, char* m) {
	int j = 0;
	if (file != 0) {
		FILE* fp;
		if ((fp = fopen(argv[file], "r")) == NULL) {
			std::cout << "File doesn't exist" << std::endl;
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
	}
}

void forward(char *m) {
	Stack *t;
	Stack *Op = NULL;
	char a, Out[128];
	int k = 0, l = 0;
	while (m[k] != '\0') {
		if (m[k] >= '0' && m[k] <= '9') {
			Out[l++] = m[k];
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
			}
			t = Op;
			Op = Op ->next;
			delete t;
		}
		else if (m[k] == '+' || m[k] == '-' || m[k] == '*' || m[k] == '/' || m[k] == '^') {
			while (Op != NULL && Priority(Op->c) >= Priority(m[k])) {
				Op = OutChar(Op, &a);
				Out[l++] = a;
			}
			Op = InChar(Op, m[k]);
		}
		k++;
	}
	while (Op != NULL) {
		Op = OutChar(Op, &a);
		Out[l++] = a;
	}
	Out[l] = '\0';
	reverse(Out, l);
}

void reverse(char *m, int l) {
	std::cout << "Polish: " << m << std::endl;
	double Res[4];
	int k = 0;
	double rez = 0;
	for (int i = 0; i < l; i++) {
		if (m[i] >= '0' && m[i] <= '9') {
			Res[k++] = (int)m[i] - 48;
		} 
		else if (m[i] == '+' || m[i] == '-' || m[i] == '*' || m[i] == '/' || m[i] == '^') {
			switch(m[i]) {
				case '+': rez = Res[k - 2] + Res[k-1]; break;
				case '-': rez = Res[k - 2] - Res[k-1]; break;
				case '*': rez = Res[k - 2] * Res[k-1]; break;
				case '/': rez = Res[k - 2] / Res[k-1]; break;
				case '^': rez = pow(Res[k - 2],Res[k-1]); break;
			}
			Res[k-2] = rez;
			k = k - 1;
		}
	}
	std::cout << "Result: " << rez << std::endl; 
}

int Priority(char c) {
	int prior = 0;
	switch (c) {
		case '^':
			prior = 4;
			break;
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