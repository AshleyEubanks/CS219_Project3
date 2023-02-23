Proj1: driver.o 
	g++ -o Proj1 driver.o

driver.o: driver.cpp
	g++ -c driver.cpp

clean: 
	rm *.o Proj1