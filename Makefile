CFLAGS = -Wall 

make:
	gcc $(CFLAGS) joc_2048.c functions.c -o joc_2048.exec -lcurses

run:
	./joc_2048.exec

clear:
	rm -f joc_2048.exec