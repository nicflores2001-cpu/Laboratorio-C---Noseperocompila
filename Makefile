CC      = gcc
CFLAGS  = -Wall -Wextra -g -Iinclude
SRC     = main.c src/artemis.c src/validaciones.c
OUT     = main.exe

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) -lm

clean:
	del $(OUT)