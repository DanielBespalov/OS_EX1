CC = gcc
CFLAGS = -Wall -w 

Poisson: Poisson.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

Poisson.o: Poisson.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f Poisson *.o
