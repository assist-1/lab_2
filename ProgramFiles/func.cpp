#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "func.h"


void printVector(std::vector<std::string> vec){
    std::string val;
    for (auto &val : vec){
        std::cout<<val<< ' ';
    }
    std::cout << std::endl;
}

std::string fileEnter(){
    std::string path = "fileForTest.txt";
    std::string input;
    std::ifstream file(path);
    if (file.is_open()){
        getline(file,input);
    }
    else std::cerr << "Can't open file" << std::endl;
    std::cout << input << std::endl;
    return input;
}

std::string consoleEnter(){
    std::string input;
    getline(std::cin,input);
    return input;
}

void convertToStrArray(std::vector<std::string>& txt,std::string input){
    std::stringstream streamStr(input);
    std::string val;
    while(std::getline(streamStr,val, ' ')){
        txt.push_back(val);
    }
}

bool isNumber(std::string str){
    for(char const &c : str){
        if (std::isdigit(c)==0){
            return false;
        }
    }
    return true;
}

bool isOperator(std::string str){
    std::string operators[6]={"+","-","*","/","(",")"};
    for (int i=0;i<6;i++){
        if (operators[i]==str) return true;
    }
    return false;
}

void calc(std::vector<std::string>& stack,std::string number1,std::string number2,std::string oprtr){
    double calculation = 0;
    if (oprtr=="+"){
        calculation = stod(number1)+stod(number2);
    }
    if (oprtr=="-"){
        calculation = stod(number1)-stod(number2);
    }
    if (oprtr=="*"){
        calculation = stod(number1)*stod(number2);
    }
    if (oprtr=="/"){
        calculation = stod(number1)/stod(number2);
    }
    std::string answer = std::to_string(calculation);
    stack.push_back(answer);
}

int checkPriority(std::string oprtr) {
    if (oprtr == "*" || oprtr == "/") return 3;
    if (oprtr == "+" || oprtr == "-") return 2;
    if (oprtr == "(" || oprtr == ")") return 1;
    return 0;
}

void convertToPolishNotation(std::vector<std::string> txt,std::vector<std::string> &finalLine){
    std::vector<std::string> stack;
    int nowPriority = 0, lastElementPriority = 0;
    for (int i = 0; i < txt.size(); i++) {
        if (isNumber(txt[i])) {
            finalLine.push_back(txt[i]);
        }
        if (isOperator(txt[i])) {
            if (txt[i] == "(") {
                stack.push_back(txt[i]); continue;
            }
            if (stack.size() == 0) {
                stack.push_back(txt[i]);
                continue;
            }
            nowPriority = checkPriority(txt[i]);
            lastElementPriority = checkPriority(stack[stack.size() - 1]);
            if (txt[i] == ")") {
                for (int j = stack.size() - 1; j > -1; j--) {
                    if (stack[j] == "(") {
                        stack.pop_back();
                        break;
                    }
                    finalLine.push_back(stack[j]);
                    stack.pop_back();
                }
                continue;
            }
            if (nowPriority > lastElementPriority) stack.push_back(txt[i]);
            else {
                for (int m = stack.size() - 1; m > -1; m--) {

                    finalLine.push_back(stack[m]);
                    stack.pop_back();
                    if (stack.size() == 0) {
                        lastElementPriority = checkPriority("NULL");
                    }
                    else lastElementPriority = checkPriority(stack[stack.size() - 1]);
                    if (nowPriority > lastElementPriority) break;
                    
                }
                stack.push_back(txt[i]);
            }
        }   
    }
    for (int j = stack.size() - 1; j > -1; j--) {
        finalLine.push_back(stack[j]);
        stack.pop_back();
    }
}   
void calcPolishNotation(std::vector<std::string> txt){
    std::vector<std::string> stack;
    std::string answer;
    for(int i=0;i<txt.size();i++){
        if (isNumber(txt[i])){
            stack.push_back(txt[i]);
        }
        else if (isOperator(txt[i])){
            std::string oprtr = txt[i];
            std::string number1 = stack[stack.size()-2];
            std::string number2 = stack[stack.size()-1];
            stack.pop_back();
            stack.pop_back();
            calc(stack,number1,number2,oprtr);
        }
        if (i+1==txt.size()&&stack.size()==1) {
            answer = stack[0];
        }
    }   
    std::cout << std::fixed << stod(answer) << std::endl;
}