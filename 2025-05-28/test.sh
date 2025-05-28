gcc -Wall -pg -g test.c -o test_gprof.x

./test_gprof.x

gprof test_gprof.x gmon.out > analysis.txt