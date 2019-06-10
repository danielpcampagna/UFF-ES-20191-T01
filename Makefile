all:
	gcc -Wall -o main figuras/*.c estruturas/*.c main.c
	
clean:
	rm -f main *~