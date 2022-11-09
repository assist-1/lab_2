#include "structures.h"

LinkedListNode *push(LinkedListNode *stack_top, Token value) {
    if (!stack_top) { // если в стеке пусто
        stack_top = new LinkedListNode();  // создаем 1 элемент
    } else {
        stack_top->next = new LinkedListNode(); // иначе к посл эл - ту приклеиваем новый
        stack_top->next->prev = stack_top; // связываем этот новый эл - т со stack_top как с предыдущим
        stack_top = stack_top->next;   // показываем на этот новый эл - т
    }
    stack_top->data = value;  // записываем токен в этот новый эл - т стека
    return stack_top; // возвращаем указатель на последний эл - т стека
}

LinkedListNode *pop(LinkedListNode *stack_top) { // удаляем посл эл - т
    if (stack_top->prev) { // если есть предыдущий эл - т
        stack_top = stack_top->prev; // переходим на предпоследний эл - т
        delete stack_top->next; // удаляем последний эл - т
        stack_top->next = nullptr; // у предпоследнего больше нет следующего, он стал последним
    } else { // это единственный эл - т
        delete stack_top;
        stack_top = nullptr; // все элементы закончились
    }
    return stack_top;
}
