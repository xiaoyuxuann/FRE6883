CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

OptionPricer08: OptionPricer08.o BinomialTreeModel.o Option08.o
	$(CC) $(CFLAGS) -o OptionPricer08 OptionPricer08.o BinomialTreeModel.o Option08.o

OptionPricer08.o: OptionPricer08.cpp BinomialTreeModel.h Option08.h
	$(CC) $(CFLAGS) -c OptionPricer08.cpp

Option08.o: BinomialTreeModel.h Option08.h Option08.cpp
	$(CC) $(CFLAGS) -c Option08.cpp
	
BinomialTreeModel02.o: BinomialTreeModel.h BinomialTreeModel.cpp
	$(CC) $(CFLAGS) -c BinomialTreeModel.cpp
	
clean:
	rm -rf OptionPricer08.o Option08.o BinomialTreeModel.o



