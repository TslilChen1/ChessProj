#pragma once

#include "Piece.h"

class Board;

class King : public Piece
{
private:
	int currentRow;
	int currentCol;
public:
	King(const int currentRow, const int currentCol);
	int checkMovement(const int nextRow, const int nextCol, Board& board) override;
};

