#pragma once
#include <string>


#define GAMEMODE 501
#define OUTER 25
#define BULL 50


class Player
{

    std::string playerName;
    uint16_t playerScore;

public:
    Player();
    Player(std::string n,uint16_t);
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

    //THROWING

    void throwSingle(uint16_t d);
    void throwBull(uint16_t d);
    void throwDouble(uint16_t d);
    void throwTreble(uint16_t d);






};

