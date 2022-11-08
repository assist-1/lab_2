#include "calculator.h"
#include "token.h"

void reverse_calculate(Token* tokens) {

}

void usual_calculate(Token* tokens) {

}

void calculate(std::istream &input_stream, bool reverse) {
    Token tokens[100];
    // TODO заполнить токены
    if (reverse) {
        reverse_calculate(tokens);
    } else {
        usual_calculate(tokens);
    }
}
