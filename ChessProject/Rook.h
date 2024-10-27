#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const int currentRow, const int currentCol);
	int checkMovement(const int nextRow, const int nextCol, Board& board) override;
};