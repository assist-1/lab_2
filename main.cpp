#include <cstring>
#include <iostream>

void usage() {
    std::cerr << "Usage: lab_2 [--forward] [--file filename] [--reverse]\n"
              << "  --forward - read mathematical expression from stdin\n"
              << "  --file filename - read mathematical expression from file\n"
              << "  --reverse - use reverse Polish notation" << std::endl;
}

int main(int argc, char **argv) {
    bool forward = false;
    bool file = false;
    char *filename = nullptr;
    bool reverse = false;
    for (std::size_t i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--forward") == 0) {
            forward = true;
        } else if (std::strcmp(argv[i], "--file") == 0) {
            file = true;
            filename = argv[i + 1];
            ++i;
        } else if (std::strcmp(argv[i], "--reverse") == 0) {
            reverse = true;
        } else {
            std::cerr << "Unexpected argument: " << argv[i] << "\n";
            usage();
            return EXIT_FAILURE;
        }
    }
    if (file == forward) {
        std::cerr << "You have to choose --forward or --file\n";
        usage();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
