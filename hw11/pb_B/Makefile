# Variables
ARRAYDIR = ../pb_A
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
CPPFLAGS = -I$(ARRAYDIR)
LDLIBS = -lm
PROG = medArray
SRC = $(PROG).c $(ARRAYDIR)/array.c
HDR = $(ARRAYDIR)/array.h
OBJ = $(SRC:.c=.o)

# Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
