#include "Hand.h"

using namespace std;

Hand::Hand()
{
    mCards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

void Hand::add(Card* pCard)
{
    mCards.push_back(pCard);
}

void Hand::clear()
{
    vector<Card*>::iterator iter = mCards.begin();
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        delete* iter;
        *iter = nullptr;
    }
    //очищаем вектор указателей
    mCards.clear();
}

int Hand::getTotal() const
{
    //если карт в руке нет. возвращает значение О
    if (mCards.empty())
    {
        return 0;
    }
    //если первая карта имеет значение О. 
    //то она лежит рубашкой вверх: 
    if (mCards[0]->getValue() == 0)
    {
        return 0;
    }

    //находит сумму очков всех карт. каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    //определяет. держит ли рука туз 
    bool containsAce = false;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    //если рука держит туз и сумма довольно маленькая. 
    //туз дает 11 очков 
    if (containsAce && total <= 11)
    {
        //добавляем только 10 очков. т.к. тузы уже добавили +1
        total += 10;
    }
    return total;
}