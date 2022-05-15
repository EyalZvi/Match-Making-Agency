executable_2: main.o String.o Client.o

	g++ main.o String.o Client.o -o  executable_2



main.o: main.cpp

	g++ -c main.cpp



String.o: String.cpp

	g++ -c String.cpp



Client.o: Client.cpp

	g++ -c Client.cpp



clean:

	rm *.o executable_2