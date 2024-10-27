#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const int currentRow, const int currentCol);
	int checkMovement(const int nextRow, const int nextCol, Board& board) override;
};