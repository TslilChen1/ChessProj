#pragma once
#include "Piece.h"
#include <string>
#include <array>
#define SIZE 8

class Piece;

class Board
{
private:
	int currentPlayer;
	std::array<std::array<char, SIZE>, SIZE> board;
public:
	Board();
	void changeBoardPosition(Piece* piece, const int nextRow, const int nextCol);
	void changeTurn();
	bool isCheckForOtherPlayer(Piece* piece, const int nextRow, const int nextCol, const int currRow, const int currCol);
	bool isSelfCheck(Piece* piece, const int nextRow, const int nextCol, const int currRow, const int currCol);
	int getCurrentPlayer();
	//bool isCheckmate(Piece* piece, int currRow, int currCol);
	std::array<std::array<char, SIZE>, SIZE> getBoard();
	void printBoard();
};