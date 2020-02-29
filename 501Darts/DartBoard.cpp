#include "DartBoard.h"
#include <iostream>

DartBoard::DartBoard()
{
	//::cout << "Dart board constuctor called" << std::endl;	
	fillBoard();
	
}

DartBoard::~DartBoard()
{
	//std::cout << "Dart board destructor called" << std::endl;
}


void DartBoard::fillBoard() {
	uint16_t bd[X][Y] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
					  { 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };


	for (uint8_t i = 0; i < X; ++i) {
		for (uint8_t j = 0; j < Y; ++j) {
			dartBoard[i][j] = bd[i][j];
		}
	}
}

uint16_t DartBoard::aimingPosition(uint16_t x, uint16_t y)  {
	return dartBoard[x][y];
}