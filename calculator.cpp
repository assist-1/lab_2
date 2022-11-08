#include "calculator.h"
#include "token.h"

struct ListNode {
    Token token;
    ListNode* next = nullptr;
};

void reverse_calculate(ListNode* head) {

}

void usual_calculate(ListNode* head) {

}

void calculate(std::istream &input_stream, bool reverse) {
    ListNode* head = nullptr;
    ListNode* p = head;
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
        reverse_calculate(head);
    } else {
        usual_calculate(head);
    }
}
