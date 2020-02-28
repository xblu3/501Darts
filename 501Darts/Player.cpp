
#include "Player.h"
#include <iostream>

Player::Player()
{
	playerName = " ";
	playerScore = 0;
	
}

Player::Player(std::string n, uint16_t s)
{
	
	playerName = n;
	playerScore = s;
}

Player::~Player()
{
}

void Player::setPlayerName(std::string name)
{
	playerName = name;
}

void Player::setPlayerScore(uint16_t score)
{
	playerScore = score;
}

std::string Player::getPlayerName()
{
	return playerName;
}

uint16_t Player::getPlayerScore()
{
	return playerScore;
}

void Player::subtractScore(int16_t score)
{
	playerScore -= score;
}

void Player::displaySingleMiss(int target , int result )
{
	std::cout << "Aiming at.. " << target << std::endl;
	std::cout << " Miss :( Scored: " << result << " Score: " << playerScore << std::endl;
}

void Player::displaySingleHit(int target, int result)
{
	std::cout << "Aiming at... " << target << std::endl;
	std::cout<<" Hit :) Scored:  " << result << "  Score: " << playerScore << std::endl;
}

void Player::displayDoubleMiss(int target, int result)
{
	std::cout << "Aiming at.. " << target << " double "<< std::endl;
	std::cout << " Miss :( Scored: " << result << " Score: " << playerScore << std::endl;
}

void Player::displayDoubleHit(int target, int result)
{
	std::cout << "Aiming at... " << target << " double "<< std::endl;
	std::cout << " Hit :) Scored:  " << result << "  Score: " << playerScore << std::endl;
}




void Player::throwSingle(uint16_t d)
{
	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	uint16_t r = rand() % 100;
	uint16_t rn = 1 + rand() % 20;


	if (d == OUTER) {		// outer  80%
		if (r < 80)
		{
			subtractScore(OUTER);
			displaySingleHit(OUTER, OUTER);
			//std::cout << "Aiming at outer.. " << " HIT :) Scored: " << OUTER << " Score: " << playerScore << std::endl;
		}		
			
		else if (r < 90)
		{
			subtractScore(BULL);
			displaySingleMiss(OUTER, BULL);
			//std::cout << "Aiming at outer.. " << " MISS :( Scored: " << BULL << " Score: " << playerScore << std::endl;

		}
			
		else
		{
			subtractScore(rn);
			displaySingleMiss(OUTER, rn);
			//std::cout << "Aiming at outer... " << " MISS :( Scored: " << rn << " Score: " << playerScore << std::endl;

		}
			
	}
	else
	{			// 1 to 20 single
		if (r < 88)
		{
			subtractScore(d);
			displaySingleHit(d, d);
			//std::cout << "Aiming for a single... " << d << " HIT :) SCORED: " << d << " Score: " << playerScore << std::endl;
		}			
		else if (r < 92)
		{
			subtractScore(bd[0][d]);
			displaySingleMiss(d, bd[0][d]);
			//std::cout << "Aiming for a single... " << d << " MISS :( SCORED: " << bd[0][d] << " Score: " << playerScore << std::endl;

		}			
		else if (r < 96)
		{
			subtractScore(bd[1][d]);
			displaySingleMiss(d, bd[1][d]);
			//std::cout << "Aiming for a single... " << d << " MISS :( SCORED: " << bd[1][d] << " Score: " << playerScore << std::endl;

						
		}			
		else if (r < rn)
		{
			subtractScore(rn);
			displaySingleMiss(d, rn);
			//std::cout << "Aiming for a single... " << d << " MISS :( SCORED: " << rn << " Score: " << playerScore << std::endl;

		}			
		
			


	}

}

void Player::throwBull(uint16_t percent)
{
	//  Throw for the bull with accuracy p%  (20<p<85)

	int r = rand() % 100;
	int rn = +rand() % 20;
	if (r < (percent - 20))
	{
		subtractScore(BULL);
		displaySingleHit(BULL, BULL);
		//std::cout << "SCORED: " << BULL << " SCORE:" << playerScore << std::endl;
		
	}		
	else if (r < 85)
	{
		subtractScore(OUTER);
		displaySingleHit(OUTER, OUTER);
		//std::cout << "SCORED: " << OUTER << " SCORE:" << playerScore << std::endl;
	}
	else
	{
		subtractScore(rn);
		displaySingleMiss(BULL, rn);
		//std::cout << "SCORED: " << rn << " SCORE:" << playerScore << std::endl;
	}
		

		 





}

void Player::throwDouble(uint16_t d)
{
	//  return result of throwing for double d with accuracy 80%
	
	// Board neighbours ignoring slot zero
	
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100;

	if (r < 80)
	{
		subtractScore(2 * d);	
		displayDoubleHit(d, 2 * d);
	}		
	else if (r < 85)
	{
		subtractScore(0);
		displayDoubleMiss(d, 0);
	}
	else if (r < 90)
	{
		subtractScore(d);
		displayDoubleHit(d, d);
		
	}		
	else if (r < 93)
	{
		subtractScore(2 * bd[0][d]);
		displayDoubleMiss(d, 2 * bd[0][d]);
	}		
	else if (r < 96)
	{
		subtractScore(2 * bd[1][d]); 
		displayDoubleMiss(d, 2 * bd[1][d]);
		
	}		
	else if (r < 98)
	{
		subtractScore(bd[0][d]);
		displayDoubleMiss(d, bd[0][d]);
		
	}		
	else
	{
		subtractScore(bd[1][d]);
		displayDoubleMiss(d, bd[1][d]);
	}
		

	
}

void Player::throwTreble(uint16_t d)
{
}


