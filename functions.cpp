#include "header.hpp"

bool Calculate(Symbol *Operations, Symbol *Values, int &i,
               int &j) { // математическая функция, которая считает арифметическую операцию от двух чисел
    int a;
    int b;
    int c;
    a = Values[i].value;
    switch (Operations[j].operation) { // на каждой операции 2 числа превращаются в одно, которое записывается в предыдущую позицию в массиве, а текущая позиция зануляется
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

int GetPriority(char ch) { // проверяем приоритет операции
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        return 0;
    }
}

int ConsoleForwardCalculate() { // функция для ввода значений в консоли в нормальном виде
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1; // флаг вводим для первого числа. Если оно отрицательное, знак запишется вместе с числом, а не в массив операций
    Symbol item;
    int i = 0; // индекс, по которому будет записывать очередное число
    int j = 0; // индекс, по которому будет записываться очередная операция
    int value;
    while (1) {
        symbol = std::cin.peek(); // смотрим следующий элемент, но не считываем
        if (symbol == '\n') {
            break;
        }
        if (symbol == ' ') { // игнорируем пробелы
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
                Operations[0].operation != '*' && Operations[0].operation !=
                                                  '/') { // если ни одна операция еще не была считана, просто записываем ее в массив
                item.operation = symbol;
                item.value = 0;
                Operations[j] = item;
                std::cin.ignore();
                ++j;
                continue;
            }
            if ((Operations[0].operation == '+' || Operations[0].operation == '-' ||
                 Operations[0].operation == '*' || Operations[0].operation == '/') &&
                GetPriority(symbol) > GetPriority(Operations[j -
                                                             1].operation)) { // если это уже не первая считанная операция, проверяем на приоритет
                if (symbol == '-' &&
                    Operations[j - 1].operation == '(') { // создаем дополнительную переменную 0 для ситуаций "(-"
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
                GetPriority(symbol) <= GetPriority(Operations[j -
                                                              1].operation)) { // когда приоритет новой операции <= приоритету нынешней, выполняем предыдущую операцию
                if (!Calculate(Operations, Values, --i, --j)) {
                    system("pause");
                    return 0;
                }
                ++j;
                ++i;
                continue;
            }
        }
        if (symbol == '(') { // если считана открывающая скобка, сохраняем ее
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            std::cin.ignore();
            ++j;
            continue;
        }
        if (symbol == ')') { // если считана закрывающая скобка, выполняем операции до открывающей
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
            Operations[j].operation = '0'; // удаляем открывающую скобку
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
    while (i >= 0 && j > -1) { // досчитываем пример до конца, если требуется
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    int a = Values[0].value;
    delete[] Values; // освобождаем память
    delete[] Operations; // освобождаем память
    return a;
}

int FileForwardCalculate(char *filepath) { // функция для ввода значений в файле в нормальном виде
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1; // флаг вводим для первого числа. Если оно отрицательное, знак запишется вместе с числом, а не в массив операций
    Symbol item;
    int i = 0; // индекс, по которому будет записывать очередное число
    int j = 0; // индекс, по которому будет записываться очередная операция
    int value;
    std::ifstream in(filepath);
    while (in.is_open() && !in.eof()) {
        symbol = in.peek(); // смотрим следующий элемент, но не считываем
        if (symbol == ' ') { // игнорируем пробелы
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
                Operations[0].operation != '*' && Operations[0].operation !=
                                                  '/') { // если ни одна операция еще не была считана, просто записываем ее в массив
                item.operation = symbol;
                item.value = 0;
                Operations[j] = item;
                in.ignore();
                ++j;
                continue;
            }
            if ((Operations[0].operation == '+' || Operations[0].operation == '-' ||
                 Operations[0].operation == '*' || Operations[0].operation == '/') &&
                GetPriority(symbol) > GetPriority(Operations[j -
                                                             1].operation)) { // если это уже не первая считанная операция, проверяем на приоритет
                if (symbol == '-' &&
                    Operations[j - 1].operation == '(') { // создаем дополнительную переменную 0 для ситуаций "(-"
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
                GetPriority(symbol) <= GetPriority(Operations[j -
                                                              1].operation)) { // когда приоритет новой операции <= приоритету нынешней, выполняем предыдущую операцию
                if (!Calculate(Operations, Values, --i, --j)) {
                    system("pause");
                    return 0;
                }
                ++j;
                ++i;
                continue;
            }
        }
        if (symbol == '(') { // если считана открывающая скобка, сохраняем ее
            item.operation = symbol;
            item.value = 0;
            Operations[j] = item;
            in.ignore();
            ++j;
            continue;
        }
        if (symbol == ')') { // если считана закрывающая скобка, выполняем операции до открывающей
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
            Operations[j].operation = '0'; // удаляем открывающую скобку
            in.ignore();
            continue;
        } else {
            std::cerr << "Uncorrect enter" << std::endl;
            system("pause");
            return 0;
        }
    }
    --i;
    --j;
    while (i >= 0 && j > -1) { // досчитываем пример до конца, если требуется
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    int a = Values[0].value;
    delete[] Values; // освобождаем память
    delete[] Operations; // освобождаем память
    return a;
}

int ConsoleReverseCalculate() { // функция для ввода значений в консоли в инфиксном виде
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1; // флаг вводим для первого числа. Если оно отрицательное, знак запишется вместе с числом, а не в массив операций
    Symbol item;
    int i = 0; // индекс, по которому будет записывать очередное число
    int j = 0; // индекс, по которому будет записываться очередная операция
    int value;
    while (1) {
        symbol = std::cin.peek(); // смотрим следующий элемент, но не считываем
        if (symbol == '\n') {
            break;
        }
        if (symbol == ' ') { // игнорируем пробелы
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
        } else {
            std::cerr << "Uncorrect enter" << std::endl;
            system("pause");
            return 0;
        }
    }
    --i;
    --j;
    while (i >= 0 && j > -1) { // досчитываем пример до конца, если требуется
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    int a = Values[0].value;
    delete[] Values; // освобождаем память
    delete[] Operations; // освобождаем память
    return a;
}

int FileReverseCalculate(char *filepath) { // функция для ввода значений в файле в инфиксном виде
    auto *Operations = new Symbol[100];
    auto *Values = new Symbol[100];
    char symbol;
    bool flag = 1; // флаг вводим для первого числа. Если оно отрицательное, знак запишется вместе с числом, а не в массив операций
    Symbol item;
    int i = 0; // индекс, по которому будет записывать очередное число
    int j = 0; // индекс, по которому будет записываться очередная операция
    int value;
    std::ifstream in(filepath);
    while (in.is_open() && !in.eof()) {
        symbol = in.peek(); // смотрим следующий элемент, но не считываем
        if (symbol == '\n' || symbol == EOF) {
            break;
        }
        if (symbol == ' ') { // игнорируем пробелы
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
        } else {
            std::cerr << "Uncorrect enter" << std::endl;
            system("pause");
            return 0;
        }

    }
    --i;
    --j;
    while (i >= 0 && j > -1) { // досчитываем пример до конца, если требуется
        if (!Calculate(Operations, Values, i, j)) {
            std::cerr << "Mathematics error! Please, check you request!" << std::endl;
            system("pause");
            return 0;
        } else {
            continue;
        }
    }
    int a = Values[0].value;
    delete[] Values; // освобождаем память
    delete[] Operations; // освобождаем память
    return a;
}
