#pragma once
#include "board.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
 

class board;
class Piece;

class MovementUtils
{
public:
	static int checkMovementGeneral(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board, const int currPlayer);
	static bool checkSlidingVerticalMovement(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board);
	static bool checkSlidingHorizontalMovement(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board);
	static bool checkSlidingDiagonalMovement(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board);
	static Piece* pieceByType(const char type, const int currentRow, const int currentCol);
	static int getKingIndex(Board& board, const int currRow, const int currCol);
};