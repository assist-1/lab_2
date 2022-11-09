#include "header.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr
                << "Please follow the rules and specify the desired flag first: --forward or -- reverse! If you also have a file, you should write --file and its name."
                << std::endl;
        return EXIT_FAILURE;
    }
    int answer;
    if (strcmp(argv[1], "--forward") == 0) {
        if (argc == 4 && strcmp(argv[2], "--file") == 0) {
            answer = FileForwardCalculate(argv[3]);
        }
        else if (argc > 4) {
            std::cerr << "Incorrect input" << std::endl;
            return EXIT_FAILURE;
        }
        else {
            answer = ConsoleForwardCalculate();
        }
    }  else if (strcmp(argv[1], "--reverse") == 0) {
        if (argc > 3 && strcmp(argv[2], "--file") == 0) {
            answer = FileReverseCalculate(argv[3]);
        }
        else if (argc > 4) {
            std::cerr << "Incorrect input" << std::endl;
            return EXIT_FAILURE;
        }
        else {
            answer = ConsoleReverseCalculate();
        }
    }
    else {
        std::cerr
                << "Please follow the rules and specify the desired flag first: --forward or -- reverse! If you also have a file, you should write --file and its name."
                << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Answer: " << answer << std::endl;
    return 0;
}
