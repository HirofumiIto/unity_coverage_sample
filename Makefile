CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -fprofile-arcs -ftest-coverage -Itest/unity -Isrc

TARGET = test_runner

# 再帰的に .c ファイルを探す（find使用）
SRCS = $(shell find . -name '*.c')
# .c → build/ ディレクトリの .o に変換
OBJS = $(patsubst %.c, build/%.o, $(SRCS))

# .o ファイルの出力先に合わせたルールを追加
build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf build
	rm -f $(TARGET) log_output.txt

test: $(TARGET)
	./$(TARGET)
