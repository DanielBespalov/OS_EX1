CC = gcc
CFLAGS = -fPIC
LDFLAGS = -shared
LIB_NAME = libpoisson.so

all: $(LIB_NAME) main

$(LIB_NAME): Poisson.o
	$(CC) $(LDFLAGS) -o $@ $^ -lm

Poisson.o: Poisson.c
	$(CC) $(CFLAGS) -c $<

main: Main.o $(LIB_NAME)
	$(CC) -o $@ Main.o -L. -lpoisson -lm -Wl,-rpath,.

Main.o: Main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(LIB_NAME) main *.o
