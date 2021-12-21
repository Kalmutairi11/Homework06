GPP=g++ -std=c++17

all: main.o
	$(GPP) main.o -o list_test

list: list_example.o
	$(GPP) list_example.o -o example_list

main.o: main.cpp GeneralStack.hpp GeneralQueue.hpp
	$(GPP) -c main.cpp

list_example.o:
	$(GPP) -c list_example.cpp

clean:
	rm main.o
	rm list_test

clean_list:
	rm list_example.o
	rm example_list
