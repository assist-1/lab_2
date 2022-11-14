#include "Functions.h"

int Value(char Ch) {
    if (Ch == '+' || Ch == '-')return 1;
    if (Ch == '*' || Ch == '/')return 2;
    else return 0;
}

bool Oper(Stack<Term> &Stack_n, Stack<Term> &Stack_o, Term &obj) {
    double s1, s2, s3;
    s1 = Stack_n.Top().value;
    Stack_n.Pop();
    switch (Stack_o.Top().type) {
        case '+':
            s2 = Stack_n.Top().value;
            Stack_n.Pop();
            s3 = s1 + s2;
            obj.type = '0';
            obj.value = s3;
            Stack_n.Push(obj);
            Stack_o.Pop();
            break;

        case '-':
            s2 = Stack_n.Top().value;
            Stack_n.Pop();
            s3 = s2 - s1;
            obj.type = '0';
            obj.value = s3;
            Stack_n.Push(obj);
            Stack_o.Pop();
            break;

        case '*':
            s2 = Stack_n.Top().value;
            Stack_n.Pop();
            s3 = s1 * s2;
            obj.type = '0';
            obj.value = s3;
            Stack_n.Push(obj);
            Stack_o.Pop();
            break;

        case '/':
            s2 = Stack_n.Top().value;
            if (s1 == 0) {
                std::cerr << "You can't divide by zero\n";
                return false;
            } else {
                Stack_n.Pop();
                s3 = (s2 / s1);
                obj.type = '0';
                obj.value = s3;
                Stack_n.Push(obj);
                Stack_o.Pop();
                break;
            }
        default:
            std::cerr << "\nError!\n";
            return false;
    }
    return true;
}

