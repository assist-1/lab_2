#include "token.h"

Token::Token(std::istream& input_stream) {
    while (isspace(input_stream.peek())) { // пропускаем пустое пространство
        input_stream.get();
    }
    char c = (char) input_stream.get();
    switch (c) {
        case '*':
        case '(':
        case ')':
        case '-':
        case '+':
        case '/':
            type = c;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            value = c - '0';
            while (isdigit(input_stream.peek())) {
                value = value * 10 + input_stream.get() - '0'; // схема Горнера
            }
            break;
        default:
            throw std::runtime_error("Wrong symbol");
    }
}
