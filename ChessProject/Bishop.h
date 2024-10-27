#pragma once
#include "Piece.h"
#include "Board.h"

class Bishop : public Piece
{
private:
	int currentRow;
	int currentCol;
public:
	Bishop(const int currentRow, const	int currentCol);
	int checkMovement(const int nextRow, const int nextCol, Board& board) override;
};