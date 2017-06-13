CC=gcc
CFLAGS=	-I. -g -Wall
OBJ =	dh.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dh: $(OBJ)
	$(CC) -o  $@  $^  $(CFLAGS)
