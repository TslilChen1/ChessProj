/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "FrontEndCommunication.h"
using std::cout;
using std::endl;
using std::string;


void main()
{
	cout << "Player 0 - White - uppercase" << std::endl;
	cout << "Player 1 - Black - lowercase" << std::endl;

	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1"); 
	Board* board = new Board();

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	FrontEndCommunication* obj = new FrontEndCommunication();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE

		strcpy_s(msgToGraphics, ((obj->sendMoveCode(msgFromGraphics, board)))); // msgToGraphics should contain the result of the operation


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		//get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

	}
	p.close();
	
}
