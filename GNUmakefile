OBJS=calcfunc.o main.o

answer: $(OBJS)
	g++ -o answer $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) answer