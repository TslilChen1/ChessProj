#include "Pawn.h"
#include "MovementUtils.h"

Pawn::Pawn(const int currentRow, const int currentCol) : Piece(currentRow, currentCol)
{
}

int Pawn::checkMovement(const int nextRow, const int nextCol, Board& board)
{
    int error = MovementUtils::checkMovementGeneral(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard(), board.getCurrentPlayer());

    if (error != 0) 
    {
        return error;
    }

    if (((getCurrentRow() == 6) && (board.getCurrentPlayer() != 0)) || ((getCurrentRow() == 1) && (board.getCurrentPlayer() == 0)))
    {
        if (checkFirstMovement(nextRow, nextCol, board))
        {
            return 0;
        }

        if ((error != 3) && checkEatingMovement(nextRow, nextCol, board))
        {
            return 0;
        }
    }
    else
    {
        if ((((board.getCurrentPlayer() == 0) && ((getCurrentRow() + 1) == nextRow)) ||
            ((board.getCurrentPlayer() != 0) && ((getCurrentRow() - 1) == nextRow))) &&
            (getCurrentCol() == nextCol) && (board.getBoard()[nextRow][nextCol] == EMPTY))
        {
            error = 0;
        }
        else if ((error != 3) && checkEatingMovement(nextRow, nextCol, board))
        {
            error = 0;
        }
        else
        {
            error = 6;
        }
        return error;
    }

    return 6;
}

bool Pawn::checkFirstMovement(const int nextRow, const int nextCol, Board& board)
{
    if ((getCurrentCol() == nextCol) &&
        (((board.getCurrentPlayer() == 0) && (nextRow == 3 || nextRow == 2)) ||
        ((board.getCurrentPlayer() != 0) && (nextRow == 5 || nextRow == 4))) && 
        (board.getBoard()[nextRow][nextCol] == EMPTY))
    {
        return true;
    }

    return false;
}

bool Pawn::checkEatingMovement(const int nextRow, const int nextCol, Board& board)
{
    if ((abs(getCurrentCol() - nextCol) == 1) &&
        (((board.getCurrentPlayer() == 0) && (getCurrentRow() + 1 == nextRow)) ||
        ((board.getCurrentPlayer() != 0) && (getCurrentRow() - 1 == nextRow))) && 
        (board.getBoard()[nextRow][nextCol] != EMPTY))
    {
        return true;
    }

    return false;
}