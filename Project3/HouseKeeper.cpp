#include "HouseKeeper.h"
#include "GenericPlayer.h"
#include <iostream>

using namespace std;

HouseKeeper::HouseKeeper(const std::string& name) : GenericPlayer(name) {}
HouseKeeper::~HouseKeeper() {};

bool HouseKeeper::isHitting() const
{
    return (getTotal() <= 16);
}

// перевернуть карту
void HouseKeeper::flipFirstCard() const
{
    if (!(mCards.empty()))
    {
        mCards[0]->flip();
    }
    else
    {
        cout << "Ќет карт дл€ переворота!\n";
    }
}