CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = test_runner
SRCS = src/my_module.c test/test_my_module.c test/unity/unity.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS) log_output.txt

test: $(TARGET)
	./$(TARGET)