#include <iostream>
#include <stack>
#include "Header.h"
struct znacheniya{
    char type;
    double number;
};
int priority(char simv){
    if (simv=='+' || simv=='-')
        return 1;
    if (simv=='*' || simv=='/')
        return 2;
    else return 0;
}
bool calculate(std::stack <znacheniya> & stack_operand, std::stack <znacheniya> & stack_operation,znacheniya& element) {
    double a,b,c;
    a=stack_operand.top().number;
    stack_operand.pop();
    switch (stack_operation.top().type){
        case '+':
            b=stack_operand.top().number;
            stack_operand.pop();
            c=a+b;
            element.type='0';
            element.number=c;
            stack_operand.push(element);
            stack_operation.pop();
            break;
        case '-':
            b=stack_operand.top().number;
            stack_operand.pop();
            c=b-a;
            element.type='0';
            element.number=c;
            stack_operand.push(element);
            stack_operation.pop();
            break;
        case '*':
            b=stack_operand.top().number;
            stack_operand.pop();
            c=a*b;
            element.type='0';
            element.number=c;
            stack_operand.push(element);
            stack_operation.pop();
            break;
        case '/':
            b=stack_operand.top().number;
            stack_operand.pop();
            c=b/a;
            element.type='0';
            element.number=c;
            stack_operand.push(element);
            stack_operation.pop();
            if (a==0){
                std::cerr<<"Error"<<std::endl;
                return false;
            }
            break;
        default:
            std::cerr<<"Error"<<std::endl;
            return false;
            break;
    }
    return true;
}
int math() {
    std::cout<<"Enter the expression:"<<std::endl;
    char simv;
    double number;
    bool flag=1;
    std::stack <znacheniya> stack_operand;
    std::stack <znacheniya> stack_operation;
    znacheniya element;
    while (true){
        simv=std::cin.peek();
        if (simv == '\n')
            break;
        if (simv == ' '){
            std::cin.ignore();
            continue;
        }
        if ((simv=='0' || simv=='1' || simv=='2' || simv=='3' || simv=='4' || simv=='5' || simv=='6' || simv=='7' || simv=='8' || simv=='9' || (simv=='-' & flag==1))){
            std::cin>>number;
            element.type='0';
            element.number=number;
            stack_operand.push(element);
            flag=0;
            continue;
        }
        if ((simv == '+' || (simv=='-' & flag==0) || simv=='*' || simv=='/')){
            if (stack_operation.size()==0){
            element.type=simv;
            element.number=0;
            stack_operation.push(element);
            std::cin.ignore();
            continue;
            }
            if (stack_operation.size()!=0 & priority(simv)>priority(stack_operation.top().type)){
                element.type=simv;
                element.number=0;
                stack_operation.push(element);
                std::cin.ignore();
                continue;
            }
            
            if (stack_operation.size()!=0 & priority(simv)<=priority(stack_operation.top().type)){
                if (calculate(stack_operand,stack_operation,element)==false)
                    return 0;
                continue;
            }
        }
    if (simv == '(') {
        element.type = simv;
        element.number = 0;
        stack_operation.push(element);
        std::cin.ignore();
        continue;
    }
    if (simv == ')') {
        while (stack_operation.top().type != '(') {
            if (calculate(stack_operand, stack_operation, element) == false) {
                return 0;
            }
            else continue;
        }
        stack_operation.pop();
        std::cin.ignore();
        continue;
        }
    else {
        std::cout<<"Value entered incorrectly"<<std::endl;
        return 0;
        }
    }
    while (stack_operation.size()!=0){
        if (calculate(stack_operand,stack_operation,element)==false){
            return 0;
            }
        else
            continue;
    }
    std::cout<<"Result:"<<stack_operand.top().number<<std::endl;
    return 0;
}

int opz() {
    char simv;
    char oper;
    double number;
    std::cout<<"Enter the expression:"<<std::endl;
    std::stack <double> stack_operand;
    while (true){
        simv=std::cin.peek();
        if (simv=='\n')
            break;
        if (simv==' '){
            std::cin.ignore();
            continue;
        }
        if (simv>='0' & simv<='9'){
            std::cin>>number;
            stack_operand.push(number);
        }
        if (simv=='+' || simv=='-' || simv=='/' || simv=='*'){
            std::cin >> oper;
            double a,b,c;
            switch (oper){
                case '+':
                    a=stack_operand.top();
                    stack_operand.pop();
                    b=stack_operand.top();
                    stack_operand.pop();
                    c=a + b;
                    stack_operand.push(c);
                    break;
                case '-':
                    a=stack_operand.top();
                    stack_operand.pop();
                    b=stack_operand.top();
                    stack_operand.pop();
                    c= b - a;
                    stack_operand.push(c);
                    break;
                case '*':
                    a=stack_operand.top();
                    stack_operand.pop();
                    b=stack_operand.top();
                    stack_operand.pop();
                    c=a * b;
                    stack_operand.push(c);
                    break;
                case '/':
                    a = stack_operand.top();
                    stack_operand.pop();
                    b=stack_operand.top();
                    stack_operand.pop();
                    c = b / a;
                    stack_operand.push(c);
                    if (a == 0){
                        std::cerr<<"Error"<<std::endl;
                        return 0;
                    }
                    break;
                default:
                    std::cerr<<"Error"<<std::endl;
                    return 0;
                    break;
            }
            continue;
        }
        else {
            std::cout<< "Value entered incorrectly"<<std::endl;
            return 0;
        }
    }
    std::cout<<"Result:"<<stack_operand.top()<<std::endl;
    return 0;
}
