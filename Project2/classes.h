#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class Card  //класс карта
{
public:
    enum rank //значени€ карт
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        TEN, JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };  //карточные масти
    Card(rank r = ACE, suit s = CLUBS, bool ifu = true);

    int getValue() const; // собщает значение карты

    void flip();        //переворачивает карту

    friend ostream& operator<<(ostream& os, const Card& aCard);

private:
    rank mRank;
    suit mSuit;
    bool mIsFaceUp;

};

Card::Card(rank r, suit s, bool ifu) :mRank{ r }, mSuit{ s }, mIsFaceUp{ ifu }
{}

int Card::getValue() const
{
    int value = 0;
    if (mIsFaceUp)      //если карта перевернута, читаем значение.
    {
        value = mRank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::flip()
{
    mIsFaceUp = !(mIsFaceUp);
}

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

// реализаци€ методов Hand
Hand::Hand()
{
    mCards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

inline void Hand::add(Card* pCard)
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
    //если карт в руке нет. возвращает значение ќ 
    if (mCards.empty())
    {
        return 0;
    }

    //если перва€ карта имеет значение ќ. 
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

    //определ€ет. держит ли рука туз 
    bool containsAce = false;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    //если рука держит туз и сумма довольно маленька€, 
    //туз дает 11 очков 
    if (containsAce && total <= 11)
    {
        //добавл€ем только 10 очков. т.к. тузы уже добавили +1
        total += 10;
    }
    return total;
}

//:Hand обобщенный игрок
class GenericPlayer :public Hand
{
    friend ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();

    //продолжать ли сдавать игроку
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;
protected:
    string mName;
};

GenericPlayer::GenericPlayer(const string& name) :mName{ name }
{}
GenericPlayer::~GenericPlayer()
{}
//перебор, больше 21
bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}
//сообщить о перебор
void GenericPlayer::bust() const
{
    cout << mName << " ѕеребор. \n";
}

//:Hand набор + доп функционал 
class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();

    //создаем стандартную колоду 52 карты
    void populate();

    //перемешиваем карты
    void shuffle();

    //сдаем по одной карте в руку
    void deal(Hand& aHand);

    //даем доп. карту игроку, если нужно
    void additionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck()
{
    mCards.reserve(52);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();
    //создаем стандартную колоду
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(mCards.begin(), mCards.end());
}

void Deck::deal(Hand& aHand) //обратить внимание на ссылку - –ука.
{
    if (!mCards.empty())
    {
        aHand.add(mCards.back());
        mCards.pop_back();
    }
    else
    {
        cout << " арты закончились. Ќе могу сдать. ";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)  //обратить внимание на ссылку - ќбобщенный»грок.
{
    cout << endl;
    //продолжаем сдавать (если не перебор и готов брать)
    while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting())
    {
        deal(aGenericPlayer);
        cout << aGenericPlayer << endl;
        if (aGenericPlayer.isBusted())
        {
            aGenericPlayer.bust();
        }
    }
}


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

Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
    cout << mName << ", ¬ам нужна еще? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << mName << ". ¬ы выиграли! \n";
}

void Player::lose() const
{
    cout << mName << " ѕроиграл. \n";
}

void Player::push() const
{
    cout << mName << " Ќичь€. \n";
}



//class HouseKeeper; // :GenericPlayer игрок-компьютер
class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const std::string& name = " азино");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    // перевернуть карту
    virtual void flipFirstCard() const;

};

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

//основна€ логика игры
class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //»граем в игру!
    void Play();
private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;
};

Game::Game(const vector<string>& names)
{
    //создаем массив игроков
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        mPlayers.push_back(Player(*pName));
    }
    //инициализируем √—„
    srand(static_cast<unsigned int>(time(NULL)));// преобразование time_t
    mDeck.populate();
    mDeck.shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    //—дать всем по 2 карты
    vector<Player>::iterator pPlayer;

    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            mDeck.deal(*pPlayer);
        }
        mDeck.deal(mHouse);
    }
    //—крыть первую карту казино
    mHouse.flipFirstCard();

    //показать все карты на руках
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << mHouse << endl;
    // сдать дополнительные карты игрокам
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        mDeck.additionalCards(*pPlayer);
    }

    //перевернуть первую карту  азино
    mHouse.flipFirstCard();
    cout << endl << mHouse;

    //раздать дополнительную карту казино
    mDeck.additionalCards(mHouse);
    if (mHouse.isBusted())
    {
        //проверить на выигрыш
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                pPlayer->win();
            }
        }
    }
    else
    {
        //сравнить карты игроков и казино
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()) && (pPlayer->getTotal() > mHouse.getTotal()))
            {//≈сли не перебор и больше диллера
                pPlayer->win();
            }
            else if ((pPlayer->isBusted()) || (!(pPlayer->isBusted()) && pPlayer->getTotal() < mHouse.getTotal()))
            {
                pPlayer->lose();
            }
            else
            {
                pPlayer->push(); //ничь€
            }

        }
    }
    //очистить карты в руках
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    mHouse.clear();
}