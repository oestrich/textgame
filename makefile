EXEC = game

CC = gcc
CFLAGS = -Wall

SOURCES := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SOURCES))

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

clean:
	rm -f *.o
	rm -f $(EXEC)
