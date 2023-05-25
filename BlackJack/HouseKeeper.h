#ifndef HOUSEKEEPER_H
#define HOUSEKEEPER_H

#include "GenericPlayer.h"

class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const string& name = "Казино");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    virtual void flipFirstCard() const;
};

#endif

