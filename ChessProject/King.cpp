#include "King.h"
#include "MovementUtils.h"

King::King(const int currentRow,const int currentCol) : Piece(currentRow, currentCol)
{
}

int King::checkMovement(const int nextRow, const int nextCol, Board& board)
{
    int error = MovementUtils::checkMovementGeneral(getCurrentRow(), getCurrentCol(), nextRow, nextCol, board.getBoard(), board.getCurrentPlayer());

    if (error != 0) {
        return error;
    }

    int rowDifference = abs((getCurrentRow()) - (nextRow));
    int colDifference = abs((getCurrentCol()) - (nextCol));

    if (!((rowDifference == 1 && colDifference == 0) || (rowDifference == 0 && colDifference == 1) || (rowDifference == 1 && colDifference == 1))) {
        return 6;
    }

    return 0;
}
