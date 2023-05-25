// Задача 3.
// Разработайте программу «Библиотека». 
// Создайте структуру «Книга» (название, автор, издательство, жанр). 
// Создайте массив из 10 книг.
// Реализуйте для него следующие возможности:
// - Печать всех книг;
// - Редактировать книгу;
// - Поиск книг по автору;
// - Поиск книги по названию;

// ДОБРЫЙ ДЕНЬ, ВЛАДИСЛАВ!
// СДАВАЯ ЭТУ ЗАДАЧУ ПОНЯЛ, ЧТО МНЕ СТРАШНО ЗА ВАШЕ МЕНТАЛЬНОЕ ЗДОРОВЬЕ (ВЫ ВЕДЬ БУДЕТЕТ ЭТО ЧИТАТЬ!!),
// Т.К., ИМЕЯ СЛОЖНОСТИ С РЕШЕНИЕМ СТРУКТУР БЕЗ ВЕКТОРА, ЗДЕСЬ Я УВЯЗ И В НЕХВАТКЕ ВРЕМЕНИ, 
// И В НЕДОПОНИМАНИИ МЕХАНИЗМОВ. СДАЮ ЛИШЬ НАЧАЛЬНЫЕ ЧЕРНОВИКИ (ЕСТЕСТВЕННО НИФИГА НЕ РАБОТАЕТ), 
// ЧТОБЫ ВЫ ПОНИМАЛИ, ЧТО Я ПЫТАЛСЯ. ФОКУС ВНИМАНИЯ СМЕЩАЮ НА КУРСОВОЕ. 
// ОЧЕНЬ НАДЕЮСЬ, ЧТО МЫ НА ПАРАХ РАЗБЕРЕМ И ВЫ ПОКАЖЕТЕ КАК ПРАВИЛЬНО. СПАСИБО!


#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <cstring>

using namespace std;

// Создаем структуру Библиотека с полями "название", "автор", "издательство" и "жанр"
// Здесь начал делать через string, т.к. в предыдущей сложности с переводом из char были
struct Library
{
    string title;
    string author;
    string publisher;
    string genre;
};

// Используем перечисляемый тип enum для идентификации пунктов меню
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

void title(); // Приветствие
void userMenu(vector <Library> book); // Вывод пользовательского меню
Library Input(Library newBook); // Создаем "шаблон", в который записывем данные из структуры
vector <Library> addBook(vector <Library> book, Library newBook); // Добавляем книгу в библиотеку
vector <Library> deleteBook(vector <Library> book, int deleteChoice); // Удалить
void initBooks(Library book); // Инициализаиуем книги
void showAll(Library book); // Выводим книги на экран
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
        book1.title = "Москва-Петушки";
        book1.author = "Венедикт Ерофеев";
        book1.publisher = "Азбука-классика";
        book1.genre = "поэма";
    };
    book.push_back(book1);

    Library book2;
    {
        book2.title = "Преступление и наказание";
        book2.author = "Федор Достоевский";
        book2.publisher = "Лабиринт";
        book2.genre = "роман";
    };
    book.push_back(book2);

    Library book3;
    {
        book3.title = "Фауст";
        book3.author = "Иоганн Вольфганг фон Гёте";
        book3.publisher = "СЗКЭО";
        book3.genre = "пьеса";
    };
    book.push_back(book3);

    Library book4;
    {
        book4.title = "Пикник на обочине";
        book4.author = "Братья Стругацкие";
        book4.publisher = "Эксмо";
        book4.genre = "фантастика";
    };
    book.push_back(book4);

    Library book5;
    {
        book5.title = "Миф о Сизифе";
        book5.author = "Альбер Камю";
        book5.publisher = "Полиграфиздат";
        book5.genre = "эссе";
    };
    book.push_back(book5);

    Library book6;
    {
        book6.title = "Хроники Амбера";
        book6.author = "Роджер Желязны";
        book6.publisher = "Лабиринт";
        book6.genre = "фэнтези";
    };
    book.push_back(book6);

    Library book7;
    {
        book7.title = "Жизнь без Карло";
        book7.author = "Дмитрий Горчев";
        book7.publisher = "АСТ";
        book7.genre = "сатира";
    };
    book.push_back(book7);

    Library book8;
    {
        book8.title = "Рубаи";
        book8.author = "Омар Хайям";
        book8.publisher = "Аргумент-Пресс";
        book8.genre = "стихи";
    };
    book.push_back(book8);

    Library book9;
    {
        book9.title = "Как я воевал с Россией";
        book9.author = "Уинстон Черчилль";
        book9.publisher = "Азбука-классика";
        book9.genre = "мемуары";
    };
    book.push_back(book9);

    Library book10;
    {
        book10.title = "О дивный новый мир";
        book10.author = "Олдос Хаксли";
        book10.publisher = "АСТ";
        book10.genre = "антиутопия";
    };
    book.push_back(book10);

    // Таким образом можно вывести книги на экран,
    // это по идее пойдет в showAll c нумерацией
    // (вывод, конечно, не в таком виде будет :)
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
    cout << "\t\t\t\t\t === БИБЛИОТЕКА === \t\t\t\t\t" << endl << endl;
    cout << "Добро пожаловать в библиотеку, друг! Давай посмотрим что у нас есть!" << endl << endl;
}

Library Input(Library newBook)
{
    cout << "Название: " << newBook.title << endl;
    cout << "Автор: " << newBook.author << endl;
    cout << "Издательство: " << newBook.publisher << endl;
    cout << "Жанр: " << newBook.genre << endl;
    cout << endl;
    return newBook;
}
void initBooks(Library book)
{
    cout << "Название: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Издательство: " << book.publisher << endl;
    cout << "Жанр: " << book.genre << endl;
    cout << endl;
}

// Тут увязать с input, чтобы поле для ввода ответов и записи работало
vector <Library> addBook(vector <Library> book, Library newBook)
{
    Input(newBook);
    book.push_back(newBook);
    cout << "Вы добавили книгу в библиотеку!" << endl << endl;
    return book;
}

vector <Library> deleteBook(vector <Library> book, int deleteChoice)
{
    auto iter = book.cbegin();
    cout << "Введите номер книги, которую необходимо удалить: ";
    cin >> deleteChoice;
    book.erase(iter + (deleteChoice - 1)); // попытался смастерить удаление книги через номер
    // (iter + номер книги, введенной юзером - 1)
    cout << "Вы удалили книгу из библиотеки!" << endl << endl;
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
        cout << "1 - Показать все книги" << endl;
        cout << "2 - Добавить книгу в библиотеку" << endl;
        cout << "3 - Удалить книгу из библиотеки" << endl;
        //cout << "4 - Найти книгу по названию" << endl;
        //cout << "5 - Найти книгу по жанру" << endl;
        //cout << "6 - Найти книгу по автору" << endl;
        //cout << "7 - Отредактировать книгу" << endl;*/
        cout << "0 - ВЫХОД ИЗ ПРОГРАММЫ" << endl << endl;

        cout << "Выберите соответствующий пункт меню: ";
        cin >> userChoice;
        cout << endl;
        cin.ignore();

        switch (userChoice)
        {
        case Exit:
        {
            cout << "До новых встреч, друг!" << endl;
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
            cout << "Заполните, пожалуйста, карточку новой книги!" << endl << endl;
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
//    cout << "Выберите номер книги, которую необходимо отредактировать: " << endl;
//    cin >> bookChoice;
//    if (bookChoice > size || bookChoice < 1)
//    {
//        cout << "Книга с таким номером в библиотеке отсутствует!" << endl;
//        return 1;
//    }
//    bookChoice--;
//    cout << endl;
//    cout << "Что вы хотите отредактировать: " << endl << endl;
//    cout << "1 - Название книги" << endl;
//    cout << "2 - Автора книги" << endl;
//    cout << "3 - Издателя книги" << endl;
//    cout << "4 - Жанр книги" << endl << endl;
//    cin >> editBookVar;
//    cout << endl;
//
//    switch (editBookVar)
//    {
//    case Title:
//        cout << "Введите верное название книги: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].title, newVal);
//        cout << endl;
//        break;
//    case Author:
//        cout << "Введите верного автора книги: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].author, newVal);
//        cout << endl;
//        break;
//    case Publisher:
//        cout << "Введите верного издателя книги: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].publisher, newVal);
//        cout << endl;
//        break;
//    case Genre:
//        cout << "Введите верный жанр: ";
//        cin >> newVal;
//        strcpy_s(books[bookChoice].genre, newVal);
//        cout << endl;
//        break;
//    }
//    cout << "Успешно исправлено!" << endl << endl;
//
//}

