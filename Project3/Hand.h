#pragma once
// набор карт
class Hand
{
public:
    Hand();
    virtual ~Hand();
    inline void add(Card* pCard);
    void clear();
    int getTotal() const;
protected:
    vector<Card*> mCards;
};
