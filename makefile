Proj3: driver.o operations.o
	g++ -o Proj3 driver.o operations.o

driver.o: driver.cpp operations.h
	g++ -c driver.cpp

operations.o: operations.h operations.cpp
	g++ -c operations.cpp

clean: 
	rm *.o Proj3