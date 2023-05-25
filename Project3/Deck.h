#pragma once

using namespace std;

//:Hand набор + доп функционал 
class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();

    //создаем стандартную колоду 52 карты
    void populate();

    //перемешиваем карты
    void shuffle();

    //сдаем по одной карте в руку
    void deal(Hand& aHand);

    //даем дополнительную карту игроку, если нужно
    void additionalCards(GenericPlayer& aGenericPlayer);
};
