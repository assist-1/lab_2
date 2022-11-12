#include <iostream>

void reverse(char** argv, int file, int math);

int main(int argc, char** argv) {
	int file = 0;
	int metod = 0;
	int math = 0;
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][3] == 'i') {
				for (int i = 1; i < argc; i++) {
					if (argv[i][0] != '-') {
						file = i;
					}
				}
			}
			else if (argv[i][2] == 'r') {
				metod = 1;
			}
			else if (argv[i][3] == 'o') {
				metod = 2;
			}
		}
		else {
			math = i;
		}
	}
	if (metod == 1) {
		reverse(argv, file, math);
	}
	else if (metod == 2) {
		//forward(argv, file, math);
	}
	else {
		std::cout << metod << "Input error 1" << std::endl;
	}
	return 0;
}

void reverse(char** argv, int file, int math) {
	char m[1024];
	int j = 0;
	if (file != 0 || math != 0) {
		if (file != 0) {
			FILE* fp;
			if ((fp = fopen(argv[file], "r")) == NULL) {
				std::cout << "File doesn't exist" << std::endl;
			}
			else {
				while ((m[j] = fgetc(fp)) != EOF) {
					j++;
				}
				fclose(fp);
			}
			//calculation(m);
		}
	}
	else {
		std::cout << "Input error 2" << std::endl;
	}

}