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

//прототипы функций
ostream& operator <<(ostream& os, const Card& aCard);
ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);
