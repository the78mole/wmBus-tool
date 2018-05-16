INC= -I .   -I ./include

CC     = gcc
CPP    = g++
CFLAGS = -Wall


all:	 wmbus-tool
		
wmbus-tool:	wmbus-tool.o wmbus.o
	$(CC) -o wmbus-tool wmbus-tool.o wmbus.o -lpthread 

wmbus-tool.o: src/wmbus-tool.c
	$(CC) $(CFLAGS) $(INC) -pthread -c src/wmbus-tool.c

wmbus.o:	src/wmbus.c
	$(CC) $(CFLAGS) $(INC) -pthread -c src/wmbus.c

clean: 			
	@rm -f wmbus-tool wmbus-tool.o wmbus.o
	@echo Clean done
