
#include "Player.h"
#include <iostream>



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

void Player::displayTrebleMiss(int target, int result)
{
	std::cout << "Aiming at.. " << target << " treble " << std::endl;
	std::cout << " Miss :( Scored: " << result << " Score: " << playerScore << std::endl;
}

void Player::displayTrebleHit(int target, int result)
{
	std::cout << "Aiming at... " << target << " treble " << std::endl;
	std::cout << " Hit :) Scored:  " << result << "  Score: " << playerScore << std::endl;
}




void Player::throwSingle(uint16_t d, DartBoard* board)
{
	
	uint16_t r = rand() % 100+1;
	uint16_t rn =  rand() % 20+1;


	if (d == OUTER) {		// outer  80%
		if (r < 80)
		{
			subtractScore(OUTER);
			displaySingleHit(OUTER, OUTER);
		}		
			
		else if (r < 75) // Bull 75%
		{
			subtractScore(BULL);
			displaySingleMiss(OUTER, BULL);

		}
			
		else
		{
			subtractScore(rn);
			displaySingleMiss(OUTER, rn);

		}
			
	}
	else
	{			// 1 to 20 single
		if (r < 88)
		{
			subtractScore(d);
			displaySingleHit(d, d);
		}			
		else if (r < 92)
		{
			subtractScore(board->aimingPosition(0,d));
			displaySingleMiss(d, board->aimingPosition(0, d));

		}			
		else if (r < 96)
		{
			subtractScore(board->aimingPosition(1,d));
			displaySingleMiss(d, board->aimingPosition(1, d));

						
		}			
		else if (r < rn)
		{
			subtractScore(rn);
			displaySingleMiss(d, rn);

		}			
	}
}

void Player::throwBull(uint16_t percent, DartBoard* board)
{
	//  Throw for the bull with accuracy p%  (20<p<85)

	int r = rand() % 100;
	int ra = +rand() % 20;
	int ran = +rand() % 2+1;
	int ran2 = +rand() % 2 + 1;

	if (r < (percent - 20))
	{
		subtractScore(BULL);
		displaySingleHit(BULL, BULL);
		
	}		
	else if (r < 85)
	{
		subtractScore(OUTER);
		displaySingleHit(OUTER, OUTER);
		//std::cout << "SCORED: " << OUTER << " SCORE:" << playerScore << std::endl;
	}
	else
	{
		subtractScore(board->aimingPosition(ran,ran2 ));		
		displaySingleMiss(BULL, board->aimingPosition(ran, ran2));
		//std::cout << "SCORED: " << rn << " SCORE:" << playerScore << std::endl;
	}
		

		 





}

void Player::throwDouble(uint16_t d, DartBoard* board)
{
	//  return result of throwing for double d with accuracy 80%
	
	// Board neighbours ignoring slot zero

	int r = rand() % 100;

	if (r < 80)
	{
	    subtractScore(2 * d);	
		displayDoubleHit(d, 2 * d);
	}	
	/*
	else if (r < 85)
	{
		subtractScore(0);
		displayDoubleMiss(d, 0);
	}*/
	else if (r < 90)
	{
		subtractScore(d);
		displayDoubleHit(d, d);
		
	}		
	else if (r < 93)
	{
		subtractScore(2* board->aimingPosition( 0, d));		//chance for scoring double left
		displayDoubleMiss(d, 2 * board->aimingPosition(0, d));
	}		
	else if (r < 96)
	{
		subtractScore(2 * board->aimingPosition(1, d));	//chance for scoring double right
		displayDoubleMiss(d, 2 * board->aimingPosition(1, d));
		
	}		
	else if (r < 98)//chance for scoring single
	{
		subtractScore(board->aimingPosition(0, d));		
		displayDoubleMiss(d, board->aimingPosition(0, d));
		
	}		
	else
	{
		subtractScore(board->aimingPosition(1, d));		
		displayDoubleMiss(d, board->aimingPosition(1, d));
	}
		

	
}

void Player::throwTreble(uint16_t d, DartBoard* board)
{
		//  return result of throwing for treble d with accuracy p%  (o<90)

		// Board neighbours ignoring slot zero
		
		int r = rand() % 100;

		if (r < 70) //treble hit
		{
			subtractScore(3 * d);
			displayTrebleHit(d, 3 * d);
		}
			
		else if (r < 80) //single hit
		{
			subtractScore(d);
			displayTrebleMiss(d, d);
			
		}
		else if (r < 90) //single hit
		{
			subtractScore(0);
			displayTrebleMiss(d, 0);

		}
			
		else if (r < 93)//treble left hand score hit
		{
			subtractScore(3* board->aimingPosition(0, d));			
			displayTrebleMiss(d, 3 * board->aimingPosition(0, d));
		}
			
		else if (r < 96)//treble right hand score hit
		{
			subtractScore(3 * board->aimingPosition(1, d));
			displayTrebleMiss(d, 3 * board->aimingPosition(1, d));
			
			
		}		
			
		else if (r < 98)//single of left hand score hit
		{
			subtractScore(board->aimingPosition(0, d));
			displayTrebleMiss(d, board->aimingPosition(0, d));			
						
		}
			
		else//single of right hand score hit
		{
			subtractScore(board->aimingPosition(1, d));
			displayTrebleMiss(d, board->aimingPosition(1, d));					
			
		}
			
	

}

void Player::setBusted(bool bustedValue)
{
	bustedScore = bustedValue;
}

bool Player::getBusted()
{
	return bustedScore;
}

bool Player::checkWin()
{
	return (playerScore == 0);
}


