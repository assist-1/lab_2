#include <iostream>
#include <cstring>
#include "func1.h"

const char* flags[3] = {
    "--forward",
    "--reverse",
    "--file"
};

int main(int argc, char ** argv) {
    switch (argc) {
        case 1:
            std::cerr << ">>> Flags has not been read <<< \n";
            exit(1);
        case 2:
            if (!strcmp(argv[1], flags[0])) {
                std::cout << "Enter a mathematical expression in normalized form:\n>> ";
                input_cin();
                forward();
            }
            else if (!strcmp(argv[1], flags[1])) {
                std::cout << "Enter a mathematical expression in reverse polish notation form:\n>> ";
                input_cin();
                reverse();
            }
            else {
                std::cerr << ">>> Wrong flags <<<\n";
                exit(1);
            }
            break;
        case 3:
            if (!strcmp(argv[1], flags[2])) {
                char *filename = argv[2];
                if (input_file(filename)) {
                    std::cerr << ">>> Provide file <<<\n";
                    exit(1);
                }
                if (!strcmp(argv[3], flags[0])) {
                    std::cout << "A mathematical expression is in normalized form\n";
                    forward();
                }
                else if (!strcmp(argv[3], flags[1])) {
                    std::cout << "A mathematical expression is in reverse polish notation form\n";
                    reverse();
                }
            }
            else {
                std::cerr << ">>> Wrong flags <<<\n";
                exit(1);
            }
            break;
        default:
            std::cerr << ">>> Wrong flags <<<\n";
            exit(1);
    }

    exit(0);
}
