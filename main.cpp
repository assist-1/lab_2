#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    bool forward = false;
    bool file = false;
    char *file_name = nullptr;
    bool reverse = false;

    if (argc == 1) {
        std::cerr << "No arguments\n";
        return EXIT_FAILURE;
    }
    for (std::size_t i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--forward") == 0) {
            forward = true;
        } else if (std::strcmp(argv[i], "--file") == 0) {
            file = true;
            ++i;
            file_name = argv[i];
        } else if (std::strcmp(argv[i], "--reverse") == 0) {
            reverse = true;
        }
    }
    if (file) {
        std::ifstream ifs(file_name);
    }
    return EXIT_SUCCESS;
}
