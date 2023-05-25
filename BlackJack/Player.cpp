#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
    cout << mName << ", Вам нужна еще? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << mName << ". Вы выиграли! \n";
}

void Player::lose() const
{
    cout << mName << " Проиграл. \n";
}

void Player::push() const
{
    cout << mName << " Ничья. \n";
}