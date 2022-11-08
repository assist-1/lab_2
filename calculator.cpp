#include "calculator.h"
#include "token.h"

struct ListNode {
    Token token;
    ListNode *next = nullptr;
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

int reverse_calculate(ListNode *head) {
    return 0;
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
            p = p->next;
        }
        p->token = Token(input_stream);
    }
    if (reverse) {
        return reverse_calculate(head);
    }
    return usual_calculate(head);
}
