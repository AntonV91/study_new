// ���� "��������"
//
//�������:
//������� ������� � ������ ��� ��������� �����
//�������� ������ ����� ������
//���������� ���� ������� � ������
//������� ������� �������������� �����
//�������� ������ ����� ������
//������� �������������� ����� ������
//���� � ������ �������
//��� ������ ��� �������� ����������
//�����
//��� ������� ������
//���� � ������ ��� ��������
//���� ����� ����� ������ ������, ��� � ������
//����� ���������
//����� ���� ����� ����� ������ ������, ��� � ������
//����� �����������
//�����
//����������� �����
//������� ����� ���� �������

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "Header.h"

using namespace std;

//��������� �������
ostream& operator <<(ostream& os, const Card& aCard);
ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t\t����� ���������� � ������!\n";
    cout << "\t\t\t������ � ��������21 !\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "������� ������� ����� ������? (1-7): \n";
        cin >> numPlayers;
    }

    vector<string>names;
    string name;

    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "������� ��� ������: \n";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    //�������� ���� ����
    Game aGame(names);

    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\n ������ ������� ���? (Y/N): \n";
        cin >> again;
    }
    return 0;
}

ostream& operator <<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };
    if (aCard.mIsFaceUp)
    {
        os << RANKS[aCard.mRank] << SUITS[aCard.mSuit];
    }
    else {
        os << "XX";
    }
    return os;
}

ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer)

{
    os << aGenericPlayer.mName << " :\t";
    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.mCards.empty())
    {
        for (pCard = aGenericPlayer.mCards.begin();
            pCard != aGenericPlayer.mCards.end();
            ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.getTotal() != 0)
        {
            cout << "(" << aGenericPlayer.getTotal() << ")";
        }
    }
    else
    {
        os << "<�����>";
    }
    return os;
}