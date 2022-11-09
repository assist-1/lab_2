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

#endif //LAB_2_STRUCTURES_H
