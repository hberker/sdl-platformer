CC = g++
FLAGS = -I /usr/include/SDL2 
TARGET = snake
EXEC = *.cpp

default: main.o

main.o: $(EXEC)
	$(CC) $(FLAGS) $(EXEC) -o $(TARGET) -lSDL2  -lSDL2_image

run: main.o
	./$(TARGET)
	-rm $(TARGET)