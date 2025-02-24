CC = gcc
CFLAGS = -g -Wall -Wextra `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lm
SRCS = simulation.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = langton

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
