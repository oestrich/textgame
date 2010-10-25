EXEC = game

CC = gcc
CFLAGS = -Wall

SOURCES := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SOURCES))

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

clean:
	rm -f $(OBJS) 
	rm -f $(EXEC)
