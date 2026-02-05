CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/menu.c src/welcome.c
OBJ = $(SRC:.c=.o)

all: app

app: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o app

clean:
	rm -f *.o app
