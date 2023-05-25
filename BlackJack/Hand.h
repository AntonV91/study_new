#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void add(Card* pCard);
	void clear();
	int getTotal() const;
protected:
	vector<Card*> mCards;
};

#endif
