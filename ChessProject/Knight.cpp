#include "Knight.h"
#include "Board.h"
#include "MovementUtils.h"

Knight::Knight(const int currentRow,const  int currentCol) : Piece(currentRow, currentCol)
{
}

int Knight::checkMovement(const int nextRow, const int nextCol, Board& board)
{
    int error = MovementUtils::checkMovementGeneral(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard(), board.getCurrentPlayer());

    if (error != 0) {
        return error;
    }

    //this if is checking if the knight is getting to the correct place
    if (!(
        ((nextRow == getCurrentRow() + 2) && (nextCol == getCurrentCol() - 1 || nextCol == getCurrentCol() + 1))
        || 
        ((nextCol == getCurrentCol() - 2) && (nextRow == getCurrentRow() - 1 || nextRow == getCurrentRow() + 1))
        ||
        (nextRow == getCurrentRow() - 2 && (nextCol == getCurrentCol() - 1 || nextCol == getCurrentCol() + 1))
        ||
        (nextCol == getCurrentCol() + 2 && (nextRow == getCurrentRow() - 1 || nextRow == getCurrentRow() + 1))
        ))
    {
        return 6;
    }

    return 0;
}

