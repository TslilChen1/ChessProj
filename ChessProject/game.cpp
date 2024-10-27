#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "MovementUtils.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Board;
class Bishop;
class Queen;
class Knight;
class King;
class Rook;

/*int main()
{
	Board* board = new Board();


	string movement = "";
	Piece* player = nullptr;
	int error = 0;

	cout << "Player 0 - White - lowercase" << std::endl;
	cout << "Player 1 - Black - uppercase" << std::endl;
	
	do
	{
		board->printBoard();
		cout << "The player that playes now is: " << board->getCurrentPlayer() << std::endl;
		cout << "Please enter the movement that you want: \n";
		getline(cin, movement);
		int currentRow = '8' - movement[1];
		int currentCol = movement[0] - 'a';
		int nextRow = '8' - movement[3];
		int nextCol = movement[2] - 'a';
		switch (std::tolower(board->getBoard()[currentRow][currentCol]))
		{
		case ROOK:
			player = new Rook(currentRow, currentCol);
			break;
		case KNIGHT:
			player = new Knight(currentRow, currentCol);
			break;
		case BISHOP:
			player = new Bishop(currentRow, currentCol);
			break;
		case KING:
			player = new King(currentRow, currentCol);
			break;
		case QUEEN:
			player = new Queen(currentRow, currentCol);
			break;
		case PAWN:
			player = new Pawn(currentRow, currentCol);
			break;
		default:
			error = 2;
			break;
		}

		if (error != 2) {
			error = player->checkMovement(nextRow, nextCol, *(board));
		}

		if (error == 1 || error == 0)
		{
			board->changeBoardPosition(player, nextRow, nextCol, error);
			board->changeTurn();
			delete player;
		}

		cout << "The error number is: " << error << std::endl;

	} while (true);
}*/