#pragma once
#include "Player.h"


#define X 2
#define Y 21

class DartBoard: public Player
{
	uint16_t board[X][Y] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

public:


	DartBoard();
	~DartBoard();


	



};

