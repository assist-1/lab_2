#include <iostream>
#include <cstring>

using namespace std;

#include "calculator.h"

//в математических выражениях пробелы игнорирутся
int main(int argc, char **argv)
{
    bool forward = false;
    bool reverse = false;
    bool file = false;

    if(argc == 1) 
    {
        cerr << "No flags\n";
        return EXIT_FAILURE;
    }
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "--forward") == 0) forward = true;
        else if(strcmp(argv[i], "--reverse") == 0) reverse = true;
        else if(strcmp(argv[i], "--file") == 0) file = true;
        else 
        {
            cerr << "Unexpected flag " << argv[i] << "\n";
            return EXIT_FAILURE;
        }        
    }

    if(reverse == forward)
    {
        cerr << "'I have the power to save the one you love. You must chOoOooOooOOoOse...'\
        \nChoose a flag between --forward and --reverse\n";
        return EXIT_FAILURE;
    }
    
    if(reverse) calculate_reverse(file);
    else calculate_forward(file);
    return EXIT_SUCCESS;

}