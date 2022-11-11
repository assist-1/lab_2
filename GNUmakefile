OBJS=func.o main.o

prog: $(OBJS)
  g++ -o result $(OBJS)

.PHONY: clean
clean:
  $(RM) $(OBJS)

distclean: clean
  $(RM) prog
