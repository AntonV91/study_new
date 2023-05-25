#include "GenericPlayer.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

GenericPlayer::GenericPlayer(const string& name) :mName{ name }
{}
GenericPlayer::~GenericPlayer()
{}
// переполнение, больше 21
bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}
// Сообщить о Переполнении
void GenericPlayer::bust() const
{
    cout << mName << " Перебор. \n";
}

ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.mName << " :\t";
    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.mCards.empty())
    {
        for (pCard = aGenericPlayer.mCards.begin();
            pCard != aGenericPlayer.mCards.end();
            ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.getTotal() != 0)
        {
            cout << "(" << aGenericPlayer.getTotal() << ")";
        }
    }
    else
    {
        os << "<пусто>";
    }
    return os;
}


