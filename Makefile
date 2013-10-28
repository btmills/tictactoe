CC = g++
CFLAGS = -Wall -std=c++11 -c
LFLAGS = -Wall

OBJS = Board.o ComputerPlayer.o Game.o HumanPlayer.o IPlayer.o RandomPlayer.o Square.o Triple.o

ttt: $(OBJS) main.cpp
	$(CC) $(LFLAGS) $(OBJS) main.cpp -o ttt

Board.o: Board.h Board.cpp
	$(CC) $(CFLAGS) Board.cpp

ComputerPlayer.o: ComputerPlayer.h ComputerPlayer.cpp
	$(CC) $(CFLAGS) ComputerPlayer.cpp

Game.o: Game.h Game.cpp
	$(CC) $(CFLAGS) Game.cpp

HumanPlayer.o: HumanPlayer.h HumanPlayer.cpp
	$(CC) $(CFLAGS) HumanPlayer.cpp

IPlayer.o: IPlayer.h IPlayer.cpp
	$(CC) $(CFLAGS) IPlayer.cpp

RandomPlayer.o: RandomPlayer.h RandomPlayer.cpp
	$(CC) $(CFLAGS) RandomPlayer.cpp

Square.o: Square.h Square.cpp
	$(CC) $(CFLAGS) Square.cpp

Triple.o: Triple.h Triple.cpp
	$(CC) $(CFLAGS) Triple.cpp

clean:
	rm -rf *.o *~ ttt
