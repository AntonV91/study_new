#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string& name) :mName{ name }
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}

void GenericPlayer::bust() const
{
    cout << mName << " Перебор. \n";
}

ostream& operator << (ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.mName << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.mCards.empty()) {
        for (pCard = aGenericPlayer.mCards.begin(); pCard != aGenericPlayer.mCards.end(); ++pCard) {
            os << *(*pCard) << "\t";
        }

        if (aGenericPlayer.getTotal() != 0) {
            cout << "(" << aGenericPlayer.getTotal() << ")";
        }
    }
    else {
        os << "<empty>";
    }

    return os;
}