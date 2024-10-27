#include "FrontEndCommunication.h"
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "MovementUtils.h"


class Bishop;
class Queen;
class Knight;
class King;
class Rook;

const char* FrontEndCommunication::sendMoveCode(const std::string& msgFromGraphics, Board* board)
{
	int error = 0;
	Piece* player = nullptr;
	int currentRow = '8' - msgFromGraphics[1];
	int currentCol = msgFromGraphics[0] - 'a';
	int nextRow = '8' - msgFromGraphics[3];
	int nextCol = msgFromGraphics[2] - 'a';
	player = MovementUtils::pieceByType(std::tolower(board->getBoard()[currentRow][currentCol]), currentRow, currentCol);
	if (player != nullptr)
	{
		error = player->checkMovement(nextRow, nextCol, *(board));
		if (error == 0) 
		{
			if (board->isCheckForOtherPlayer(player, nextRow, nextCol, currentRow, currentCol))
			{
				error = 1;


				/*if (board->isCheckmate(player, currentRow, currentCol))
				{
					error = 8;
				}
				board->changeTurn();*/
			}
			else
			{
				if (board->isSelfCheck(player, nextRow, nextCol, currentRow, currentCol))
				{
					error = 4;
				}		
			}
		}
	}
	else
	{
		error = 2;
	}
	char charNumberErrorCode = static_cast<char>(error + '0');
	const char charNumberErrorCodeStr[] = { charNumberErrorCode , '\0' };
	const char* charNumberErrorCodePointer = charNumberErrorCodeStr;
	if (error == 0 || error == 1)
	{
		board->changeBoardPosition(player, nextRow, nextCol);
		board->changeTurn();
		delete player;
	}
	
	return charNumberErrorCodePointer;
}
