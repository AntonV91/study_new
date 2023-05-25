#include "Game.h"
#include "GenericPlayer.h"
#include "Deck.h"
#include "HouseKeeper.h"
#include "Player.h"
#include "Card.h"
#include <iostream>
#include <vector>

using namespace std;

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

//��������� �������
ostream& operator <<(ostream& os, const Card& aCard);
ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);
