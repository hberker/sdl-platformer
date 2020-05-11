CC = g++
FLAGS =  -std=c++14 -lSDL2 -lSDL2_image
TARGET = topdown.out
EXEC = *.cpp

default: main.o

main.o: $(EXEC)
	$(CC) $(FLAGS) $(EXEC) -o $(TARGET) 

run: main.o
	./$(TARGET)

clean:
	-rm $(TARGET)
	rm -f *.o

.PHONY: clean