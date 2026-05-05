CC=gcc
AR=ar
UNAME_S := $(shell uname -s)
CFLAGS=-std=c11 -Wall -Wextra -Werror -pedantic

TEST_CFLAGS=-std=c11
TEST_FLAGS=-lcheck -lm
ifneq (,$(findstring MINGW,$(UNAME_S)))
    TEST_CFLAGS+=-D_GNU_SOURCE
	CFLAGS+=-D_GNU_SOURCE
else
    TEST_FLAGS+=-lsubunit
endif

TARGET=s21_string.a
OBJS=s21_string.o s21_sprintf_ext.o

TEST_PROG=test
TEST_SRC=test.c

TEST_SUITS_DIR=test-suits
TEST_SRCS=$(wildcard $(TEST_SUITS_DIR)/*.c)
TEST_OBJS=$(TEST_SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET) $(TEST_SRC) $(TEST_OBJS)
	$(CC) $(TEST_CFLAGS) $(TEST_SRC) $(TEST_OBJS) -L. -l:s21_string.a -o $(TEST_PROG) $(TEST_FLAGS)
	./$(TEST_PROG)

gcov_report: $(TARGET)
	@$(CC) $(CFLAGS) --coverage s21_string.c $(TEST_SRC) $(TEST_SRCS) $(TARGET) -L. $(TARGET) $(TEST_FLAGS) -o gcov.out
	@./gcov.out
	@lcov -t "TEST" -o test_full.info -c -d .
	@lcov --extract test_full.info '*/s21_string.c' --output-file test.info
	@genhtml test.info -o html
	@open html/index.html

memtest:
	@valgrind --tool=memcheck --leak-check=yes -q ./test

clean:
	rm -rf $(OBJS) $(TARGET) $(TEST_PROG) *.gcda *.gcno html *.info gcov.out $(TEST_OBJS)
