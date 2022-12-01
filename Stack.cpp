#include <cstdlib>
#define SIZE 100

class Stack {
    int * arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool empty();
    bool isFull();


};
Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (isFull()) {
        exit(EXIT_FAILURE);
    }
    arr[++top] = x;
}
int Stack::pop() {
    if (empty())  {
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

int Stack::peek() {
    if (!empty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

int Stack::size() {
    return top + 1;
}

bool Stack::empty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}
