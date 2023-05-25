#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "GenericPlayer.h"
#include "Game.h"
#include "Hand.h"
#include "HouseKeeper.h"
#include <windows.h>

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

// ��� �������������� ��������� ��� ����������: ��������� �������������, �� � ������ �� �����
// � ������ ������ ��� ����. ����� ��������� ���� � ���� 1 �����, 1 MAIN � CPP �Ѩ �������� - 
// ��� ����� � ����� BLACKJACK �����������
// � ��������� ��������, ��� ��� ������ ���������� �������� ���� �� �����, ������ ������ ������� ���
// �������� ����� ��������� � �������� (� ���� ��� ������� �� ������ ����� �� ����)

