#include <iostream>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "Nothing was read\n";
        return EXIT_FAILURE;
    } else {
        std::cout << "You entered " << argc - 1 << " arguments\n";
        for (std::size_t i = 1; i < argc; ++i) {
            std::cout << argv[i] << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
