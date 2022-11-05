#include "calculator.h"

void reverse_calculate(std::istream &input_stream) {

}

void usual_calculate(std::istream &input_stream) {

}

void calculate(std::istream &input_stream, bool reverse) {
    if (reverse) {
        reverse_calculate(input_stream);
    } else {
        usual_calculate(input_stream);
    }
}
