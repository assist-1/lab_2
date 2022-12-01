#include  <iostream>
#include <cstring>
#include <fstream>
#include "calculate.h"
#include "Stack.h"
int calculator(const char *s){
    Stack numbers;
    Stack operations;
    int j=0;

    while(s[j]!='\0'){
        j++;}
    for(int i=0;i<=j;i++){
        if (s[i]==' ')
            continue;
        else if (s[i] == '(')
            operations.push(s[i]);
            if(s[i+1]=='-'){
                numbers.push(0);
            }

        else if (isdigit(s[i])) {
            int numb = 0;
            while ((s[i] != '\0') && (isdigit(s[i]))) {
                numb = numb * 10 + (s[i] - '0');
                i++;
            }
            i--;
            numbers.push(numb);

        }
        else if (s[i] == ')') {
            while (!operations.empty() && operations.peek() != '(') {
                int numb2 = numbers.peek();
                numbers.pop();
                int numb1 = numbers.peek();
                numbers.pop();
                char op = operations.peek();
                operations.pop();
                numbers.push(perform(numb2, numb1, op));
            }
            if (!operations.empty()) {
                operations.pop();
            }
        }
        else {
             if(s[i]=='-' && i==0){
                numbers.push(0);
            }

            while (!operations.empty() && precedence(operations.peek()) >= precedence(s[i])) {
                int numb2 = numbers.peek();
                numbers.pop();
                int numb1 = numbers.peek();
                numbers.pop();
                char op = operations.peek();
                operations.pop();
                numbers.push(perform(numb1, numb2, op));
            }
            operations.push(s[i]);
        }

    }

    return numbers.peek();
}
int calculatorr(const char *s){
    Stack numbers;
    Stack operations;
    int j=0;
    while(s[j]!='\0' && s[j]!='\n'){
        j++;}
    for(int i=0;i<j;i++){
        if (s[i]==' ')
            continue;

        else if (isdigit(s[i])) {
            int numb = 0;
            while (numbers.size()!=2 && (isdigit(s[i]))) {
                numb = numb * 10 + (s[i] - '0');
                i++;
            }
            i--;
            numbers.push(numb);

        }
        else {
            operations.push(s[i]);
            while (!operations.empty()) {
                int numb2 = numbers.peek();
                numbers.pop();
                int numb1 = numbers.peek();
                numbers.pop();
                char op = operations.peek();
                operations.pop();
                numbers.push(perform(numb1, numb2, op));
            }
        }
    }

    return numbers.peek();
}


int main(int argc, char ** argv){
    std::string name;
    char s[1000];
    bool forward=false;
    bool file=false;
    bool reverse=false;
    if (argc==1){
        std::cerr<<"Nothing was read\n";
        return EXIT_FAILURE;
    }
    else{
        for (int i=1;i<argc;++i){
            if(std::strcmp(argv[i],"--forward")==0){
                forward=true;
            }
            if(std::strcmp(argv[i],"--file")==0){
                if (!argv[i+1]){
                    std::cerr<<"File name not specified\n";
                    return EXIT_FAILURE;
                }
                else {
                    file=true;
                    name = argv[i + 1];
                }

            }
            if(std::strcmp(argv[i],"--reverse")==0){
                reverse=true;
            }
        }

        if (file && forward){
            std::cerr<<"You should choose only file or only forward\n";
            return EXIT_FAILURE;
        }
        if (file && reverse){
            std::ifstream f(name);
            f.getline(s, 1000);
            f.close();
            std::cout<<s<<std::endl;
            std::cout<<calculatorr(s) << '\n';
        }
        else if (file){
            std::ifstream f(name);
            f.getline(s, 1000);
            f.close();
            std::cout<<s<<std::endl;
            std::cout<<calculator(s) << '\n';
            }
        else if(forward){
            char a[1000]={0};
            char token;
            int i=0;
            while(std::cin.get(token)) {
                if (token == '\n') {
                    break;
                }
                a[i] = token;
                i++;
            }
            if(reverse){
                std::cout<<calculatorr(a) << '\n';
            }
            else{
                std::cout<<calculator(a) << '\n';
            }

            }
        }


    return 0;
    }



