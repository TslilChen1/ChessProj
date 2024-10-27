#include "Queen.h"
#include "MovementUtils.h"

Queen::Queen(const int currentRow, const int currentCol) : Piece(currentRow, currentCol)
{
}

int Queen::checkMovement(const int nextRow, const int nextCol, Board& board)
{
    int error = MovementUtils::checkMovementGeneral(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard(), board.getCurrentPlayer());

    if (error != 0) {
        return error;
    }

    if (!(MovementUtils::checkSlidingVerticalMovement(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard())
        || MovementUtils::checkSlidingHorizontalMovement(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard())
        || MovementUtils::checkSlidingDiagonalMovement(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard())))
    {
        return 6;
    }

    return 0;
}
