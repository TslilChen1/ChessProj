#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	int currentCol;
	int currentRow;
public:
	Pawn(const int currentRow, const int currentCol);
	int checkMovement(const int nextRow, const int nextCol, Board& board) override;
	bool checkFirstMovement(const int nextRow, const int nextCol, Board& board);
	bool checkEatingMovement(const int nextRow, const int nextCol, Board& board);
};