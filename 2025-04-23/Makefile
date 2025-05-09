SOURCES := $(wildcard *.cpp)
OBJETS =  $(SOURCES:.cpp=.o)


figura.pdf	:	script.gp data.txt
	gnuplot $<

%.o	:	%.cpp
	g++ $< -c 

sumupdown.x	: $(OBJETS)
	g++ $^ -o $@

data.txt	:	sumupdown.x
	./$< > $@

clean	:
	rm -f *.x a.out *.txt *.pdf *.o