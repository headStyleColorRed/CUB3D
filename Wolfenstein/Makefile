CC = gcc
OBJECTS = main.o

9_1 : $(OBJECTS)
	$(CC) $(OBJECTS) -o 9_1

main.o : main.c 
	$(CC) -g -c main.c 

.PHONY : clean
clean : 
	rm $(OBJECTS)