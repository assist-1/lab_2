#include "calculator.h"
#include "token.h"

struct ListNode {
    Token token;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
};

struct TreeNode {
    Token token;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

int evaluate(TreeNode *root) {
    switch (root->token.type) {
        case '+':
            return evaluate(root->left) + evaluate(root->right);
        case '-':
            return evaluate(root->left) - evaluate(root->right);
        case '*':
            return evaluate(root->left) * evaluate(root->right);
        case '/':
            return evaluate(root->left) / evaluate(root->right);
        case '0':
            return root->token.value;
        default:
            throw std::runtime_error("Unexpected token");
    }
}

ListNode *pop(ListNode *stack_top) {
    if (!stack_top->prev) {
        delete stack_top;
        return nullptr;
    }
    stack_top = stack_top->prev;
    delete stack_top->next;
    stack_top->next = nullptr;
    return stack_top;
}

ListNode *push(ListNode *stack_top, Token token) {
    if (!stack_top) {
        stack_top = new ListNode();
    } else {
        stack_top->next = new ListNode();
        stack_top->next->prev = stack_top;
        stack_top = stack_top->next;
    }
    stack_top->token = token;
    return stack_top;
}

int reverse_calculate(ListNode *head) {
    ListNode *stack_top = nullptr;
    for (ListNode *p = head; p != nullptr; p = p->next) {
        if (p->token.type == '0') {
            stack_top = push(stack_top, p->token);
        } else {
            Token rhs = stack_top->token;
            stack_top = pop(stack_top);

            Token lhs = stack_top->token;
            stack_top = pop(stack_top);

            Token res;
            switch (p->token.type) {
                case '+':
                    res.value = lhs.value + rhs.value;
                    break;
                case '-':
                    res.value = lhs.value - rhs.value;
                    break;
                case '*':
                    res.value = lhs.value * rhs.value;
                    break;
                case '/':
                    res.value = lhs.value / rhs.value;
                    break;
            }
            stack_top = push(stack_top, res);
        }
    }
    return stack_top->token.value;
}

TreeNode *usual_parse(ListNode *head, ListNode *tail) {
    ListNode *last = nullptr;

    for (ListNode *p = head; p != tail; p = p->next) {
        if (p->token.type == '+' || p->token.type == '-') {
            last = p;
        }
    }
    if (last) {
        TreeNode *root = new TreeNode();
        root->token = last->token;
        root->left = usual_parse(head, last);
        root->right = usual_parse(last->next, tail);
        return root;
    }

    for (ListNode *p = head; p != tail; p = p->next) {
        if (p->token.type == '*' || p->token.type == '/') {
            last = p;
        }
    }
    if (last) {
        TreeNode *root = new TreeNode();
        root->token = last->token;
        root->left = usual_parse(head, last);
        root->right = usual_parse(last->next, tail);
        return root;
    }

    TreeNode *root = new TreeNode();
    root->token = head->token;
    return root;
}

int usual_calculate(ListNode *head) {
    TreeNode *root = usual_parse(head, nullptr);
    return evaluate(root);
}

int calculate(std::istream &input_stream, bool reverse) {
    ListNode *head = nullptr;
    ListNode *p = head;
    while (input_stream.peek() != '\n' && input_stream.peek() != EOF) {
        if (!head) {
            head = new ListNode();
            p = head;
        } else {
            p->next = new ListNode();
            p = p->next; // односвязный список (prev не заполняем)
        }
        p->token = Token(input_stream);
    }
    if (reverse) {
        return reverse_calculate(head);
    }
    return usual_calculate(head);
}
