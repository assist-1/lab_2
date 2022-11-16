#include <iostream>
#include <fstream>
#include <parse.cpp>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "Nothing was read" << std::endl;
        return EXIT_FAILURE;
    }

    std::string args[3] = {"--forward", "--reverse", "--file"};
    
    bool from_file = false;
    bool rpn = false;
    bool args_err = true;
    bool forward = false;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == args[0]) {
            forward = true;
            args_err = false;
        }
        else if (argv[i] == args[1]) {
            rpn = true;
            args_err = false;
        }
        else if (argv[i] == args[2]) {
            from_file = true;
        }
        else {
            std::cerr << "Wrong argument." << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (args_err or rpn == forward) {
        std::cerr << "Wrong argument." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << parse() << std::endl;
    return 0;


    if (from_file) {
        std::ifstream input ("input.txt");
        
        if (!input) {
            std::cerr << "Unable to open input file" << std::endl;
            return EXIT_FAILURE;
        }
    }


}