#include <iostream>
#include <stack>
#include <fstream>
#include "convert.h"
#include "evaluate.h"

using namespace std;

int main(int argc, char **argv) {
	string source;
	bool order;
	if (argc < 2) {
		cout << "Не хватает параметров" << '\n';
		return 1;
	}
	if ((string)argv[1] == "--forward") {
		order = true;
	} else {
		if ((string)argv[1] == "--reverse") {
			order = false;
		} else {
			cout << "Формат не задан" << '\n';
			return 1;
		}
	}
	if (argc == 2) {
		cout << "Введите выражение" << '\n';
		getline(cin, source);
	} else {
		if ((string)argv[2] == "--file") {
			if (argc == 3) {
				cout << "Не указано имя файла" << '\n';
				return 1;
			} else {
				ifstream f(argv[3]);
				if (f.is_open()) {
					getline(f, source);
				} else {
					cout << "Не могу открыть файл" << '\n';
					return 1;
				}
			}
		} else {
			cout << "Неправильные параметры";
			return 1;
		}
	}
	if (order) {
		cout << "Starting forward order" << '\n';
		string pstfx = Convert2postfix(source);
    	cout << source << '\n';
		cout << pstfx << '\n';
		cout << Evaluate(pstfx) << '\n' ;
	} else {
		cout << "Starting reverse order" << '\n';
		cout << source << '\n';
		cout << Evaluate(source) << '\n';
	}
}

