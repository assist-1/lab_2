#include "header.hpp"

bool Calculate(Symbol *Operations, Symbol *Values, int &i, int &j) {
    int a;
    int b;
    int c;
    a = Values[i].value;
    switch (Operations[j].operation) {
        case '+':
            b = Values[i - 1].value;
            c = a + b;
            Values[i - 1].value = c;
            Values[i].value = 0;
            Operations[j].operation = '0';
            --i;
            --j;
            break;
        case '-':
            b = Values[i - 1].value;
            c = b - a;
            Values[i - 1].value = c;
            Values[i].value = 0;
            Operations[j].operation = '0';
            --i;
            --j;
            break;
        case '*':
            b = Values[i - 1].value;
            c = a * b;
            Values[i - 1].value = c;
            Values[i].value = 0;
            Operations[j].operation = '0';
            --i;
            --j;
            break;
        case '/':
            if (a == 0) {
                return false;
            }
            b = Values[i - 1].value;
            c = b / a;
            Values[i - 1].value = c;
            Values[i].value = 0;
            Operations[j].operation = '0';
            --i;
            --j;
            break;
        default:
            std::cerr << "Error";
            return false;
    }
    return true;

}

int GetPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        return 0;
    }
}

int ConsoleForwardCalculate() {
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1;
    Symbol item;
    int i = 0;
    int j = 0;
    int value;
    while (1) {
        symbol = std::cin.peek();
        if (symbol == '\n') {
            break;
        }
        if (symbol == ' ') {
            std::cin.ignore();
            continue;
        }
        if (symbol >= '0' && symbol <= '9' || symbol == '-' && flag) {
            std::cin >> value;
            item.operation = '0';
            item.value = value;
            Values[i] = item;
            ++i;
            flag = 0;
            continue;
        }
        if (symbol == '+' || symbol == '-' && !flag || symbol == '*' || symbol == '/') {
            if (Operations[0].operation != '+' && Operations[0].operation != '-' &&
                Operations[0].operation != '*' && Operations[0].operation != '/') {
                item.operation = symbol;
                item.value = 0;
                Operations[j] = item;
                std::cin.ignore();
                ++j;
                continue;
            }
            if ((Operations[0].operation == '+' || Operations[0].operation == '-' ||
                 Operations[0].operation == '*' || Operations[0].operation == '/') &&
                GetPriority(symbol) > GetPriority(Operations[j - 1].operation)) {
                if (symbol == '-' && Operations[j - 1].operation == '(') {
                    Symbol extraItem;
                    extraItem.operation = '0';
                    extraItem.value = 0;
                    Values[i] = extraItem;
                    ++i;
                }
                item.operation = symbol;
                item.value = 0;
                Operations[j] = item;
                std::cin.ignore();
                ++j;
                continue;
            }
            if ((Operations[0].operation == '+' || Operations[0].operation == '-' ||
                 Operations[0].operation == '*' || Operations[0].operation == '/') &&
                GetPriority(symbol) <= GetPriority(Operations[j - 1].operation)) {
                if (!Calculate(Operations, Values, --i, --j)) {
                    system("pause");
                    return 0;
                }
                ++j;
                ++i;
                continue;
            }
        }
        if (symbol == '(') {
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            std::cin.ignore();
            ++j;
            continue;
        }
        if (symbol == ')') {
            --j;
            --i;
            while (Operations[j].operation != '(') {
                if (!Calculate(Operations, Values, i, j)) {
                    system("pause");
                    return 0;
                } else {
                    continue;
                }
            }
            ++i;
            Operations[j].operation = '0';
            std::cin.ignore();
            continue;
        } else {
            std::cout << "Uncorrect enter" << std::endl;
            system("pause");
            return 0;
        }
    }
    --i;
    --j;
    while (i >= 0 && j > -1) {
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    delete[] Values;
    delete[] Operations;
    return Values[0].value;
}

int FileForwardCalculate(char *filepath) {
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1;
    Symbol item;
    int i = 0;
    int j = 0;
    int value;
    std::ifstream in(filepath);
    while (in.is_open() && !in.eof()) {
        symbol = in.peek();
        if (symbol == ' ') {
            in.ignore();
            continue;
        }
        if (symbol == '\n' || symbol == EOF) {
            break;
        }
        if (symbol >= '0' && symbol <= '9' || symbol == '-' && flag) {
            in >> value;
            item.operation = '0';
            item.value = value;
            Values[i] = item;
            ++i;
            flag = 0;
            continue;
        }
        if (symbol == '+' || symbol == '-' && !flag || symbol == '*' || symbol == '/') {
            if (Operations[0].operation != '+' && Operations[0].operation != '-' &&
                Operations[0].operation != '*' && Operations[0].operation != '/') {
                item.operation = symbol;
                item.value = 0;
                Operations[j] = item;
                in.ignore();
                ++j;
                continue;
            }
            if ((Operations[0].operation == '+' || Operations[0].operation == '-' ||
                 Operations[0].operation == '*' || Operations[0].operation == '/') &&
                GetPriority(symbol) > GetPriority(Operations[j - 1].operation)) {
                if (symbol == '-' && Operations[j - 1].operation == '(') {
                    Symbol extraItem;
                    extraItem.operation = '0';
                    extraItem.value = 0;
                    Values[i] = extraItem;
                    ++i;
                }
                item.operation = symbol;
                item.value = 0;
                Operations[j] = item;
                in.ignore();
                ++j;
                continue;
            }
            if ((Operations[0].operation == '+' || Operations[0].operation == '-' ||
                 Operations[0].operation == '*' || Operations[0].operation == '/') &&
                GetPriority(symbol) <= GetPriority(Operations[j - 1].operation)) {
                if (!Calculate(Operations, Values, --i, --j)) {
                    system("pause");
                    return 0;
                }
                ++j;
                ++i;
                continue;
            }
        }
        if (symbol == '(') {
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            in.ignore();
            ++j;
            continue;
        }
        if (symbol == ')') {
            --j;
            --i;
            while (Operations[j].operation != '(') {
                if (!Calculate(Operations, Values, i, j)) {
                    system("pause");
                    return 0;
                } else {
                    continue;
                }
            }
            ++i;
            Operations[j].operation = '0';
            in.ignore();
            continue;
        } else {
            std::cout << "Uncorrect enter" << std::endl;
            system("pause");
            return 0;
        }
    }
    --i;
    --j;
    while (i >= 0 && j > -1) {
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    delete[] Values;
    delete[] Operations;
    return Values[0].value;
}

int ConsoleReverseCalculate() {
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1;
    Symbol item;
    int i = 0;
    int j = 0;
    int value;
    while (1) {
        symbol = std::cin.peek();
        if (symbol == '\n') {
            break;
        }
        if (symbol == ' ') {
            std::cin.ignore();
            continue;
        }
        if (symbol >= '0' && symbol <= '9' || symbol == '-' && flag) {
            std::cin >> value;
            item.operation = '0';
            item.value = value;
            Values[i] = item;
            ++i;
            flag = 0;
            continue;
        }
        if (symbol == '+' || symbol == '-' && !flag || symbol == '*' || symbol == '/') {
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            std::cin.ignore();
            ++j;
            if (!Calculate(Operations, Values, --i, --j)) {
                system("pause");
                return 0;
            }
            ++j;
            ++i;
            continue;
        }
        if (symbol == '(') {
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            std::cin.ignore();
            ++j;
            continue;
        }
        if (symbol == ')') {
            --j;
            --i;
            while (Operations[j].operation != '(') {
                if (!Calculate(Operations, Values, i, j)) {
                    system("pause");
                    return 0;
                } else {
                    continue;
                }
            }
            ++i;
            Operations[j].operation = '0';
            std::cin.ignore();
            continue;
        } else {
            std::cout << "Uncorrect enter" << std::endl;
            system("pause");
            return 0;
        }
    }
    --i;
    --j;
    while (i >= 0 && j > -1) {
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    delete[] Values;
    delete[] Operations;
    return Values[0].value;
}

int FileReverseCalculate(char *filepath) {
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1;
    Symbol item;
    int i = 0;
    int j = 0;
    int value;
    std::ifstream in(filepath);
    while (in.is_open() && !in.eof()) {
        symbol = in.peek();
        if (symbol == '\n' || symbol == EOF) {
            break;
        }
        if (symbol == ' ') {
            in.ignore();
            continue;
        }
        if (symbol >= '0' && symbol <= '9' || symbol == '-' && flag) {
            in >> value;
            item.operation = '0';
            item.value = value;
            Values[i] = item;
            ++i;
            flag = 0;
            continue;
        }
        if (symbol == '+' || symbol == '-' && !flag || symbol == '*' || symbol == '/') {
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            in.ignore();
            ++j;
            if (!Calculate(Operations, Values, --i, --j)) {
                system("pause");
                return 0;
            }
            ++j;
            ++i;
            continue;
        }
        if (symbol == '(') {
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            in.ignore();
            ++j;
            continue;
        }
    }
    delete[] Values;
    delete[] Operations;
    return Values[0].value;
}
