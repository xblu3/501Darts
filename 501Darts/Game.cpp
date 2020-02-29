#include "Game.h"
#include <time.h>
#include <iostream>

Game::Game()
{
	Player p1();
	Player p2();
}

Game::~Game()
{
}

void Game::startGame()
{
	displayInstructions();
	std::cin >> userChoice;

	while (userChoice != 0)
	{
		switch (userChoice) {
		case (Exit): {
			userChoice = 0;
		} break;

		case (Playing): {
			
			std::cout << "How many times you want to play? ";

			getNames();
					
			Player* player1 = new Player;
			Player* player2 = new Player;
						
			player1->setPlayerName(name);
			player2->setPlayerName(name2);
			
			player1->setPlayerScore(GAMEMODE);
			player2->setPlayerScore(GAMEMODE);


			

		} break;

		default: break;
		}
	}





}

void Game::displayInstructions()
{
	std::cout << "\nWelcome to the 501 Darts World Championships Game Simulator ";
	std::cout << "\nTwo players play a match of 13 sets";
	std::cout << "\nEach set is the best of 5";	
	std::cout << "\nPress: ";
	std::cout << "\n 1 - START";
	std::cout << "\n 2 - EXIT \n";

}

void Game::getNames()
{

	
		std::cout << "Player 1 name: ";
		std::cin >> name;

		std::cout << "Player 2 name: ";
		std::cin >> name2;

}







