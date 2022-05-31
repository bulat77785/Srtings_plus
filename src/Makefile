CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CCOV = -fprofile-arcs -ftest-coverage
GFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck
#ASAN = -g -fsanitize=address

all: clean test s21_string.a gcov_report

s21_string.a: s21_string.o s21_sprintf.o helpers.o
	ar rcs s21_string.a s21_string.o s21_sprintf.o helpers.o
	ranlib s21_string.a

s21_string.o: s21_string.c
	$(CC) $(ASAN) $(CFLAGS) -c s21_string.c

s21_sprintf.o: s21_sprintf.c
	$(CC) $(ASAN) $(CFLAGS) -c s21_sprintf.c

helpers.o: helpers.c
	$(CC) $(ASAN) $(CFLAGS) -c helpers.c

s21_string_test.o: s21_string_test.c
	$(CC) $(ASAN) $(CFLAGS) -c s21_string_test.c

test: s21_string.a s21_string_test.o
	$(CC) $(ASAN) $(CCOV) s21_string_test.o s21_string.a -o test $(TFLAGS)
	./test
	
gcov_report: s21_string.a s21_string_test.o
	$(CC) $(ASAN) $(GFLAGS) -g s21_string_test.c s21_string.c s21_sprintf.c helpers.c s21_string.a -L. s21_string.a $(TFLAGS) -o ./s21_string_test.out
	./s21_string_test.out
#	gcov -f s21_string.gcda s21_sprintf.gcda helpers.gcda
#	gcovr -b
#	gcovr
#	gcovr --html-details -o report.html
	lcov -t "s21_string_test" -o test.info -c -d .
	genhtml -o report test.info

check:
	cppcheck *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c
#	CK_FORK=no leaks --atExit -- ./test
#   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info test report *.out.dSYM

rebuild: clean all

