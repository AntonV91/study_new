#pragma once

//class Player; // :GenericPlayer  игрок-человек
class Player : public GenericPlayer//  игрок-человек
{
public:
    Player(const string& name = "");
    virtual ~Player();
    // нужна ли карта еще
    virtual bool isHitting() const;
    void win() const;  // победил
    void lose() const; // проиграл
    void push() const; // сдать
};
