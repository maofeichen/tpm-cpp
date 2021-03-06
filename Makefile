CC = g++
CF = -g -Wall -Wno-reorder
LF = -g

all : tpm

tpm : main.o log.o record.o util.o flag.o
	$(CC) -o tpm main.o log.o record.o flag.o util.o $(LF) 

main.o : main.cpp
	$(CC) -c main.cpp $(CF) 

log.o : log.cpp
	$(CC) -c log.cpp $(CF) 

record.o : record.cpp
	$(CC) -c record.cpp $(CF)	

flag.o : flag.cpp
	$(CC) -c flag.cpp $(CF)

util.o : util.cpp
	$(CC) -c util.cpp $(CF)

clean : 
	rm -rf *.o tpm