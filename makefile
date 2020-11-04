mydictionary: MainDSA.o DSA1.o
	g++ MainDSA.o DSA1.o -o mydictionary
main.o: MainDSA.cpp
	g++ -c MainDSA.cpp
DSA1.o: DSA1.cpp DSA1.h
	g++ -c DSA1.cpp
clean:
	rm *.o mydictionary

