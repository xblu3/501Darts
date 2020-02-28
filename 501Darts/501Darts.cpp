// 501Darts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include <time.h>
#include "DartBoard.h"

#define GAMEMODE 501

int main()
{
    srand(time(NULL));
    //std::cout << "Hello World!\n";
    Player p1("Jacek", GAMEMODE);
    

    for (int i = 0; i < 10; i++)
    {
        p1.throwDouble(10);
    }
  

}

