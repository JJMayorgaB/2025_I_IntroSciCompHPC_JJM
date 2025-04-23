figura.pdf	:	script.gp data.txt
	gnuplot $<

%.x	:	%.cpp
	g++ $< -o $@

data.txt	:	sumupdown.x
	./$< > $@

clean	:
	rm -f *.x a.out *.txt *.pdf