CC = gcc
CFLAGS = -Wall -w 

code: code.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

code.o: code.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f code *.o
