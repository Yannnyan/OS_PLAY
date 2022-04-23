CC = g++
CFLAGS = -Wall -g - pthread



process_limit: process_limit.o
	$(CC) $^ -o $@


%.o: %.c
	$(CC) -c $^ -o $@



PHONY: clean
clean:
	rm -f *.o process_limit


