CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

OptionPricer05: OptionPricer05.o BinomialTreeModel.o Option05.o
	$(CC) $(CFLAGS) -o OptionPricer05 OptionPricer05.o BinomialTreeModel.o Option05.o

OptionPricer05.o: OptionPricer05.cpp BinomialTreeModel.h Option05.h
	$(CC) $(CFLAGS) -c OptionPricer05.cpp

Option05.o: BinomialTreeModel.h Option05.h Option05.cpp
	$(CC) $(CFLAGS) -c Option05.cpp
	
BinomialTreeModel.o: BinomialTreeModel.h BinomialTreeModel.cpp
	$(CC) $(CFLAGS) -c BinomialTreeModel.cpp
	
clean:
	rm -rf OptionPricer05 *.o



