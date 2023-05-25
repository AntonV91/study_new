#include "Deck.h"
#include <iostream>

using namespace std;

Deck::Deck()
{
    mCards.reserve(52);
    populate();
}

Deck::~Deck()
{
    for (auto cardPtr : mCards)
    {
        delete cardPtr;
    }
}

void Deck::populate()
{
    clear();
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(mCards.begin(), mCards.end());
}

void Deck::deal(Hand& aHand)
{
    if (!mCards.empty())
    {
        aHand.add(mCards.back());
        mCards.pop_back();
    }
    else
    {
        cout << "Карты закончились. Не могу сдать. ";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting())
    {
        deal(aGenericPlayer);
        cout << aGenericPlayer << endl;
        if (aGenericPlayer.isBusted())
        {
            aGenericPlayer.bust();
        }
    }
}