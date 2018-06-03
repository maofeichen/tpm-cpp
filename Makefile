CC = g++
CF = -g
LF = -g

tpm : main.o log.o
	$(CC) -o tpm main.o log.o $(LF) 

main.o : main.cpp
	$(CC) -c main.cpp $(CF) 

log.o : log.cpp
	$(CC) -c log.cpp $(CF) 
	
clean : 
	rm -rf *.o tpm