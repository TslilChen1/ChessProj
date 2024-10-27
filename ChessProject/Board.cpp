#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "MovementUtils.h"
#include <iostream>

using std::string;

class Bishop;
class Queen;
class Knight;
class King;
class Rook;

Board::Board()
{
    currentPlayer = 1;
    char tempBoard[SIZE][SIZE] = {
            {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'}
    };

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            board[i][j] = tempBoard[i][j];
        }
    }
}

void Board::changeBoardPosition(Piece* piece, int nextRow, int nextCol)
{
    char temp = this->board[piece->getCurrentRow()][piece->getCurrentCol()];
    this->board[piece->getCurrentRow()][piece->getCurrentCol()] = '#';
    this->board[nextRow][nextCol] = temp;
}

void Board::changeTurn()
{
    if (currentPlayer == 0) {
        currentPlayer = 1;
    }
    else {
        currentPlayer = 0;
    }
}

bool Board::isCheckForOtherPlayer(Piece* piece, const int nextRow, const int nextCol, const int currRow, const int currCol)
{
    char currentPlayerChr = board[piece->getCurrentRow()][piece->getCurrentCol()];
    int isChechReturnedError = 0;
    int errorCode = 0;
    
    int kingIndex = MovementUtils::getKingIndex(*this, currRow, currCol);
    int kingRow = kingIndex / SIZE;
    int kingCol = kingIndex % SIZE;

    if ((isupper(currentPlayerChr) && (currentPlayer == 0)) || (islower(currentPlayerChr) && (currentPlayer != 0)))
    {
       
        Piece* p = MovementUtils::pieceByType(currentPlayerChr, nextRow, nextCol);
        char letter = this->board[currRow][currCol];
        this->board[currRow][currCol] = EMPTY;
        this->board[nextRow][nextCol] = letter;
        errorCode = p->checkMovement(kingRow, kingCol, *this);
        this->board[nextRow][nextCol] = EMPTY;
        this->board[currRow][currCol] = letter;
        delete p;
        return (errorCode == 0);
    }

    return false;
}

bool Board::isSelfCheck(Piece* piece, const int nextRow, const int nextCol, const int currRow, const int currCol)
{
    Piece* player = nullptr;
    changeTurn();
    char letter = this->board[currRow][currCol];
    this->board[currRow][currCol] = EMPTY;
    this->board[nextRow][nextCol] = letter;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((islower(board[i][j]) && (getCurrentPlayer() != 0)) || (isupper(board[i][j]) && (getCurrentPlayer() == 0)))
            {
                player = MovementUtils::pieceByType(board[i][j], i, j);

                if (player != nullptr) {
                    if (isCheckForOtherPlayer(player, i, j, player->getCurrentRow(), player->getCurrentCol()))
                    {
                        this->board[nextRow][nextCol] = EMPTY;
                        this->board[currRow][currCol] = letter;
                        return true;
                    }
                    delete player;
                }
            }
        }
    }
    this->board[nextRow][nextCol] = EMPTY;
    this->board[currRow][currCol] = letter;
    changeTurn();
    return false;
}


int Board::getCurrentPlayer()
{
    return currentPlayer;
}

/*bool Board::isCheckmate(Piece* piece, int currRow, int currCol)
{
    int kingIndex = MovementUtils::getKingIndex(*this, currRow, currCol);
    int kingRow = kingIndex / SIZE;
    int kingCol = kingIndex % SIZE;

    int nextRow = 0;
    int nextCol = 0;
    bool isSelfCheck = false;

    changeTurn();

    King* king = new King(kingRow, kingCol);
    if (king->checkMovement(kingRow + 1, kingCol, *this) == 0)
    {
        nextRow = kingRow + 1;
        nextCol = kingCol;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    }
    if (king->checkMovement(kingRow - 1, kingCol, *this) == 0)
    {
        nextRow = kingRow - 1;
        nextCol = kingCol;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    }
    if (king->checkMovement(kingRow, kingCol + 1, *this) == 0)
    {
        nextRow = kingRow;
        nextCol = kingCol + 1;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    }
    if (king->checkMovement(kingRow, kingCol - 1, *this) == 0)
    {
        nextRow = kingRow;
        nextCol = kingCol - 1;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    } 
    if (king->checkMovement(kingRow + 1, kingCol + 1, *this) == 0)
    {
        nextRow = kingRow + 1;
        nextCol = kingCol + 1;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    } 
    if (king->checkMovement(kingRow - 1, kingCol - 1, *this) == 0)
    {
        nextRow = kingRow - 1;
        nextCol = kingCol - 1;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    }
    if (king->checkMovement(kingRow + 1, kingCol - 1, *this) == 0)
    {
        nextRow = kingRow + 1;
        nextCol = kingCol - 1;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    }
    if (king->checkMovement(kingRow - 1, kingCol + 1, *this) == 0)
    {
        nextRow = kingRow - 1;
        nextCol = kingCol + 1;
        isSelfCheck = this->isSelfCheck(king, nextRow, nextCol, kingRow, kingCol);
        if (!isSelfCheck) { return isSelfCheck; };
    }
    return true;
}
*/

std::array<std::array<char, SIZE>, SIZE> Board::getBoard()
{
    return board;
}


void Board::printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << this->board[i][j] << " ";
        }
        std::cout << "\n";
    }
}