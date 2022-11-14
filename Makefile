OBJS=Lab2.o main.o

result: $(OBJS)
	g++ -o result $(OBJS)

.PHONY: clean
clean:
	$ (RM)  $(OBJS)

distclean: clean
	$ (RM) result