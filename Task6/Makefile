CC = gcc

TARGETS = add2PB findPhone

all: $(TARGETS)

add2PB: add2PB.o
	$(CC)  -o $@ $^

findPhone: findPhone.o
	$(CC)  -o $@ $^

add2PB.o: add2PB.c
	$(CC)  -c $<

findPhone.o: findPhone.c
	$(CC)  -c $<

clean:
	rm -f $(TARGETS) *.o PhoneBook.txt

# PHONY targets are not files
.PHONY: all clean
