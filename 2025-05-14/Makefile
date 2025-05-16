CXXFLAGS = -fsanitize=address,undefined,leak -fprofile-arcs -ftest-coverage

all: main_factorial.x

%.x: %.o factorial.o
	g++ $(CXXFLAGS)  $^ -o $@ 

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

test:	test_factorial.x
	./$< 

coverage: test_function.x coverage/index.html
	./$<
	~/.local/bin/gcovr factorial.cpp test_function.cpp
	~/.local/bin/gcovr --html-details coverage.html
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage
	@echo "open file coverage/index.html" 

clean:
	rm -f *.o *.x *a.out *.gcov *.gcno 