#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class Card  //����� �����
{
public:
    enum rank //�������� ����
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        TEN, JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };  //��������� �����
    Card(rank r = ACE, suit s = CLUBS, bool ifu = true);

    int getValue() const; // ������� �������� �����

    void flip();        //�������������� �����

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
    if (mIsFaceUp)      //���� ����� �����������, ������ ��������.
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

// ����� ����
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

// ���������� ������� Hand
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
    //������� ������ ����������
    mCards.clear();
}

int Hand::getTotal() const
{
    //���� ���� � ���� ���. ���������� �������� � 
    if (mCards.empty())
    {
        return 0;
    }

    //���� ������ ����� ����� �������� �. 
    //�� ��� ����� �������� �����: 
    if (mCards[0]->getValue() == 0)
    {
        return 0;
    }

    //������� ����� ����� ���� ����. ������ ��� ���� 1 ����
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    //����������. ������ �� ���� ��� 
    bool containsAce = false;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    //���� ���� ������ ��� � ����� �������� ���������, 
    //��� ���� 11 ����� 
    if (containsAce && total <= 11)
    {
        //��������� ������ 10 �����. �.�. ���� ��� �������� +1
        total += 10;
    }
    return total;
}

//:Hand ���������� �����
class GenericPlayer :public Hand
{
    friend ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();

    //���������� �� ������� ������
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
//�������, ������ 21
bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}
//�������� � �������
void GenericPlayer::bust() const
{
    cout << mName << " �������. \n";
}

//:Hand ����� + ��� ���������� 
class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();

    //������� ����������� ������ 52 �����
    void populate();

    //������������ �����
    void shuffle();

    //����� �� ����� ����� � ����
    void deal(Hand& aHand);

    //���� ���. ����� ������, ���� �����
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
    //������� ����������� ������
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

void Deck::deal(Hand& aHand) //�������� �������� �� ������ - ����.
{
    if (!mCards.empty())
    {
        aHand.add(mCards.back());
        mCards.pop_back();
    }
    else
    {
        cout << "����� �����������. �� ���� �����. ";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)  //�������� �������� �� ������ - ���������������.
{
    cout << endl;
    //���������� ������� (���� �� ������� � ����� �����)
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


//class Player; // :GenericPlayer  �����-�������
class Player : public GenericPlayer//  �����-�������
{
public:
    Player(const string& name = "");
    virtual ~Player();
    // ����� �� ����� ���
    virtual bool isHitting() const;
    void win() const;  // �������
    void lose() const; // ��������
    void push() const; // �����
};

Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
    cout << mName << ", ��� ����� ���? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << mName << ". �� ��������! \n";
}

void Player::lose() const
{
    cout << mName << " ��������. \n";
}

void Player::push() const
{
    cout << mName << " �����. \n";
}



//class HouseKeeper; // :GenericPlayer �����-���������
class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const std::string& name = "������");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    // ����������� �����
    virtual void flipFirstCard() const;

};

HouseKeeper::HouseKeeper(const std::string& name) : GenericPlayer(name) {}

HouseKeeper::~HouseKeeper() {};

bool HouseKeeper::isHitting() const
{
    return (getTotal() <= 16);
}

// ����������� �����
void HouseKeeper::flipFirstCard() const
{
    if (!(mCards.empty()))
    {
        mCards[0]->flip();
    }
    else
    {
        cout << "��� ���� ��� ����������!\n";
    }
}

//�������� ������ ����
class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //������ � ����!
    void Play();
private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;
};

Game::Game(const vector<string>& names)
{
    //������� ������ �������
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        mPlayers.push_back(Player(*pName));
    }
    //�������������� ���
    srand(static_cast<unsigned int>(time(NULL)));// �������������� time_t
    mDeck.populate();
    mDeck.shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    //����� ���� �� 2 �����
    vector<Player>::iterator pPlayer;

    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            mDeck.deal(*pPlayer);
        }
        mDeck.deal(mHouse);
    }
    //������ ������ ����� ������
    mHouse.flipFirstCard();

    //�������� ��� ����� �� �����
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << mHouse << endl;
    // ����� �������������� ����� �������
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        mDeck.additionalCards(*pPlayer);
    }

    //����������� ������ ����� ������
    mHouse.flipFirstCard();
    cout << endl << mHouse;

    //������� �������������� ����� ������
    mDeck.additionalCards(mHouse);
    if (mHouse.isBusted())
    {
        //��������� �� �������
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
        //�������� ����� ������� � ������
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()) && (pPlayer->getTotal() > mHouse.getTotal()))
            {//���� �� ������� � ������ �������
                pPlayer->win();
            }
            else if ((pPlayer->isBusted()) || (!(pPlayer->isBusted()) && pPlayer->getTotal() < mHouse.getTotal()))
            {
                pPlayer->lose();
            }
            else
            {
                pPlayer->push(); //�����
            }

        }
    }
    //�������� ����� � �����
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    mHouse.clear();
}