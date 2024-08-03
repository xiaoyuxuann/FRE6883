CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

OptionPricer05: OptionPricer05.o BinomialTreeModel.o Option05.o ButterflySpread.o StrangleSpread.o DoubDigitOpt.o
	$(CC) $(CFLAGS) -o OptionPricer05 OptionPricer05.o BinomialTreeModel.o Option05.o ButterflySpread.o StrangleSpread.o DoubDigitOpt.o

OptionPricer05.o: OptionPricer05.cpp BinomialTreeModel.h Option05.h StrangleSpread.h ButterflySpread.h DoubDigitOpt.h
	$(CC) $(CFLAGS) -c OptionPricer05.cpp

Option05.o: BinomialTreeModel.h Option05.h Option05.cpp 
	$(CC) $(CFLAGS) -c Option05.cpp
	
BinomialTreeModel.o: BinomialTreeModel.h BinomialTreeModel.cpp
	$(CC) $(CFLAGS) -c BinomialTreeModel.cpp

StrangleSpread.o: Option05.h StrangleSpread.h StrangleSpread.cpp 
	$(CC) $(CFLAGS) -c StrangleSpread.cpp

ButterflySpread.o: Option05.h ButterflySpread.h ButterflySpread.cpp 
	$(CC) $(CFLAGS) -c ButterflySpread.cpp

DoubDigitOpt.o: Option05.h DoubDigitOpt.h DoubDigitOpt.cpp 
	$(CC) $(CFLAGS) -c DoubDigitOpt.cpp
	
clean:
	rm -rf OptionPricer05 *.o BinomialTreeModel.o Option05.o ButterflySpread.o StrangleSpread.o DoubDigitOpt.o



