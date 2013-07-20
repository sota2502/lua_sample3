.PHONY: array debug

array: array.c luadebug.c
	gcc -Wall -o array array.c luadebug.c -llua

debug: array.c luadebug.c
	gcc -Wall -DDEBUG -o array array.c luadebug.c -llua
