#include <iostream>
#include <fstream>
#include <tuple>
#include <list>
#include <algorithm>
#include <vector>
#include <cmath>


std::pair<std::vector<double>, std::vector<char> > math(std::vector<double> values, std::vector<char> ops) {
    if (values.size() == 1 and ops.size() == 0) {
        return std::make_pair(values, ops);
    }

    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '^') {
            double exp = pow(values[i], values[i + 1]);
            std::vector<double> new_values(values.size() - 1);
            std::vector<char> new_ops(ops.size() - 1);
            int c = 0;
            for (int j = 0; j < new_values.size(); ++j) {
                if (j == i) {
                    new_values[j] = exp;
                    c = 1;
                    continue;
                }
                new_values[j] = values[j+c];
            }
            c = 0;
            for (int j = 0; j < new_ops.size(); ++j) {
                if (j == i) {
                    c = 1;
                }
                new_ops[j] = ops[j + c];
            }

            return math(new_values, new_ops);
        }
    }

    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '*') {
            double exp = values[i] * values[i + 1];
            std::vector<double> new_values(values.size() - 1);
            std::vector<char> new_ops(ops.size() - 1);
            int c = 0;
            for (int j = 0; j < new_values.size(); ++j) {
                if (j == i) {
                    new_values[j] = exp;
                    c = 1;
                    continue;
                }
                new_values[j] = values[j+c];
            }
            c = 0;
            for (int j = 0; j < new_ops.size(); ++j) {
                if (j == i) {
                    c = 1;
                }
                new_ops[j] = ops[j + c];
            }

            return math(new_values, new_ops);
        }
    }
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '/') {
            if (values[i + 1] == 0) {
                std::cout << "Деление на ноль невозможно" << std::endl;
                exit(0);
            }
            double exp = values[i] / values[i + 1];
            std::vector<double> new_values(values.size() - 1);
            std::vector<char> new_ops(ops.size() - 1);
            int c = 0;
            for (int j = 0; j < new_values.size(); ++j) {
                if (j == i) {
                    new_values[j] = exp;
                    c = 1;
                    continue;
                }
                new_values[j] = values[j+c];
            }
            c = 0;
            for (int j = 0; j < new_ops.size(); ++j) {
                if (j == i) {
                    c = 1;
                }
                new_ops[j] = ops[j + c];
            }

            return math(new_values, new_ops);
        }
    }
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '+') {
            double exp = values[i] + values[i + 1];
            std::vector<double> new_values(values.size() - 1);
            std::vector<char> new_ops(ops.size() - 1);
            int c = 0;
            for (int j = 0; j < new_values.size(); ++j) {
                if (j == i) {
                    new_values[j] = exp;
                    c = 1;
                    continue;
                }
                new_values[j] = values[j+c];
            }
            c = 0;
            for (int j = 0; j < new_ops.size(); ++j) {
                if (j == i) {
                    c = 1;
                }
                new_ops[j] = ops[j + c];
            }

            return math(new_values, new_ops);
        }
    }
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '-') {
            double exp = values[i] - values[i + 1];
            std::vector<double> new_values(values.size() - 1);
            std::vector<char> new_ops(ops.size() - 1);
            int c = 0;
            for (int j = 0; j < new_values.size(); ++j) {
                if (j == i) {
                    new_values[j] = exp;
                    c = 1;
                    continue;
                }
                new_values[j] = values[j+c];
            }
            c = 0;
            for (int j = 0; j < new_ops.size(); ++j) {
                if (j == i) {
                    c = 1;
                }
                new_ops[j] = ops[j + c];
            }

            return math(new_values, new_ops);
        }
    }
}

bool my_isdigit(char ch)
{
    return std::isdigit(static_cast<unsigned char>(ch));
}

std::pair<std::vector<double>, std::vector<char> > parse(std::string input) {
    char ops [5] = {'+', '-', '*', '/', '^'};
    std::vector<char> operators;
    std::vector<double> values;
    std::string value = "";
    for(int i = 0; i < input.length(); ++i) {
        if (my_isdigit(input[i])) {
            value += input[i];
        } else {
            int n = sizeof(ops) / sizeof(*ops);
            if (std::find(ops, ops + n, input[i]) != ops + n) {
                operators.push_back(input[i]);
            }
            if (value != "") {
                values.push_back(std::stoi(value));
                value = "";
            }
        }
    }

    if (value != "") {
        values.push_back(std::stoi(value));
    }

    return std::make_pair(values, operators);
}
int main(int argc, char *argv[])
{
    std::string input;
    if (argc == 1) {
        std::cout << "Надо ввести флажок --forward или --file" << std::endl;
        return 0;
    }
    else if (argc == 2 && std::string(argv[1]) == "--forward") {
        std::getline(std::cin, input);
    }
    else if (argc == 3 && std::string(argv[1]) == "--file") {
        std::ifstream file;
        file.open((argv[2]));
        std::getline(file, input);
    }
    else {
        std::cout << "Некорректные данные" << std::endl;
        return 0;
    }
    std::pair<std::vector<double>, std::vector<char> > data = parse(input);
    std::cout << "Result:";
    std::cout << math(data.first, data.second).first[0] << std::endl;
    return 0;
}