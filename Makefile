G++ = g++ -Wall -Werror -Wextra

all: clean lab tests

lab:
	$(G++) lab.cpp -o lab

tests:
	./lab --forward --file forward1.txt
	./lab --reverse --file reverse1.txt
	./lab --forward --file forward2.txt
	./lab --reverse --file reverse2.txt
	./lab --reverse --file doesnot_exist.txt

clean:
	rm -rf lab
