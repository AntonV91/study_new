#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "GenericPlayer.h"
#include <iostream>
#include <algorithm>

Deck::Deck()
{
    mCards.reserve(52);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();
    //создаем стандартную колоду
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

void Deck::deal(Hand& aHand) // обратить внимание на ссылку - Рука.
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

void Deck::additionalCards(GenericPlayer& aGenericPlayer)  // обратить внимание на ссылку - ОбобщенныйИгрок.
{
    cout << endl;
    //продолжаем сдавать (если не перебор и готов брать)
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