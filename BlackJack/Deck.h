#ifndef DECK_H
#define DECK_H

#include "hand.h"
#include "GenericPlayer.h"
#include "Card.h"
#include <algorithm>
#include <vector>

using namespace std;

class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();

    void populate();
    void shuffle();
    void deal(Hand& aHand);
    void additionalCards(GenericPlayer& aGenericPlayer);

private:
    vector<Card*> mCards;
};

#endif


