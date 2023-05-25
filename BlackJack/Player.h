#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "genericplayer.h"

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");
    virtual ~Player();
    virtual bool isHitting() const;
    void win() const;
    void lose() const;
    void push() const;
};

#endif

