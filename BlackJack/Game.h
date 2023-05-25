#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Deck.h"
#include "HouseKeeper.h"
#include "Player.h"

using namespace std;

class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    void Play();

private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;
};

#endif


