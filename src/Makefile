CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
TEST_FLAGS = -lcheck -lpthread -pthread -lm 
SRC = $(wildcard *.c) $(wildcard ./add_funk/*.c)

OBJ = $(patsubst %.c, %.o, $(SRC))

TEST_SRC = $(wildcard ./test/*.c)

OBJS_PATHES = $(SRCS:.c=.o)

TEST_OBJ = $(patsubst ./test/%.c, ./test/%.o, $(TEST_SRC))

OS := $(shell uname)
ifeq ($(OS),Linux) # определяем ОС
TEST_LIBS = -lcheck -lm -lsubunit
else
TEST_LIBS = -lcheck
endif

all : clean s21_matrix.a test gcov_report

test.a: $(TEST_OBJ)
	ar r test.a $^	

s21_matrix.a: $(OBJ)
	ar rc s21_matrix.a $^
	ranlib s21_matrix.a
	rm -rf *.o

test: s21_matrix.a test.a
	$(CC) test.a s21_matrix.a $(TEST_FLAGS) -o test.out
	./test.out

gcov_report: clean test.a
	$(CC) -fprofile-arcs -ftest-coverage test.a $(SRC) -o test.out $(TEST_FLAGS)
	./test.out
	lcov -t "s21_matrix.a" -o s21_matrix.a.info -c -d .
	genhtml -o gcov_report s21_matrix.a.info
	rm -rf *.gcno *.gcda
	open ./gcov_report/index.html

check_linters:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h add_funk/*.c add_funk/*.h
	cppcheck *.c *.h add_funk/*.c add_funk/*.h
	rm CPPLINT.cfg

cppcheck:
	cppcheck --enable=all  --check-config --suppress=missingIncludeSystem *.c *.h add_funk/*.c add_funk/*.h test/*.c *.h

clean :
	rm -rf *.o *.a gcov *.gch *.gcda *.gcno *.info *.out *.cfg report .clang-format gcov_report
	rm -f ./add_funk/*.o
	rm -f ./test/*.o



rebuild : clean all

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -i -n *.c *.h add_funk/*.c add_funk/*.h
	rm .clang-format

clang :
	clang-format -i --style=Google *.c *.h add_funk/*.c add_funk/*.h
	clang-format -n --style=Google *.c *.h add_funk/*.c add_funk/*.h