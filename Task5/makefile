q5: q5.o
	gcc -o q5 q5.o -pg

q5.o: q5.c
	gcc -c -pg q5.c


clean:
	rm -f q5 *.o gmon.out analysis1.txt analysis2.txt analysis3.txt

profile: q5
	./q5 25 100
	gprof q5 gmon.out > analysis1.txt
	cat analysis1.txt
	
	./q5 25 1000
	gprof q5 gmon.out > analysis2.txt
	cat analysis2.txt
	
	./q5 25 10000
	gprof q5 gmon.out > analysis3.txt
	cat analysis3.txt
