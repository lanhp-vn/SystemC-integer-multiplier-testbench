# Edited for F24 by VG
# Makefile for ECPS 203, Assignment 3 (by Zhongqi Cheng)

SYSTEMC = /users/ugrad/2017/summer/ecps203/public/SystemC_F24

INCLUDE = -I. -I$(SYSTEMC)/include
LIBRARY = $(SYSTEMC)/lib-linux64
CFLAG = $(INCLUDE) -L$(LIBRARY) -Xlinker -R -Xlinker $(LIBRARY) -lsystemc -O2

CC = g++
RM = rm -f

TARGET	= hw3
OFILES = main.o \
	mon.o \
	stim.o \
	mult.o        

all: $(TARGET)

test: hw3
	./hw3
	
clean:
	$(RM) *.o $(TARGET)


hw3: $(OFILES)
	$(CC) $^ $(CFLAG) -o $@

main.o : main.cpp top.h stim.h mult.h mon.h
	$(CC) -c main.cpp $(INCLUDE) $(CFLAG) -O2 -o $@
	
stim.o : stim.cpp stim.h
	$(CC) -c stim.cpp $(INCLUDE) $(CFLAG) -O2 -o $@
	
mon.o : mon.cpp mon.h 
	$(CC) -c mon.cpp $(INCLUDE) $(CFLAG) -O2 -o $@
	
mult.o : mult.cpp mult.h
	$(CC) -c mult.cpp $(INCLUDE) $(CFLAG) -O2 -o $@
