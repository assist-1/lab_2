#include <iostream>
#include "Header.h"
#include <fstream>


void Forward(void) {
	std::cout << "Введите выражения с использованием символов *,/,+,-." << std::endl;
	std::cout << "В конце введите '='" << std::endl;
	char str1[1000];
	double str2[1000];
	char s = '-';
	int i = 0, p=0;
	for (i = 0; i < 1000; i++) {
		if (i % 2 == 0) std::cin >> str2[i];
		else std::cin >> str1[i];
		if (str1[i] == '=') break;
		p += 1;
	}
	char f1[1000];
	double f11[1000];
	char f2[1000]; double f21[1000]; double f31[1000]; double f41[1000];
	char f3[1000];
	char f4[1000];
	for (i = 0; i < p; i++) {
			if (i >= 1 && str1[i] == '*') {
			f11[i] = Mult(str2[i - 1], str2[i + 1]);
			str2[i + 1] = f11[i];
			str2[i - 1] = f11[i];
		}
			}
	for (i = 0; i < 1000; i++) {
		if (i>=1 && str1[i] == '/') {
			f21[i] = Div(str2[i-1],str2[i+1]);
			str2[i + 1] = f21[i];
			str2[i - 1] = f21[i];
		}
	}
	double tmp;
	int t = 0;
	for (i = 0; i < p; i++) {
		if (i >= 1 && str1[i] == '+') {
			if (t == 0) f31[i] = Summ(str2[i - 1], str2[i + 1]);
			else f31[i] = Summ(tmp, str2[i + 1]);
			tmp = f31[i];
			t += 1;
			str2[i + 1] = f31[i];
			str2[i - 1] = f31[i];
		}
		if (i >= 1 && str1[i] == '-') {
			if (t == 0) f41[i] = Sub(str2[i - 1], str2[i + 1]);
			else f41[i] = Sub(tmp, str2[i + 1]);
			tmp = f41[i];
			t += 1;
			str2[i + 1] = f41[i];
			str2[i - 1] = f41[i];
		}
	}
	str2[p - 1] = tmp;
		std::cout << str2[p - 1] << std::endl;
	return;
}

void Reverse() {
	std::cout << "Введите выражение ОПН с использованием символов *,/,+,-" << std::endl;
	std::cout << "В конце введите '='" << std::endl;
	char str1[1000] = {' '};
	double str2[1000];
	int i = 0;
	int h = 0;
	for (i = 0; i < 1000;i++) {
		if (i!=0 && i % 2 == 0) std::cin >> str1[i];
		else std::cin >> str2[i];
		if (str2[i] == '=') break;
		h += 1;
	}
	int g;
	double p = str2[0];
	for (g = 1; g <= h; g++) {
		if (str1[g] == '+') {
			p = Summ(p, str2[g-1]);
		}
		if (str1[g] == '*') {
			p = Mult(p, str2[g-1]);
		}
		if (str1[g] == ':') {
			p = Div(p, str2[g-1]);
		}
		if (str1[g] == '-') {
			p = Sub(p, str2[g-1]);
		}
	}
	std::cout << p << std::endl;
	return;
}
void Forward1(void) {
	std::ifstream fin("text.txt");
	char str1[1000];
	double str2[1000];
	char s = '-';
	int i = 0, p = 0;
	for (i = 0; i < 1000; i++) {
		if (i % 2 == 0) fin >> str2[i];
		else fin >> str1[i];
		if (str1[i] == '=') break;
		p += 1;
	}
	char f1[1000];
	double f11[1000];
	char f2[1000]; double f21[1000]; double f31[1000]; double f41[1000];
	char f3[1000];
	char f4[1000];
	for (i = 0; i < p; i++) {
		if (i >= 1 && str1[i] == '*') {
			f11[i] = Mult(str2[i - 1], str2[i + 1]);
			str2[i + 1] = f11[i];
			str2[i - 1] = f11[i];
		}
	}
	for (i = 0; i < 1000; i++) {
		if (i >= 1 && str1[i] == '/') {
			f21[i] = Div(str2[i - 1], str2[i + 1]);
			str2[i + 1] = f21[i];
			str2[i - 1] = f21[i];
		}
	}
	double tmp;
	int t = 0;
	for (i = 0; i < p; i++) {
		if (i >= 1 && str1[i] == '+') {
			if (t == 0) f31[i] = Summ(str2[i - 1], str2[i + 1]);
			else f31[i] = Summ(tmp, str2[i + 1]);
			tmp = f31[i];
			t += 1;
			str2[i + 1] = f31[i];
			str2[i - 1] = f31[i];
		}
		if (i >= 1 && str1[i] == '-') {
			if (t == 0) f41[i] = Sub(str2[i - 1], str2[i + 1]);
			else f41[i] = Sub(tmp, str2[i + 1]);
			tmp = f41[i];
			t += 1;
			str2[i + 1] = f41[i];
			str2[i - 1] = f41[i];
		}
	}
	str2[p - 1] = tmp;
	std::cout << str2[p - 1] << std::endl;

	return;
}

void Reverse1() {
	std::ifstream fin("text.txt");
	char str1[1000] = { ' ' };
	double str2[1000];
	int i = 0;
	int h = 0;
	for (i = 0; i < 1000; i++) {
		if (i != 0 && i % 2 == 0) fin >> str1[i];
		else fin >> str2[i];
		if (str2[i] == '=') break;
		h += 1;
	}
	int g;
	double p = str2[0];
	for (g = 1; g <= h; g++) {
		if (str1[g] == '+') {
			p = Summ(p, str2[g - 1]);
		}
		if (str1[g] == '*') {
			p = Mult(p, str2[g - 1]);
		}
		if (str1[g] == ':') {
			p = Div(p, str2[g - 1]);
		}
		if (str1[g] == '-') {
			p = Sub(p, str2[g - 1]);
		}
	}
	std::cout << p << std::endl;
	return;
}