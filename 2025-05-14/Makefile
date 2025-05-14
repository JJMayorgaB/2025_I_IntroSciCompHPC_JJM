CXXFLAGS = -fsanitize=address,undefined,leak -fprofile-arcs -ftest-coverage

all: main_factorial.x

%.x: %.o factorial.o
	g++ $(CXXFLAGS)  $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

test:	test_factorial.x
	./$< 

clean:
	rm -f *.o *.x *a.out *.gcov *.gcno 