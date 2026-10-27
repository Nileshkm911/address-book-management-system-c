CC ?= gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = address_book
SRCS = main.c contact.c file.c populate.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) a.out *.exe

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
