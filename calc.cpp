#include "calc.h"

LinkedListNode *eval(LinkedListNode *numbers_top, char operation) {
    int right = numbers_top->data.number;
    numbers_top = pop(numbers_top);

    int left = numbers_top->data.number;
    numbers_top = pop(numbers_top);

    Token result;
    if (operation == '+') {
        result.number = left + right;
    } else if (operation == '-') {
        result.number = left - right;
    } else if (operation == '*') {
        result.number = left * right;
    } else if (operation == '/') {
        result.number = left / right;
    }
    numbers_top = push(numbers_top, result);
    return numbers_top;
}

int calc(LinkedListNode *tokens) {
    LinkedListNode *numbers_top = nullptr;
    LinkedListNode *operators_top = nullptr;
    for (LinkedListNode *p = tokens; p; p = p->next) {
        if (p->data.operation == 0) { // мы ничего не записали в операцию и там остался 0, значит это число
            numbers_top = push(numbers_top, p->data);
        } else { // тогда это операция
            char op = p->data.operation;
            if (op == '*' || op == '/') {
                while (operators_top &&
                       (operators_top->data.operation == '*' || operators_top->data.operation == '/')) {
                    numbers_top = eval(numbers_top, operators_top->data.operation);
                    operators_top = pop(operators_top);
                }
            } else {
                while (operators_top) {
                    numbers_top = eval(numbers_top, operators_top->data.operation);
                    operators_top = pop(operators_top);
                }
            }
            operators_top = push(operators_top, p->data);
        }
    }
    while (operators_top) {
        numbers_top = eval(numbers_top, operators_top->data.operation);
        operators_top = pop(operators_top);
    }

    return numbers_top->data.number;
}

int calc_reverse(LinkedListNode *tokens) {
    return 0;
}
