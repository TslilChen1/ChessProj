#pragma once
#include "Piece.h"

class Knight : public Piece
{
private:
	int currentRow;
	int currentCol;
public:
	Knight(const int currentRow, const int currentCol);
	int checkMovement(const int nextRow, const int nextCol, Board& board) override;
};