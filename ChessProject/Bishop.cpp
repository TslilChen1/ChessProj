#include "Bishop.h"
#include "MovementUtils.h"

Bishop::Bishop(const int currentRow, const int currentCol) : Piece(currentRow, currentCol)
{
}

int Bishop::checkMovement(const int nextRow, const int nextCol, Board& board)
{
    int error = MovementUtils::checkMovementGeneral(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard(), board.getCurrentPlayer());

    if (error != 0) {
        return error;
    }

    if (!MovementUtils::checkSlidingDiagonalMovement(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard()))
    {
        return 6;
    }

    return 0;
}
