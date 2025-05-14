all: main_factorial.x

%.x: %.o factorial.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o *.x