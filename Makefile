CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -fprofile-arcs -ftest-coverage -Itest/unity
TARGET = test_runner
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS) log_output.txt

test: $(TARGET)
	./$(TARGET)