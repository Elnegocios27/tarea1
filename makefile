CC = gcc

CFLAGS = -Wall

TARGET = rps_game

OBJECTS = main.o game_logic.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
	
main.o: main.c game_logic.h
	$(CC) $(CFLAGS) -c main.c

game_logic.o: game_logic.c game_logic.h
	$(CC) $(CFLAGS) -c game_logic.c

.PHONY: clean
clean:
	del *.o $(TARGET).exe