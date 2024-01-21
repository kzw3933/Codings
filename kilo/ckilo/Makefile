.PHYON: all

CC = gcc
CFLAGS = -g -Wall -Wextra -pedantic -std=c99


all: kilo

kilo: kilo.c
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f kilo
