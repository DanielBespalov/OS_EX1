q5: q5.o
	gcc -o q5 q5.o -pg

q5.o: q5.c
	gcc -c -pg q5.c

run_kk: q5
	./q5 25 100

run_kkk: q5
	./q5 25 1000

run_kkkk: q5
	./q5 25 10000

clean:
	rm -f q5 *.o gmon.out analysis.txt

profile: q5
	./q5 25 100
	./q5 25 1000
	./q5 25 10000
	gprof q5 gmon.out > analysis.txt
	cat analysis.txt
