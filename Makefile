all:
	gcc -Wall -o main figuras/*.c estruturas/*.c libs/*.c main.c forms/*.c -lm

run:
	./main
	
clean:
	rm -f main *~