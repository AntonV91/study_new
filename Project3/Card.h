#pragma once
#include <fstream>

using namespace std;

class Card  //карта
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        TEN, JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    Card(rank r = ACE, suit s = CLUBS, bool ifu = true);

    int getValue() const; // собщает значение карты

    void flip(); //переворачивает карту

    friend ostream& operator<<(ostream& os, const Card& aCard);

private:
    rank mRank;
    suit mSuit;
    bool mIsFaceUp;

};
