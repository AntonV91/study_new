// Задача 1.
// Написать функцию, добавляющую столбец двумерному массиву в указанную позицию.

#include <iostream>
#include <iomanip>

void title();
void initArray(int** ar, int rows, int cols);
void showArray(int** ar, int rows, int cols);
int** newArray(int rows, int cols);
void addCol(int** ar, int rows, int cols, int temp);
void inputVerify(int** ar, int rows, int cols, int userchoice);
void deleteArray(int** ar, int rows, int cols);

using namespace std;

int userChoice; // Глобальная переменная для выбора нужного столбца

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    title();
    cout << endl;
    // Просим пользователя ввести количество строк и столбцов в массиве
    cout << "Введите количество строк массива: ";
    int rows;
    cin >> rows;
    cout << "Введите количество столбцов массива: ";
    int cols;
    cin >> cols;
    cout << endl;

    int** ar = newArray(rows, cols);
    initArray(ar, rows, cols);
    showArray(ar, rows, cols);
    cout << endl;
    inputVerify(ar, rows, cols, userChoice);

    deleteArray(ar, rows, cols);
    cout << "Память удалена! До свидания!" << endl << endl;

    system("pause");
    return 0;
}

void title()
{
    cout << "Написать функцию, добавляющую столбец двумерному массиву в указанную позицию" << endl;
}

void initArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ar[i][j] = rand() % 20 + (-10);
        }
    }
}

void showArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << ar[i][j] << " | ";
        }
        cout << endl;
    }
}

// Создаем функцию для массива, с которым будем работать
int** newArray(int rows, int cols)
{
    int** ar = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        ar[i] = new int[cols];
    }
    return ar;
}

// Создаем функцию для пользовательского ввода нужного столбца, а также его проверки
// (внутри используем функцию addCol и выводим итоговый массив на экран)
void inputVerify(int** ar, int rows, int cols, int userChoice)
{
    do
    {
        cout << "Введите позицию (номер столбца), в которую необходимо вставить новый столбец: (от 1 до " << cols + 1 << "): ";
        cin >> userChoice;
        if (userChoice >= 1 && userChoice <= cols + 1)
        {
            cols++;
            addCol(ar, rows, cols, userChoice);
            cout << endl;
            showArray(ar, rows, cols);
            cout << endl;
        }
        else
        {
            cout << "Вы ввели неправильный номер столбца! Попробуйте еще раз!" << endl;
            cout << endl;
        }

    } while (userChoice < 1 || userChoice > cols + 1);
}

// Добавляем столбец в исходный массив
void addCol(int** ar, int rows, int cols, int temp)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Выполняем сдвиг массива на одну позицию вправо после добавленного столбца
            if (j == temp - 1)
            {
                for (int k = cols; k > temp - 1; k--)
                {
                    ar[i][k] = ar[i][k - 1];
                }
                // Инициализируем новый столбец (заполняем для наглядности 
                // цифрами другого порядка, чтобы он сразу "бросался в глаза") 
                ar[i][j] = rand() % 200 + (-100);
            }
        }
    }
}

void deleteArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        if (ar[i])
        {
            ar[i] = nullptr;
            delete[] ar[i];
        }
        else
            cout << "ERROR: Память уже была освобождена!" << endl;
    }
    if (ar)
    {
        ar = nullptr;
        delete[] ar;
    }
    else
        cout << "ERROR: Память уже была освобождена!" << endl;
}