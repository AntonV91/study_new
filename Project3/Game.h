#pragma once

// Основная логика игры
class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //Играем в игру!
    void Play();
private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;
};
