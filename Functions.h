#ifndef LABA2_FUNCTIONS_H
#define LABA2_FUNCTIONS_H
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
public:

    Stack& operator=(Stack &) = delete;
    Stack(Stack &) = delete;
    Stack& operator=(Stack &&) noexcept = default;
    Stack(Stack &&) noexcept = default;
    Stack() = default;


    void Push(T value) {
        last_ = new Node{.value = value, .left = last_};
        ++size_;
    }

    void Pop() {
        EmptyStackCheck();
        Node *to_pop = last_;
        last_ = last_->left;
        delete to_pop;
        --size_;
    }

    T Top() {
        EmptyStackCheck();
        return last_->value;
    }


    size_t Size() {
        return size_;
    }

    bool Empty() {
        return size_ == 0;
    }

    ~Stack() {
        while (!Empty()) {
            Pop();
        }
    }

private:
    struct Node {
        T value;
        Node *left;
    };

private:
    void EmptyStackCheck() {
        if (last_ == nullptr) {
            throw std::runtime_error("Stack is empty!");
        }
    }

private:

    size_t size_ = 0;
    Node* last_ = nullptr;
};

struct Term {
    char type;
    double value;
};
int Value(char Ch);

bool Oper(Stack<Term> &Stack_n, Stack<Term> &Stack_o, Term &obj);



#endif //LABA2_FUNCTIONS_H
