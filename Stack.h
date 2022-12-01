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

