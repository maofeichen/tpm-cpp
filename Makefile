CC = g++
CF = -g -Wall -Wno-reorder
LF = -g

tpm : main.o log.o record.o
	$(CC) -o tpm main.o log.o $(LF) 

main.o : main.cpp
	$(CC) -c main.cpp $(CF) 

log.o : log.cpp
	$(CC) -c log.cpp $(CF) 

record.o : record.cpp
	$(CC) -c record.cpp $(CF)	

clean : 
	rm -rf *.o tpm