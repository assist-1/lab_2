#include <iostream>

int main(int argc, char** argv) {
	int i = 1;
	while ((argc - i) > 0) {
		std::cout << argv[argc - i] << " ";
		i++;
	}
	std::cout << std::endl;
}