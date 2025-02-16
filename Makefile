CC=gcc
FLAGS=-Wall -Werror -Wextra
BUILD=../build

all: graph

graph:
	$(CC) $(FLAGS) *.c -o $(BUILD)/graph

rebuild: clean graph

clean:
	rm -rf $(BUILD)/graph
