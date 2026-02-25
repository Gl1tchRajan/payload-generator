CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/*.c

OUT = payload

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) *.bin *.txt
