#pragma once
#define NUMBEROFPLAYERS 2
enum Choice {Exit,Playing};
#include "Player.h"
#include "DartBoard.h"
class Game
{
	int userChoice;
	int setCounter;

	std::string name;
	std::string name2;

public:
	Game();
	~Game();


	void startGame();
	void displayInstructions();
	void throw3Darts(Player* player, DartBoard* board);
	void getNames();



};

