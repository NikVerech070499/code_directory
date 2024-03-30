.phony: all

all:program

program:average.cpp num_threads.cpp
	g++ average.cpp num_threads.cpp -O3 -pthread -o program -Werror -Wall -Wextra -Wpedantic
