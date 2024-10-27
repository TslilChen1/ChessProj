#pragma once
#include "board.h"

class FrontEndCommunication
{
public:
	const char* sendMoveCode(const std::string& msgFromGraphics, Board* board);
};