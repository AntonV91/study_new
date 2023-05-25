#pragma once

// �������� ������ ����
class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //������ � ����!
    void Play();
private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;
};
