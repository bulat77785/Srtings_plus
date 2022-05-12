CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 
CCOV = -fprofile-arcs -ftest-coverage
GFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck -lm -lpthread


all: test gcov_report

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info s21_string_test.c tests

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o

s21_string.o: s21_string.c
	$(CC) -c s21_string.c 

s21_string_test.o: s21_string_test.check
	checkmk s21_string_test.check > s21_string_test.c
	$(CC) -c s21_string_test.c

test: s21_string.a s21_string_test.o
	$(CC) $(CCOV) s21_string_test.o s21_string.a -o tests -lcheck
	./tests
	
gcov_report: s21_string.a
	$(CC) $(GFLAGS) s21_string_test.c s21_string.c s21_string.a -L. s21_string.a $(TFLAGS) -o ./s21_string_test.out
	./s21_string_test.out
	lcov -t "s21_string_test" -o test.info -c -d .
	genhtml -o report test.info
	

check:
	cppcheck *.h *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./test

rebuild: clean all