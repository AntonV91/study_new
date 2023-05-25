// ������ 3.
// ������������ ��������� �����������. 
// �������� ��������� ������ (��������, �����, ������������, ����). 
// �������� ������ �� 10 ����.
// ���������� ��� ���� ��������� �����������:
// - ������ ���� ����;
// - ������������� �����;
// - ����� ���� �� ������;
// - ����� ����� �� ��������;
// - ���������� ������� �� �������� ����;
// - ���������� ������� �� ������;
// - ���������� ������� �� ������������ 

// (� ����������� ������� ����� - ���������� �����-�� �����, �� ����� �� �����. 
// ������ ����� ������� ��������/���������� ������.
// �������� � ��������� �������� �� ������)

#include <iostream>
#include <string>
#include <windows.h>
#include <cstring>

using namespace std;

// ������� ��������� ���������� � ������ "��������", "�����", "������������" � "����"
struct Library
{
    // ������ ����������� � 80 �������� (����� ���������, ����� ���������)
    char title[80];
    char author[80];
    char publisher[80];
    char genre[80];
};

// ���������� ������������� ��� enum ��� ������������� ������� ����
enum userChoice
{
    Exit = 0,
    Print = 1,
    AddBook = 2,
    DeleteBook = 3,
    SearchTitle = 4,
    SearchAuthor = 5,
    SearchGenre = 6,
    EditBook = 7
};

enum editBookVar
{
    Title = 1,
    Author = 2,
    Publisher = 3,
    Genre = 4,
};

using namespace std;

Library* Create(int size); // ������� ������ � �������
Library Input(); // ������� "������", � ������� ��������� ������ �� ���������
Library* addBook(Library* books, int& size, Library book); // ��������� ����� � ����������
Library* deleteBook(Library* books, int& size, char* searchBookTitle); // ������� �����
void title(); // �����������
void userMenu(Library* books, int& size); // ����� ����������������� ����
void initBooks(Library books); // �������������� �����
void showAll(Library* books, int size); // ������� ����� �� �����
void searchBookTitle(Library* books, int& size, char* searchBookTitle); // ���� ����� �� ��������
void searchBookGenre(Library* books, int& size, char* searchBookGenre); // ���� �� ������
void searchBookAuthor(Library* books, int& size, char* searchBookAuthor); // ���� �� �����
int editBook(Library*& books, int size);
void deleteBooksDin(Library* books); // ������� ������ ����� ��������� ���������

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int size = 20;
    Library* books = Create(size);

    // ��������� ��������� ������� (������ 20 ������ 10, ����� ��� ������ ������ ��� �����
    // �� ����� ����� ���� ������� ����� ����� ������)
    books[0] = { "������-�������", "�������� �������", "������-��������", "�����" };
    books[1] = { "������������ � ���������", "����� �����������", "��������", "�����" };
    books[2] = { "�����", "������ ��������� ��� ø��", "�����", "�����" };
    books[3] = { "������ �� �������", "������ ����������", "�����", "����������" };
    books[4] = { "��� � ������", "������ ����", "�������������", "����" };
    books[5] = { "������� ������", "������ �������", "��������", "�������" };
    books[6] = { "����� ��� �����", "������� ������", "���", "������" };
    books[7] = { "�����", "���� �����", "��������-�����", "�����" };
    books[8] = { "��� � ������ � �������", "������� ��������", "�����", "�������" };
    books[9] = { "�������", "��������� ���", "������-��������", "����������" };
    books[10] = { "� ������ ����� ���", "����� ������", "���", "����������" };
    books[11] = { "����������� � �������", "������ ���������", "����� �����", "�������" };
    books[12] = { "������", "������ ����", "���", "�����" };
    books[13] = { "���� ��������", "��� �������", "�����", "�����" };
    books[14] = { "��", "������� �������", "�����", "����������" };
    books[15] = { "������� ����", "������ ����", "�����", "�������" };
    books[16] = { "�����", "���� ������", "�����", "��������" };
    books[17] = { "��������� ����������", "������ ���������", "����� �����", "�������" };
    books[18] = { "������", "����� ������", "���", "����������" };
    books[19] = { "������� �� ����", "������� ������", "���", "������" };

    title();
    userMenu(books, size);

    return 0;
}

void title()
{
    cout << "\t\t\t\t\t === ���������� === \t\t\t\t\t" << endl << endl;
    cout << "����� ���������� � ����������, ����! ����� ��������� ��� � ��� ����!" << endl << endl;
}

Library* Create(int size)
{
    Library* books = new Library[size];

    return books;
}

Library Input()
{
    Library book;
    cout << "��������:" << endl;
    // ������ ������������ cin ���������� ������� gets_s 
    // (��� ��������� ������ �� ������������ ������ ����� � ��������� � ������)
    // ��������� � �����, ��� �������� �� ������������ ������, � ���������� ��������� � cin
    // (����� ������� ������� ���������� �� �������, ����� �������� �� cin - �������� ��� ��)
    gets_s(book.title, 80);
    cout << "�����:" << endl;
    gets_s(book.author, 80);
    cout << "������������:" << endl;
    gets_s(book.publisher, 80);
    cout << "����:" << endl;
    gets_s(book.genre, 80);

    return book;
}
void initBooks(Library books)
{
    cout << "��������: " << books.title << endl;
    cout << "�����: " << books.author << endl;
    cout << "������������: " << books.publisher << endl;
    cout << "����: " << books.genre << endl;
    cout << endl;
}

void userMenu(Library* books, int& size)
{
    int userChoice;
    do {
        cout << "1 - �������� ��� �����" << endl;
        cout << "2 - �������� ����� � ����������" << endl;
        cout << "3 - ������� ����� �� ����������" << endl;
        cout << "4 - ����� ����� �� ��������" << endl;
        cout << "5 - ����� ����� �� �����" << endl;
        cout << "6 - ����� ����� �� ������" << endl;
        cout << "7 - ��������������� �����" << endl;
        cout << "0 - ����� �� ���������" << endl << endl;
        // ������������� ����� �� ��������
        // ������������� ����� �� ������
        // ������������� ����� �� ������������

        cout << "�������� ��������������� ����� ����: ";
        cin >> userChoice;
        cout << endl;
        cin.ignore();

        switch (userChoice)
        {
        case Exit:
        {
            cout << "�� ����� ������, ����!" << endl;
        }
        break;
        case Print:
        {
            system("cls");
            showAll(books, size);
        }
        break;
        case AddBook:
        {
            system("cls");
            cout << "���������, ����������, �������� ����� �����!" << endl << endl;
            books = addBook(books, size, Input());
        }
        break;
        case DeleteBook:
        {
            system("cls");
            char searchName[40];
            showAll(books, size);
            cout << "������� �������� �����, ������� ������ �������: ";
            gets_s(searchName, 40);
            system("cls");
            books = deleteBook(books, size, searchName);
        }
        break;
        case SearchTitle:
        {
            system("cls");
            char searchName[40];
            cout << "������� �������� ������� �����: ";
            gets_s(searchName, 40);
            cout << endl;
            searchBookTitle(books, size, searchName);
        }
        break;
        case SearchAuthor:
        {
            system("cls");
            char searchGenre[40];
            cout << "�����: �����, ��������, �����, �����, ����������, ����, �������, ������, �����, �������, ����������, �������, �����" << endl << endl;
            cout << "������� ���� ������� �����: ";
            gets_s(searchGenre, 40);
            cout << endl;
            searchBookGenre(books, size, searchGenre);
        }
        break;
        case SearchGenre:
        {
            system("cls");
            char searchAuthor[40];
            cout << "������� ������ ������� �����: ";
            gets_s(searchAuthor, 40);
            cout << endl;
            searchBookAuthor(books, size, searchAuthor);

        }
        break;
        case EditBook:
        {
            system("cls");
            showAll(books, size);
            editBook(books, size);
        }
        break;
        }

    } while (userChoice != Exit);
}

void showAll(Library* books, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ") ";
        initBooks(books[i]);
    }
    cout << endl;
}

Library* addBook(Library* books, int& size, Library book)
{
    // � tmp ����������� ������ ���������� �� 1 �����
    Library* tmp = Create(size + 1);
    for (int i = 0; i < size; i++)
    {
        *(tmp + i) = *(books + i);
    }
    *(tmp + size) = book;
    cout << endl;
    system("cls");
    cout << "�� �������� �����: \"" << book.title << "\"  � ����������!" << endl << endl;
    deleteBooksDin(books);
    size++;
    return tmp;
}

Library* deleteBook(Library* books, int& size, char* searchBookTitle)
{
    // � tmp ��������� ������ ���������� �� 1 �����
    Library* tmp = Create(size - 1);
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchBookTitle, books[i].title) == 0)
        {
            continue;
        }
        tmp[k] = books[i];
        k++;
    }
    size--;
    cout << "�� ������� �����: \"" << searchBookTitle << "\"  �� ����������!" << endl << endl;
    deleteBooksDin(books);
    return tmp;
}

void searchBookTitle(Library* books, int& size, char* searchBookTitle)
{
    for (int i = 0; i < size; i++)
    {
        // ������� strcmp() ���������� ��� ������ �, ���� ��� ���������, ���������� ����
        // ����� � ����� ���������� ��� ������������ ������ �� ������ ������������ 
        // (������� ��� ������ �� ��������, ����� - �� ������ � �����, ��������������)
        if (strcmp(searchBookTitle, books[i].title) == 0)
        {
            initBooks(books[i]);
            cout << endl;
        }
    }
}

// ������� ����� �� �����, ����� ���� ���� �����-�� ���� � ������ �����
void searchBookGenre(Library* books, int& size, char* searchBookGenre)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchBookGenre, books[i].genre) == 0)
        {
            initBooks(books[i]);
            cout << endl;
        }
    }
}
void searchBookAuthor(Library* books, int& size, char* searchBookAuthor)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchBookAuthor, books[i].author) == 0)
        {
            initBooks(books[i]);
            cout << endl;
        }
    }
}

int editBook(Library*& books, int size)
{
    int bookChoice;
    int editBookVar;
    char* newVal = new char[size];
    // ��� ������ ���������� � ����� ��� ������� ������� ��������� ������ 
    // (�� ��������� ������ � ����������� ����� � ������ Exit).
    // ������� ������� ����� string � getline, �� �� ���, �� ����� ��� ���������� ��������� ������
    // string newVal; - ������ � ��� ��� �����.������ ������� �������
    // getline (cin, newVal); - � �����
    // � �����-�� ������ ������ ����������, �� �� �������� � ����� :(
    cout << "�������� ����� �����, ������� ���������� ���������������: " << endl;
    cin >> bookChoice;
    if (bookChoice > size || bookChoice < 1)
    {
        cout << "����� � ����� ������� � ���������� �����������!" << endl;
        return 1;
    }
    bookChoice--;
    cout << endl;
    cout << "��� �� ������ ���������������: " << endl << endl;
    cout << "1 - �������� �����" << endl;
    cout << "2 - ������ �����" << endl;
    cout << "3 - �������� �����" << endl;
    cout << "4 - ���� �����" << endl << endl;
    cin >> editBookVar;
    cout << endl;

    switch (editBookVar)
    {
    case Title:
        cout << "������� ������ �������� �����: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].title, newVal);
        cout << endl;
        break;
    case Author:
        cout << "������� ������� ������ �����: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].author, newVal);
        cout << endl;
        break;
    case Publisher:
        cout << "������� ������� �������� �����: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].publisher, newVal);
        cout << endl;
        break;
    case Genre:
        cout << "������� ������ ����: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].genre, newVal);
        cout << endl;
        break;
    }
    cout << "������� ����������!" << endl << endl;

    delete[] newVal;
}

void deleteBooksDin(Library* books)
{
    delete[]books;
}