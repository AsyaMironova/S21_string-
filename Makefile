CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -Wno-format
SRC=s21_string_functions/*.c
OBJ=$(SRC:.c=.o)
TSRC=tests/*.c
TOBJ=$(TSRC:.c=.o)
LIB_NAME=s21_string.a
NAME=s21_string
UNAME:=$(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS=-lcheck -lm -lrt -lpthread -lsubunit
endif
ifeq ($(UNAME), Darwin)
	LIBS=-lcheck
endif

all: $(LIB_NAME) test clean

clean:
	rm -rf $(OBJ)
	rm -rf $(TOBJ)
	rm -f *.o
	rm -f s21_string

test: $(OBJ) $(TOBJ)
	$(CC) $^ -o $(NAME) $(LIBS)
	./$(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o s21_string_functions

$(TOBJ): $(TSRC)
	$(CC) $(CFLAGS) -c $^
	mv *.o tests


rebuild: clean test

check_style:
	clang-format -n --style="Google" s21_string_functions/*.c
	clang-format -n --style="Google" tests/*.c

fix_style:
	clang-format -i --style="Google" s21_string_functions/*.c
	clang-format -i --style="Google" tests/*.c

gcov_report:

.PHONY: all clean test gcov_report
