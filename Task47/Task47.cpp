//-----===== Здесь пишем условие задачи =====-----
//Создать 2Д массив символов. NxN размер ввести с клавиатуры.
//Разместить в него поле огороженное '*' или '#' или другими символами.
//Забросить в случайные координаты в пределах массива -'O'.
//Создать функцию, которая будет перемещать О по полю.
//Управление клавишами WASD или стрелками.
//
//При нажатии на (ПРОБЕЛ) в направлении предыдущего движения
//"вылетает" '-' '|' или 'о' и летит до стены.
//
//Движения и выстрелы делать через функции.

#include <iostream>
#include <time.h>
#include <conio.h>

// Чуть поковырял реализацию из примера (кое-что исправил, кое-что добавил/убрал). Мало что менял.
// Разобрался что имел в виду автор :-)
// Попытался сделать функции для выстрела - подзастрял и вернулся к курсовому (времени мало)

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

	/*while (1) // на мой взгляд лишний while, закомментировал его
	{*/
	int size;
	void title();
	cout << "Добро пожаловать в наш лабиринт-шутер! Давайте определим размеры квадратного лабиринта!" << endl << endl;
	do
	{
		cout << "Введите размер массива (от 5 до 20): "; // ограничим для красоты
		cin >> size;
		cout << endl;
		cout << "Вы ввели неверное значение! Попробуйте еще раз!" << endl << endl;
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

	// ==== Основной блок
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

void createBoard(int s, char** board) // создаем поле для игры
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
	humX = rand() % (s - 2) + 1; // рандим положение персонажа по оси X
	humY = rand() % (s - 2) + 1; // рандим положение персонажа по оси X
	board[humY][humX] = 'O';
}

bool humanMov(int s, char** board, int& humX, int& humY)
{
	bool flag = false;

	char c = _getch();
	switch (c)
	{
	case 'w': // расширим кейс (чтобы реагировало как на нижний, так и на верхний регистр)
	case 'W': // можно добавить для русской раскладки
		if (board[humY - 1][humX] == '*')
		{
			board[humY][humX] = 'X'; // "убиваем" персонажа при столкновении со стеной
			flag = true;
		}
		else
		{
			board[humY][humX] = ' '; // меняем 0 на пробел при перемещении
			board[humY - 1][humX] = 'O'; // риусем 0 в новой клетке по направлению движения
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
	createBoard(s, board); // вызываем функцию создания поля
	return flag;
}

// Функция для направления выстрела (недописанная; застопорился немного и ушел с головой в курсач)
// Вызывать ее не стал в main
void shootBul(int s, char** board, int& humX, int& humY, char dir, int& bulX, int& bulY)
{
	switch (dir)
	{
	case 'w':
	case 'W':
		bulY = humY + 1; // смещение пули при выстреле по оси Y (здесь +1, т.к. стреляем вверх)
		bulX = humX; // по оси X не смещаем (далее аналогично)
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

// Функция движения пули (здесь основной затык получился, потому закомментировал)
// В свое время сдвигу массива не уделил достаточно времени :-(

//void moveBul(int s, char** board, int& bulX, int& bulY)
//{
//	board[bulX][bulY] = ' ';
//	bulX--;
//	if (bulX >= 0)
//	{
//		board[bulX][bulY] = '|';
//	}
//}