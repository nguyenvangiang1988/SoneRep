math: main.o math.o
	gcc -o math main.o math.o
main.o: main.c math.h
	gcc -c main.c
math.o: math.c math.h
	gcc -c math.c
