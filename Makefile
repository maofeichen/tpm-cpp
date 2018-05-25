tpm : main.o log.o
	g++ -o tpm main.o -g

main.o : main.cpp
	g++ -c main.cpp -g

log.o : log.cpp
	g++ -c log.cpp -g
	
clean : 
	rm -rf *.o tpm