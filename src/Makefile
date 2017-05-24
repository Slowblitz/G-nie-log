all: E-gam
	 ./E-gam
	 

E-gam: Perso.o Case.o Map.o main.o
	g++ -o $@ $^

Perso.o: Perso.cpp Case.h Map.h
	g++ -o $@ -c $<

Case.o: Case.cpp
	g++ -o $@ -c $<

Map.o: Map.cpp Perso.h Case.h
	g++ -o $@ -c $<

main.o -o:	main.cpp Map.h
	g++ -o $@ -c $<

clean:
	rm -rf *.o

mrproper: clean
	rm -rf E-gam