CC = gcc
CFLAGS = -Wall -w -g

q4: q4.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

q4.o: q4.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f q4 *.o