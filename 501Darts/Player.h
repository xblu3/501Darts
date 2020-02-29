#pragma once
#include <string>
#include "DartBoard.h"



#define GAMEMODE 501
#define OUTER 25
#define BULL 50

class DartBoard;

class Player
{



    std::string playerName;
    uint16_t playerScore;
    bool bustedScore;

public:
    
    Player(std::string name = " ",uint16_t score =GAMEMODE);
    ~Player();


    void setPlayerName(std::string name);
    void setPlayerScore(uint16_t score);

    std::string getPlayerName();
    uint16_t getPlayerScore();

    void subtractScore(int16_t score);

    //DISPLAY

    void displaySingleMiss(int target, int result);
    void displaySingleHit(int target, int result);

    void displayDoubleMiss(int target, int result);
    void displayDoubleHit(int target, int result);

    void displayTrebleMiss(int target, int result);
    void displayTrebleHit(int target, int result);



    //THROWING

    void throwSingle(uint16_t d, DartBoard* board);
    void throwBull(uint16_t d, DartBoard* board);
    void throwDouble(uint16_t d, DartBoard* board);
    void throwTreble(uint16_t d , DartBoard* board);

    void setBusted(bool bustedScore);
    bool getBusted();

    bool checkWin();



};

