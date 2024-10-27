#include "MovementUtils.h"
#include "Piece.h"
#include <cctype>
#include <cstdlib>


int MovementUtils::checkMovementGeneral(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board, const int currPlayer)
{
    if ((currentRow < 0 || currentRow > 7) || (currentCol < 0 || currentCol > 7) || (nextRow < 0 || nextRow > 7) || (nextCol < 0 || nextCol > 7))
    {
        return 5;
    }

    char currentItem = board[currentRow][currentCol];
    char nextItem = board[nextRow][nextCol];

    if ((currentRow == nextRow) && (currentCol == nextCol))
    {
        return 7;
    }

    if (!((islower(currentItem) && (currPlayer != 0)) || (isupper(currentItem) && (currPlayer == 0))))
    {
        return 2;
    }

    if ((islower(nextItem) && (currPlayer != 0)) || (isupper(nextItem) && (currPlayer == 0)))
    {
        return 3;
    }

    

    return 0;
}

bool MovementUtils::checkSlidingVerticalMovement(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board)
{
    if (currentCol != nextCol) {
        return false;
    }

    int startRow = (currentRow < nextRow) ? currentRow : nextRow;
    int endRow = (currentRow < nextRow) ? nextRow : currentRow;

    for (int i = startRow + 1; i < endRow; i++)
    {
        if (board[i][currentCol] != '#') {
            return false;
        }
    }

    return true;
}

bool MovementUtils::checkSlidingHorizontalMovement(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board)
{
    if (currentRow != nextRow) {
        return false;
    }

    int startCol = (currentCol < nextCol) ? currentCol : nextCol;
    int endCol = (currentCol < nextCol) ? nextCol : currentCol;

    for (int i = startCol + 1; i < endCol; i++)
    {
        if (board[currentRow][i] != '#') {
            return false;
        }
    }

    return true;
}

bool MovementUtils::checkSlidingDiagonalMovement(const int currentRow, const int currentCol, const int nextRow, const int nextCol, const std::array<std::array<char, SIZE>, SIZE>& board)
{
    if (abs(currentRow - nextRow) != abs(currentCol - nextCol)) {
        return false;
    }

    int rowDirection = (nextRow > currentRow) ? 1 : -1;
    int colDirection = (nextCol > currentCol) ? 1 : -1;

    for (int i = 1; i < abs(currentRow - nextRow); ++i) {
        int row = currentRow + i * rowDirection;
        int col = currentCol + i * colDirection;

        if (board[row][col] != '#') {
            return false;
        }
    }

    return true;
}

Piece* MovementUtils::pieceByType(char type, int currentRow, int currentCol)
{
    Piece* player = nullptr;

    switch (type)
    {
    case ROOK:
    case ROOK_C:
        player = new Rook(currentRow, currentCol);
        break;
    case KNIGHT:
    case KNIGHT_C:
        player = new Knight(currentRow, currentCol);
        break;
    case BISHOP:
    case BISHOP_C:
        player = new Bishop(currentRow, currentCol);
        break;
    case KING:
    case KING_C:
        player = new King(currentRow, currentCol);
        break;
    case QUEEN:
    case QUEEN_C:
        player = new Queen(currentRow, currentCol);
        break;
    case PAWN:
    case PAWN_C:
        player = new Pawn(currentRow, currentCol);
    }

    return player;
}

int MovementUtils::getKingIndex(Board& board, const int currRow, const int currCol)
{
    int kingRow = 0;
    int kingCol = 0;
    char currentPlayerChr = board.getBoard()[currRow][currCol];
    if (islower(currentPlayerChr) && board.getCurrentPlayer() != 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board.getBoard()[i][j] == KING_C)
                {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }
    }
    if (isupper(currentPlayerChr) && board.getCurrentPlayer() == 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board.getBoard()[i][j] == KING)
                {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }
    }
    return ((kingRow * SIZE) + kingCol);
}

