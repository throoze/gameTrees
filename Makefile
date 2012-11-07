CC = g++
LibreriasC = arbolesJuego.cpp
#Flags = -std=c++11

all:
	$(CC) $(Flags) $(LibreriasC) main.cc  -o othello
