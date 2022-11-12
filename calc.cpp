#include "calc.h"

LinkedListNode *eval(LinkedListNode *numbers_top, char operation) { // берет два последних числа из стека numbers_top и применяет к ним operation, результат кладет в numbers_top и возвращает его
    int right = numbers_top->data.number; // верхний - последний добавленный
    numbers_top = pop(numbers_top); // убираем верхний

    int left = numbers_top->data.number; // верхний - предпоследний добавленный
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
    numbers_top = push(numbers_top, result); // добавляем результат в стек
    return numbers_top; // возвращаем указатель на стек
}

int calc(LinkedListNode *tokens) {
    LinkedListNode *numbers_top = nullptr;
    LinkedListNode *operators_top = nullptr;
    for (LinkedListNode *p = tokens; p; p = p->next) { // пока р существует, читаем следующий токен
        if (p->data.operation == 0) { // мы ничего не записали в операцию и там остался 0, значит это число
            numbers_top = push(numbers_top, p->data);
        } else { // тогда это операция
            char op = p->data.operation;
            if (op == '*' || op == '/') { // выполняем предыдущие только * и / подряд
                while (operators_top &&
                       (operators_top->data.operation == '*' || operators_top->data.operation == '/')) {
                    numbers_top = eval(numbers_top, operators_top->data.operation);
                    operators_top = pop(operators_top); // удаляем выполненную операцию
                }
            } else { // выполняем все предыдущие
                while (operators_top) {
                    numbers_top = eval(numbers_top, operators_top->data.operation);
                    operators_top = pop(operators_top);
                }
            }
            operators_top = push(operators_top, p->data); // добавляем вновь прочитанную операцию
        }
    }
    while (operators_top) { // выполняем все добавленные, но не выполненные операции
        numbers_top = eval(numbers_top, operators_top->data.operation);
        operators_top = pop(operators_top);
    }

    return numbers_top->data.number; // в стеке чисел остается только результат последней операции
}

int calc_reverse(LinkedListNode *tokens) {
    LinkedListNode *numbers_top = nullptr;
    for (LinkedListNode *p = tokens; p; p = p->next) {// пока р существует, читаем следующий токен
        if (p->data.operation == 0) { // поле operation не менялось, значит, это число
            numbers_top = push(numbers_top, p->data);
        } else { // иначе - операция
            numbers_top = eval(numbers_top, p->data.operation); // применяем прочитанную операцию и кладем результат на вершину стека
        }
    }
    return numbers_top->data.number; // в стеке чисел остается только результат последней операции
}
