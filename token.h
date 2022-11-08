#ifndef LAB_2_TOKEN_H
#define LAB_2_TOKEN_H
#include <iostream>

struct Token {
    Token() = default;
    explicit Token(std::istream& input_stream);

    char type = '0';
    int value = 0;
};

#endif //LAB_2_TOKEN_H
