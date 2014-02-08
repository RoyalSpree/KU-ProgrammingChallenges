ADVANCED: main.o MatrixRoads.o
	g++ main.o MatrixRoads.o -o ADVANCED

MatrixRoads.o: MatrixRoads.h MatrixRoads.c++
	g++ -c -g MatrixRoads.c++

main.o:	main.c++
	g++ -c -g main.c++

clean:
	rm ADVANCED *.o *~
