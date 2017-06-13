CC = gcc
EXECS = size_types endian

endian : endian.c
	$(CC) -o endian endian.c
size_types : size_types.c
	$(CC) -o size_types size_types.c
size_types.h : size_types
	size_types

clean :
	rm $(EXECS) size_types.h
