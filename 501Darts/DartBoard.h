#pragma once
#include "Player.h"



#define X 2
#define Y 21

class DartBoard
{
	uint16_t dartBoard[X][Y];

public:


	DartBoard();
	~DartBoard();

	void fillBoard();

	uint16_t aimingPosition(uint16_t x, uint16_t y);

	



};

