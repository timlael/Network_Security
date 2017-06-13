CC=gcc
CFLAGS=	-I. -g -Wall
OBJ =	rc5.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rc5: $(OBJ)
	$(CC) -o  $@  $^  $(CFLAGS)
