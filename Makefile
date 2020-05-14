CC = gcc
DEPS = init.h fcfs.h sjf.h
OBJ = program.o
WIN = del
NIX = rm -f

program: $(OBJ) $(DEPS)
	$(CC) $(OBJ) -o program

%.o: %.c
	$(CC) -c $<

.PHONY: clean

clean:
	$(NIX) output.txt program.exe $(OBJ)