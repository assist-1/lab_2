#include <iostream>
#include <fstream>

int numbers[100];
int max_s = 0; int max_n = 0;
int counter = 0;

char symbols[100];

const int str_len = 256;
char algebraic[str_len];


int input_file(char *in_name) {
    std::ifstream in_f;
    in_f.open(in_name);
    char letter;
    int i = 0;
    if (in_f.is_open()) {
        while (in_f >> letter)
            algebraic[i++] = letter;
        in_f.close();
        return 0;
    }
    return 1;
}

void input_cin() {
    std::cin.read(algebraic, str_len - 1);
    long len = std::cin.gcount();
    algebraic[len] = '\0';
}

int is_sign(char x) {
    if (x == '*' || x == '/' ||
        x == '+' || x == '-')
        return 1;
    return 0;
}

int is_digit(char x) {
    if (x >= '0' and x <= '9')
        return 1;
    return 0;
}


int full_num() {
    int x = algebraic[counter++] - '0';
    while (is_digit(algebraic[counter]))
        x = x * 10 + algebraic[counter++] - '0';
    return x;
}

int next_sign() {
    while (!is_sign(algebraic[counter]) &&
           !is_digit(algebraic[counter])) {
        if (!algebraic[counter])
            return 1;
        counter++;
    }
    return 0;
}

int use_sign(int x, int y, char signi) {
    switch (signi) {
        case '*': return x * y;
        case '/': return x / y;
        case '+': return x + y;
        case '-': return x - y;
    }
    return 1;
}

int division_by_zero(int y, char signi) {
    if (!y and signi == '/')
        return 1;
    return 0;
}
bool indication(char x, char y) {
    if ((x == '*' || x == '/') &&
        (y == '*' || y == '/'))
        return true;
    else if ((y == '*' || y == '/') &&
             (x == '+' || x == '-'))
        return true;
    else if ((x == '+' || x == '-') &&
             (y == '+' || y == '-'))
        return true;
    return 0;
}
int count() {
    char signi = symbols[--max_s];
    int x = numbers[--max_n];
    int y = numbers[--max_n];
    if (division_by_zero(x, signi)) {
        std::cerr << "\n >>> Division by zero <<< \n";
        exit(1);
    }
    int answer = use_sign(y, x, signi);
    return answer;
}


int forward() {
    char mark = algebraic[0];
    int res;
    int num_fin;
    while ((mark = algebraic[counter++])) {
        if (is_digit(mark)) {
            num_fin = mark - '0';
            while (is_digit(algebraic[counter])) {
                mark = algebraic[counter++];
                num_fin = num_fin * 10 + mark - '0';
            }
            numbers[max_n++] = num_fin;
        }
        else if (is_sign(mark)) {
            while (max_s != 0 &&
                   indication(mark, symbols[max_s - 1])) {
                res = count();
                numbers[max_n++] = res;
            }
            symbols[max_s++] = mark;
        }
        else if (mark == '(')
            symbols[max_s++] = mark;
        else if (mark == ')'){
            while (symbols[max_s - 1] != '(') {
                res = count();
                numbers[max_n++] = res;
            }
            max_s--;
        }
    }
    while (max_s != 0) {
        res = count();
        numbers[max_n++] = res;
    }
    int max_min = max_n - 1;
    std::cout << std::endl << "Answer: "
              << numbers[max_min] << std::endl;
    return 0;
}


int reverse() {
    int x, y;
    char signi;
    next_sign();
    x = full_num();
    next_sign();
    
    while(true) {
        y = full_num();
        next_sign();
        signi = algebraic[counter++];

        if (division_by_zero(y, signi)) {
            std::cerr << "\n >>> Division by zero <<< \n";
            exit(1);
        }
        x = use_sign(x, y, signi);
        if (next_sign())
            break;
    }

    std::cout << std::endl << "Answer: "
              << x << std::endl;
    return 0;
}
