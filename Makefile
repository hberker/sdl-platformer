CC = g++
FLAGS =  -std=c++14 -lSDL2 -lSDL2_image
TARGET = snake
EXEC = *.cpp

default: main.o

main.o: $(EXEC)
	$(CC) $(FLAGS) $(EXEC) -o $(TARGET) 

run: main.o
	./$(TARGET)
	-rm $(TARGET)