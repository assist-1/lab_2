#include <iostream> 
#include <stack> 
#include <string> 
#include<fstream> 
#include<cstring>
#include "clac.h"
 

 
int main(int argc,char**argv) 
{ 
    if (argc == 1) { 
        std::cerr << "Nothing was read\n"; 
        return EXIT_FAILURE; 
 
    } 
    else { 
        if (strcmp(argv[1], "--forward") == 0) {   
            std::cout << "enter the formula" << std::endl; 
            char a[100]; 
            std::cin >> a; 
            int ans = forward(a); 
            std::cout << ans<<std::endl; 
 
 
        } 
        else if (strcmp(argv[1], "--reverse") == 0) { 
            std::cout << "enter the formula" << std::endl; 
            std::string a; 
            getline(std::cin, a); 
            int ans = forward(a); 
            std::cout << ans << std::endl; 
 
        } 
 
        else if (strcmp(argv[1], "--file") == 0) { 
            if (strcmp(argv[2], "--forward") == 0) { 
                 
                std::ifstream input("laba.txt"); 
                if (!input) { 
                    std::cout << "Unable to open file."; 
                    return -1; 
                } 
                std::string y; 
                input >> y; 
                std::cout << "Formula: " << y << std::endl; 
                int ans = forward(y); 
                std::cout << ans << std::endl; 
 
 
 
 
 
 
 
 
 
            } 
            else if (strcmp(argv[2], "--reverse") == 0) { 
                std::ifstream input("C:\\Users\\79165\\source\\repos\\lab2final\\example.txt"); 
                if (!input) { 
                    std::cout << "Unable to open file."; 
                    return -1; 
                } 
                std::string y; 
                getline(input, y); 
                std::cout << "Formula: " << y << std::endl; 
                int ans = forward(y);
                std::cout << ans << std::endl; 
 
 
 
            } 
            else { 
                std::cout << "Choose right option"; 
            } 
         
 
        } 
        /*/else{ 
            std::cout << "wrong args" << std::endl; 
            return EXIT_FAILURE; 
        }/*/ 
    } 
 
 
    return 0; 
} 
 
