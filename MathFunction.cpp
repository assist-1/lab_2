#include "calculator.h"
#include <cmath>

double MathOperations(double first, double second, int operations_type) {
    if (operations_type == 2) return first + second;
    if (operations_type == -2) return first - second;
    if (operations_type == 3) return first * second;
    if (operations_type == -3) return first / second;
    if (operations_type == 4) return pow(first, second);
    else return 0;
}