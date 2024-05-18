CC = gcc
CFLAGS = -Wall -w -g

Poisson: Poisson.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

Poisson.o: Poisson.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f Poisson *.o
