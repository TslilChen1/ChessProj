#pragma once
#include "Board.h"
class Board;

enum piecesTypes 
{
	ROOK = 'r',   
	KNIGHT = 'n',  
	BISHOP = 'b',   
	PAWN = 'p', 
	KING = 'k', 
	QUEEN = 'q', 
	ROOK_C = 'R',
	KNIGHT_C = 'N',
	BISHOP_C = 'B',
	PAWN_C = 'P',
	KING_C = 'K',
	QUEEN_C = 'Q',
	EMPTY = '#'
};


class Piece
{
private:
	int currentCol;
	int currentRow;

public:
	Piece(const int currentRow, const int currentCol);
	virtual int checkMovement(const int nextRow, const int nextCol, Board& board) = 0;
	virtual int getCurrentCol();
	virtual int getCurrentRow();
};