CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g

PROG = lifo_test
SRC = lifo_test.c lifo.c
HDR = lifo.h
OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
tags: $(SRC) $(HDR)
	ctags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
