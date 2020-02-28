#include <string>

#pragma once
class CreatePlayer
{
public:

	//SETTERS

	virtual void setName(std::string name) = 0; //set player name


	//GETTERS

	virtual std::string getName() = 0; //get player name
	virtual bool getBust() = 0;
	virtual uint16_t getWinCounter() = 0;
	

	//THROW FUNCTIONS

	virtual void throwSingle(uint16_t d, Board* board) = 0;
	virtual void throwDouble(uint16_t d, Board* board) = 0;
	virtual void throwTriple(uint16_t d, Board* board) = 0;
	virtual void throwBull() = 0;
	virtual void throwOuter() = 0;

	virtual bool throwBullPercentage(uint16_t percentage) = 0;


	//SCORE FUNCTIONS

	virtual void setScore(uint16_t score) = 0;
	virtual void updateScore(int16_t number) = 0;
	virtual int16_t getScore() = 0;

	virtual bool isEven(int16_t number) = 0;
	virtual bool isOdd(int16_t number) = 0;

	virtual bool checkWin() = 0;
	virtual void triggerBust(bool value) = 0;
	
	virtual void incrementWinCounter() = 0;






};

