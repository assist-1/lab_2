#ifndef LAB_2_STRUCTURES_H
#define LAB_2_STRUCTURES_H

struct Token {
    char operation = 0;
    int number = 0;
};

struct LinkedListNode {
    LinkedListNode *prev = nullptr;
    Token data;
    LinkedListNode *next = nullptr;
};

LinkedListNode *push(LinkedListNode *stack_top, Token value);

LinkedListNode *pop(LinkedListNode *stack_top);

#endif //LAB_2_STRUCTURES_H
