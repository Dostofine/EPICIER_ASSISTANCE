CC = gcc
CFLAGS = -I include -Wall
SRC = SRC/clear.c  SRC/list.c  SRC/main.c  SRC/menu.c  SRC/new_day.c  SRC/Welcome.c SRC/create_csv.c
TARGET = program

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)