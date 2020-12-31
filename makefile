CC = gcc
FLAGS = -Wall


all: isort txtfind

isort: isort.c
	$(CC) $(FLAGS) -o isort isort.c

txtfind: txtfind.c
	$(CC) $(FLAGS) -o txtfind txtfind.c
	
.PHONY: all clean

clean:
	rm isort txtfind
