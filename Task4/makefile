# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -fprofile-arcs -ftest-coverage -Wall -Wextra

# Targets and files
TARGET = Q4
SOURCE = Q4.c
OBJECT = Q4.o

# Default target
all: $(TARGET)

# Link the target
$(TARGET): $(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT) $(CFLAGS)

# Compile the object file
$(OBJECT): $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Generate coverage report
coverage: run
	gcov $(SOURCE)

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJECT) *.gcno *.gcda *.gcov

.PHONY: all run coverage clean
