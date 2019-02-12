# Makefile for the $(class) class
OBJS	= blackjack.o deck.o card.o
SOURCE	= blackjack.cpp deck.cpp card.cpp
HEADER	=
OUT	= project
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

project.o: blackjack.cpp
	$(CC) $(FLAGS) blackjack.cpp

deck.o: deck.cpp
	$(CC) $(FLAGS) deck.cpp

card.o: card.cpp
	$(CC) $(FLAGS) card.cpp


clean:
	rm -f $(OBJS) $(OUT)
