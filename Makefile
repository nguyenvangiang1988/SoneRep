filelib: main.o filelib.o
	gcc -o filelib main.o filelib.o
main.o: main.c filelib.h
	gcc -c main.c
filelib.o: filelib.c filelib.h
	gcc -c filelib.c
