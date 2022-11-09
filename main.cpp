#include <cstring>
#include <fstream>
#include <iostream>

#include "structures.h"

LinkedListNode *split(std::istream &in_s) { // разделяем поток ввода на токены, вернем указатель на список
    LinkedListNode *head = nullptr; // указатель на начало списка
    LinkedListNode *tail = nullptr;  // указатель на конец списка
    for (int c = in_s.get(); c != '\n' && c != EOF; c = in_s.get()) {
        while (c == ' ' || c == '\t') {
            c = in_s.get(); // пропускаем пустое прост - во
        }
        if (c == '\n' || c == EOF) {
            break;
        }
        Token t;
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            t.operation = (char) c;
        } else if (c >= '0' && c <= '9') {
            int x = c - '0'; // код цифры минус код нуля равно знач цифры
            while (in_s.peek() >= '0' && in_s.peek() <= '9') {
                c = in_s.get();
                x = x * 10 + c - '0'; // по схеме Горнера добавляем след цифру
            }
            t.number = x;
        }
        if (!head) { // если в списке пусто
            head = new LinkedListNode();  // создаем 1 элемент
            tail = head;  // показываем на новый эл - т
        } else {
            tail->next = new LinkedListNode(); // иначе к посл эл - ту приклеиваем новый
            tail = tail->next;   // показываем на этот новый эл - т
        }
        tail->data = t;  // записываем токен в этот новый эл - т списка
    }
    return head;
}

int main(int argc, char **argv) {
    bool forward = false;
    bool file = false;
    char *file_name = nullptr;
    bool reverse = false;

    if (argc == 1) {
        std::cerr << "No arguments\n";
        return EXIT_FAILURE;
    }
    for (std::size_t i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--forward") == 0) {
            forward = true;
        } else if (std::strcmp(argv[i], "--file") == 0) {
            file = true;
            ++i;
            file_name = argv[i];
        } else if (std::strcmp(argv[i], "--reverse") == 0) {
            reverse = true;
        }
    }

    LinkedListNode *tokens = nullptr;
    if (file) {
        std::ifstream ifs(file_name);
        tokens = split(ifs);
    } else if (forward) {
        tokens = split(std::cin);
    }

    return EXIT_SUCCESS;
}
