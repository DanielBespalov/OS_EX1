q4: q4.o
	gcc -o q4.c q4.o -fprofile-arcs -ftest-coverage

q4.o: q4.c
	gcc -c q4.c -fprofile-arcs -ftest-coverage

clean:
	rm -f q4 *.o
