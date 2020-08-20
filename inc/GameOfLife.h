#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{
public:
	GameOfLife();
	int row;
	int col;
	std::vector<std::vector<Cell>> Board;
	void start();
	void stop();
	void advance();
	//void neighborhood(int, int);
	void neighborhood();
	ucm::json getBoard();

};

#endif
