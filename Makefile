CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/generator.c src/crypto.c src/output.c src/logger.c

OUT = payload

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) *.bin *.txt
