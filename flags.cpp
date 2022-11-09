#include <iostream>
#include <cstring>
#include "Header.h"
int main(int argc, char **argv){
    if (argc==1){
        std::cerr << "Nothing was read!\n";
        return EXIT_FAILURE;
    }
    bool forward=false;
    bool reverse=false;
    bool file=false;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "--forward") == 0)
            forward = true;
        else if(strcmp(argv[i],"--reverse") == 0)
            reverse = true;
        else if(strcmp(argv[i],"--file")==0)
            file = true;
        else
        {
            std::cerr << "The flag was enterd incorrectly" << argv[i] <<std::endl;
            return EXIT_FAILURE;
        }
    }
    if(forward)
        math();
    else
        opz();
    return EXIT_SUCCESS;

}
