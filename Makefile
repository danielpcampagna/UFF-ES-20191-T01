all:
	gcc -Wall -o main figuras/*.c main.c
	
clean:
	rm -f main *~