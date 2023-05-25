// ������ 3.
// ������������ ��������� �����������. 
// �������� ��������� ������ (��������, �����, ������������, ����). 
// �������� ������ �� 10 ����.
// ���������� ��� ���� ��������� �����������:
// - ������ ���� ����;
// - ������������� �����;
// - ����� ���� �� ������;
// - ����� ����� �� ��������;

// ������ ����, ���������!
// ������ ��� ������ �����, ��� ��� ������� �� ���� ���������� �������� (�� ���� ������� ��� ������!!),
// �.�., ���� ��������� � �������� �������� ��� �������, ����� � ���� � � �������� �������, 
// � � ������������� ����������. ���� ���� ��������� ��������� (����������� ������ �� ��������), 
// ����� �� ��������, ��� � �������. ����� �������� ������ �� ��������. 
// ����� �������, ��� �� �� ����� �������� � �� �������� ��� ���������. �������!


#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <cstring>

using namespace std;

// ������� ��������� ���������� � ������ "��������", "�����", "������������" � "����"
// ����� ����� ������ ����� string, �.�. � ���������� ��������� � ��������� �� char ����
struct Library
{
    string title;
    string author;
    string publisher;
    string genre;
};

// ���������� ������������� ��� enum ��� ������������� ������� ����
//
enum userChoice
{
    Exit = 0,
    Print = 1,
    AddBook = 2,
    DeleteBook = 3,
    /*SearchTitle = 4,
    SearchAuthor = 5,
    SearchGenre = 6,*/
    EditBook = 7
};

//enum editBookVar
//{
//    Title = 1,
//    Author = 2,
//    Publisher = 3,
//    Genre = 4,
//};

using namespace std;

void title(); // �����������
void userMenu(vector <Library> book); // ����� ����������������� ����
Library Input(Library newBook); // ������� "������", � ������� ��������� ������ �� ���������
vector <Library> addBook(vector <Library> book, Library newBook); // ��������� ����� � ����������
vector <Library> deleteBook(vector <Library> book, int deleteChoice); // �������
void initBooks(Library book); // �������������� �����
void showAll(Library book); // ������� ����� �� �����
//int editBook(Library*& books, int size);

int deleteChoice;
Library newBook;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    title();

    vector <Library> book;
    book.reserve(10);

    auto iter = book.cbegin();

    Library book1;
    {
        book1.title = "������-�������";
        book1.author = "�������� �������";
        book1.publisher = "������-��������";
        book1.genre = "�����";
    };
    book.push_back(book1);

    Library book2;
    {
        book2.title = "������������ � ���������";
        book2.author = "����� �����������";
        book2.publisher = "��������";
        book2.genre = "�����";
    };
    book.push_back(book2);

    Library book3;
    {
        book3.title = "�����";
        book3.author = "������ ��������� ��� ø��";
        book3.publisher = "�����";
        book3.genre = "�����";
    };
    book.push_back(book3);

    Library book4;
    {
        book4.title = "������ �� �������";
        book4.author = "������ ����������";
        book4.publisher = "�����";
        book4.genre = "����������";
    };
    book.push_back(book4);

    Library book5;
    {
        book5.title = "��� � ������";
        book5.author = "������ ����";
        book5.publisher = "�������������";
        book5.genre = "����";
    };
    book.push_back(book5);

    Library book6;
    {
        book6.title = "������� ������";
        book6.author = "������ �������";
        book6.publisher = "��������";
        book6.genre = "�������";
    };
    book.push_back(book6);

    Library book7;
    {
        book7.title = "����� ��� �����";
        book7.author = "������� ������";
        book7.publisher = "���";
        book7.genre = "������";
    };
    book.push_back(book7);

    Library book8;
    {
        book8.title = "�����";
        book8.author = "���� �����";
        book8.publisher = "��������-�����";
        book8.genre = "�����";
    };
    book.push_back(book8);

    Library book9;
    {
        book9.title = "��� � ������ � �������";
        book9.author = "������� ��������";
        book9.publisher = "������-��������";
        book9.genre = "�������";
    };
    book.push_back(book9);

    Library book10;
    {
        book10.title = "� ������ ����� ���";
        book10.author = "����� ������";
        book10.publisher = "���";
        book10.genre = "����������";
    };
    book.push_back(book10);

    // ����� ������� ����� ������� ����� �� �����,
    // ��� �� ���� ������ � showAll c ����������
    // (�����, �������, �� � ����� ���� ����� :)
    initBooks(book1);
    initBooks(book2);
    initBooks(book3);
    initBooks(book4);
    initBooks(book5);
    initBooks(book6);
    initBooks(book7);
    initBooks(book8);
    initBooks(book9);
    initBooks(book10);

    userMenu(book);

    return 0;
}

void title()
{
    cout << "\t\t\t\t\t === ���������� === \t\t\t\t\t" << endl << endl;
    cout << "����� ���������� � ����������, ����! ����� ��������� ��� � ��� ����!" << endl << endl;
}

Library Input(Library newBook)
{
    cout << "��������: " << newBook.title << endl;
    cout << "�����: " << newBook.author << endl;
    cout << "������������: " << newBook.publisher << endl;
    cout << "����: " << newBook.genre << endl;
    cout << endl;
    return newBook;
}
void initBooks(Library book)
{
    cout << "��������: " << book.title << endl;
    cout << "�����: " << book.author << endl;
    cout << "������������: " << book.publisher << endl;
    cout << "����: " << book.genre << endl;
    cout << endl;
}

// ��� ������� � input, ����� ���� ��� ����� ������� � ������ ��������
vector <Library> addBook(vector <Library> book, Library newBook)
{
    Input(newBook);
    book.push_back(newBook);
    cout << "�� �������� ����� � ����������!" << endl << endl;
    return book;
}

vector <Library> deleteBook(vector <Library> book, int deleteChoice)
{
    auto iter = book.cbegin();
    cout << "������� ����� �����, ������� ���������� �������: ";
    cin >> deleteChoice;
    book.erase(iter + (deleteChoice - 1)); // ��������� ���������� �������� ����� ����� �����
    // (iter + ����� �����, ��������� ������ - 1)
    cout << "�� ������� ����� �� ����������!" << endl << endl;
    return book;
}

void showAll(vector <Library> book)
{
    for (int i = 0; i < book.size(); i++)
    {
        cout << i + 1 << ") ";
        initBooks(book[i]);
    }
    cout << endl;
}

void userMenu(vector <Library> book)
{
    int userChoice;

    do {
        cout << "1 - �������� ��� �����" << endl;
        cout << "2 - �������� ����� � ����������" << endl;
        cout << "3 - ������� ����� �� ����������" << endl;
        //cout << "4 - ����� ����� �� ��������" << endl;
        //cout << "5 - ����� ����� �� �����" << endl;
        //cout << "6 - ����� ����� �� ������" << endl;
        //cout << "7 - ��������������� �����" << endl;*/
        cout << "0 - ����� �� ���������" << endl << endl;

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
            showAll(book);
        }
        break;
        case AddBook:
        {
            system("cls");
            cout << "���������, ����������, �������� ����� �����!" << endl << endl;
            addBook(book, newBook);
        }
        break;
        case DeleteBook:
        {
            showAll(book);
            system("cls");
            deleteBook(book, deleteChoice);

        }
        break;

        /*case EditBook:
        {
            system("cls");
            showAll(book);
            editBook(book);
        }
        break;*/
        }

    } while (userChoice != Exit);
}

//vector <Library> editBook(vector <Library> book)
//{
//    int bookChoice;
//    int editBookVar;
//    char* newVal = new char[size];
//    
//    cout << "�������� ����� �����, ������� ���������� ���������������: " << endl;
//    cin >> bookChoice;
//    if (bookChoice > size || bookChoice < 1)
//    {
//        cout << "����� � ����� ������� � ���������� �����������!" << endl;
//        return 1;
//    }
//    bookChoice--;
//    cout << endl;
//    cout << "��� �� ������ ���������������: " << endl << endl;
//    cout << "1 - �������� �����" << endl;
//    cout << "2 - ������ �����" << endl;
//    cout << "3 - �������� �����" << endl;
//    cout << "4 - ���� �����" << endl << endl;
//    cin >> editBookVar;
//    cout << endl;
//
//    switch (editBookVar)
//    {
//    case Title:
//        cout << "������� ������ �������� �����: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].title, newVal);
//        cout << endl;
//        break;
//    case Author:
//        cout << "������� ������� ������ �����: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].author, newVal);
//        cout << endl;
//        break;
//    case Publisher:
//        cout << "������� ������� �������� �����: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].publisher, newVal);
//        cout << endl;
//        break;
//    case Genre:
//        cout << "������� ������ ����: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].genre, newVal);
//        cout << endl;
//        break;
//    }
//    cout << "������� ����������!" << endl << endl;
//
//}

