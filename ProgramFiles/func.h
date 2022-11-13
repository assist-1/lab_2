#include <vector>
#include <string>
std::string consoleEnter();
std::string fileEnter();
void convertToStrArray(std::vector<std::string>& txt,std::string input);
void printVector(std::vector<std::string> vec);
bool isNumber(std::string str);
bool isOperator(std::string str);
void convertToPolishNotation(std::vector<std::string> txt,std::vector<std::string> &finalLine);
void calc(std::vector<std::string>& stack,std::string number1,std::string number2,std::string oprtr);
void calcPolishNotation(std::vector<std::string> txt);