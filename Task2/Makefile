CC = gcc


Poisson: Poisson.o
	$(CC) -o $@ $^ -lm

Poisson.o: Poisson.c
	$(CC) -c $<

clean:
	rm -f Poisson *.o
