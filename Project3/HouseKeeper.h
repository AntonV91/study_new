#pragma once

//class HouseKeeper; // :GenericPlayer игрок-компьютер
class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const std::string& name = "Казино");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    // перевернуть карту
    virtual void flipFirstCard() const;

};

