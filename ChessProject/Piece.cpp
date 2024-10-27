#include "Piece.h"

Piece::Piece(const int currentRow, const int currentCol)
{
	this->currentCol = currentCol;
	this->currentRow = currentRow;
}

int Piece::getCurrentCol()
{
	return this->currentCol;
}

int Piece::getCurrentRow()
{
	return this->currentRow;
}


