CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

Main: Main.o Function.o NonlinearSolver02.o CouponBond.o
	$(CC) $(CFLAGS) -o Main Main.o NonlinearSolver02.o CouponBond.o

Main.o: Main.cpp Function.h NonlinearSolver02.h CouponBond.h
	$(CC) $(CFLAGS) -c Main.cpp

CouponBond.o: NonlinearSolver02.h CouponBond.h CouponBond.cpp
	$(CC) $(CFLAGS) -c CouponBond.cpp
	
NonlinearSolver02.o: NonlinearSolver02.h Function.h NonlinearSolver02.cpp 
	$(CC) $(CFLAGS) -c NonlinearSolver02.cpp

Function.o: Function.h
	
clean:
	rm -rf Main.o Function.o NonlinearSolver02.o CouponBond.o



