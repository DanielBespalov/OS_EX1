CC = gcc


all: 

add2PB: add2PB.o
	$(CC) -o $@ $^ -lm

add2PB.o: add2PB.c
	$(CC) -c $<

clean:
	rm -f add2PB *.o
