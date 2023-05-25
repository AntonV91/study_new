//-----===== ����� ����� ������� ������ =====-----
//������� 2� ������ ��������. NxN ������ ������ � ����������.
//���������� � ���� ���� ����������� '*' ��� '#' ��� ������� ���������.
//��������� � ��������� ���������� � �������� ������� -'O'.
//������� �������, ������� ����� ���������� � �� ����.
//���������� ��������� WASD ��� ���������.
//
//��� ������� �� (������) � ����������� ����������� ��������
//"��������" '-' '|' ��� '�' � ����� �� �����.
//
//�������� � �������� ������ ����� �������.

#include <iostream>
#include <time.h>
#include <conio.h>

// ���� ��������� ���������� �� ������� (���-��� ��������, ���-��� �������/�����). ���� ��� �����.
// ���������� ��� ���� � ���� ����� :-)
// ��������� ������� ������� ��� �������� - ���������� � �������� � ��������� (������� ����)

using namespace std;

void createBoard(int s, char** board);
bool humanMov(int s, char** board, int& humX, int& humY);
void humanPos(int s, char** board, int& humX, int& humY);
void shootBul(int s, char** board, int& humX, int& humY, char dir, int& bulX, int& bulY);
//void moveBul(int s, char** board, int& bulX, int& bulY);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int humX = 1, humY = 1;
	/*int* phumX = &humX;
	int* phumY = &humY;*/

	/*while (1) // �� ��� ������ ������ while, ��������������� ���
	{*/
	int size;
	void title();
	cout << "����� ���������� � ��� ��������-�����! ������� ��������� ������� ����������� ���������!" << endl << endl;
	do
	{
		cout << "������� ������ ������� (�� 5 �� 20): "; // ��������� ��� �������
		cin >> size;
		cout << endl;
		cout << "�� ����� �������� ��������! ���������� ��� ���!" << endl << endl;
	} while (size < 5 || size > 20);

	char** a1 = new char* [size];
	for (int i = 0; i < size; i++)
	{
		a1[i] = new char[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1) a1[i][j] = '*';
			else a1[i][j] = ' ';
	}
	humanPos(size, a1, humX, humY);
	createBoard(size, a1);

	// ==== �������� ����
	bool breakStatus = false;
	while (!breakStatus)
	{
		breakStatus = humanMov(size, a1, humX, humY);
	}
	//shoot_bullet();
	//move_bullet();

/*	break;
}*/
}

void createBoard(int s, char** board) // ������� ���� ��� ����
{
	system("cls");
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void humanPos(int s, char** board, int& humX, int& humY)
{
	srand(time(NULL));
	humX = rand() % (s - 2) + 1; // ������ ��������� ��������� �� ��� X
	humY = rand() % (s - 2) + 1; // ������ ��������� ��������� �� ��� X
	board[humY][humX] = 'O';
}

bool humanMov(int s, char** board, int& humX, int& humY)
{
	bool flag = false;

	char c = _getch();
	switch (c)
	{
	case 'w': // �������� ���� (����� ����������� ��� �� ������, ��� � �� ������� �������)
	case 'W': // ����� �������� ��� ������� ���������
		if (board[humY - 1][humX] == '*')
		{
			board[humY][humX] = 'X'; // "�������" ��������� ��� ������������ �� ������
			flag = true;
		}
		else
		{
			board[humY][humX] = ' '; // ������ 0 �� ������ ��� �����������
			board[humY - 1][humX] = 'O'; // ������ 0 � ����� ������ �� ����������� ��������
			humY--;
		}
		break;
	case 'a':
	case 'A':
		if (board[humY][humX - 1] == '*')
		{
			board[humY][humX] = 'X';
			flag = true;
		}
		else
		{
			board[humY][humX] = ' ';
			board[humY][humX - 1] = 'O';
			humX--;
		}
		break;
	case 's':
	case 'S':
		if (board[humY + 1][humX] == '*')
		{
			board[humY][humX] = 'X';
			flag = true;
		}
		else
		{
			board[humY][humX] = ' ';
			board[humY + 1][humX] = 'O';
			humY++;
		}
		break;
	case 'd':
	case 'D':
		if (board[humY][humX + 1] == '*')
		{
			board[humY][humX] = 'X';
			flag = true;
		}
		else
		{
			board[humY][humX] = ' ';
			board[humY][humX + 1] = 'O';
			humX++;
		}
		break;
	}
	createBoard(s, board); // �������� ������� �������� ����
	return flag;
}

// ������� ��� ����������� �������� (������������; ������������ ������� � ���� � ������� � ������)
// �������� �� �� ���� � main
void shootBul(int s, char** board, int& humX, int& humY, char dir, int& bulX, int& bulY)
{
	switch (dir)
	{
	case 'w':
	case 'W':
		bulY = humY + 1; // �������� ���� ��� �������� �� ��� Y (����� +1, �.�. �������� �����)
		bulX = humX; // �� ��� X �� ������� (����� ����������)
		board[bulX][bulY] = '|';
		break;
	case 'a':
	case 'A':
		bulX = humX - 1;
		bulY = humY;
		board[bulX][bulY] = '-';
		break;
	case 's':
	case 'S':
		bulY = humY - 1;
		bulX = humX;
		board[bulX][bulY] = '|';
		break;
	case 'd':
	case 'D':
		bulX = humX + 1;
		bulY = humY;
		board[bulX][bulY] = '-';
		break;
	}
}

// ������� �������� ���� (����� �������� ����� ���������, ������ ���������������)
// � ���� ����� ������ ������� �� ������ ���������� ������� :-(

//void moveBul(int s, char** board, int& bulX, int& bulY)
//{
//	board[bulX][bulY] = ' ';
//	bulX--;
//	if (bulX >= 0)
//	{
//		board[bulX][bulY] = '|';
//	}
//}