CC = gcc

all: libpoisson.so main

libpoisson.so: Poisson.o
	$(CC) -shared -o $@ $^ -lm

Poisson.o: Poisson.c
	$(CC)  -c $<

main: Main.o libpoisson.so
	$(CC) -o $@ Main.o -L. -lpoisson -lm -Wl,-rpath,. 

Main.o: Main.c
	$(CC)  -c $<

clean:
	rm -f libpoisson.so main *.o


# -L.: Add the current directory to the library search path.
# -lpoisson: Link with the libpoisson library.
# -lm: Link with the math library.
# -Wl,-rpath,.: Set the runtime library search path to the current directory.