// Задача 3.
// Разработайте программу «Библиотека». 
// Создайте структуру «Книга» (название, автор, издательство, жанр). 
// Создайте массив из 10 книг.
// Реализуйте для него следующие возможности:
// - Печать всех книг;
// - Редактировать книгу;
// - Поиск книг по автору;
// - Поиск книги по названию;
// - Сортировка массива по названию книг;
// - Сортировка массива по автору;
// - Сортировка массива по издательству 

// (С СОРТИРОВКОЙ МУЧАЛСЯ ДОЛГО - ПОЛУЧАЛАСЬ КАКАЯ-ТО ФИГНЯ, по итогу не успел. 
// Вместо этого добавил удаление/добавление строки.
// Попробую в векторном варианте ее добить)

#include <iostream>
#include <string>
#include <windows.h>
#include <cstring>

using namespace std;

// Создаем структуру Библиотека с полями "название", "автор", "издательство" и "жанр"
struct Library
{
    // Задаем ограничение в 80 символов (можем увеличить, можем уменьшить)
    char title[80];
    char author[80];
    char publisher[80];
    char genre[80];
};

// Используем перечисляемый тип enum для идентификации пунктов меню
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

Library* Create(int size); // Создаем массив с книгами
Library Input(); // Создаем "шаблон", в который записывем данные из структуры
Library* addBook(Library* books, int& size, Library book); // Добавляем книгу в библиотеку
Library* deleteBook(Library* books, int& size, char* searchBookTitle); // Удаляем книгу
void title(); // Приветствие
void userMenu(Library* books, int& size); // Вывод пользовательского меню
void initBooks(Library books); // Инициализаиуем книги
void showAll(Library* books, int size); // Выводим книги на экран
void searchBookTitle(Library* books, int& size, char* searchBookTitle); // Ищем книгу по названию
void searchBookGenre(Library* books, int& size, char* searchBookGenre); // Ищем по автору
void searchBookAuthor(Library* books, int& size, char* searchBookAuthor); // Ищем по жанру
int editBook(Library*& books, int size);
void deleteBooksDin(Library* books); // Очищаем память после отработки программы

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int size = 20;
    Library* books = Create(size);

    // Заполняем структуру книгами (создал 20 вместо 10, чтобы при выводе автора или жанра
    // на экран можно было вывести более одной записи)
    books[0] = { "Москва-Петушки", "Венедикт Ерофеев", "Азбука-классика", "поэма" };
    books[1] = { "Преступление и наказание", "Федор Достоевский", "Лабиринт", "роман" };
    books[2] = { "Фауст", "Иоганн Вольфганг фон Гёте", "СЗКЭО", "пьеса" };
    books[3] = { "Пикник на обочине", "Братья Стругацкие", "Эксмо", "фантастика" };
    books[4] = { "Миф о Сизифе", "Альбер Камю", "Полиграфиздат", "эссе" };
    books[5] = { "Хроники Амбера", "Роджер Желязны", "Лабиринт", "фэнтези" };
    books[6] = { "Жизнь без Карло", "Дмитрий Горчев", "АСТ", "сатира" };
    books[7] = { "Рубаи", "Омар Хайям", "Аргумент-Пресс", "стихи" };
    books[8] = { "Как я воевал с Россией", "Уинстон Черчилль", "Эксмо", "мемуары" };
    books[9] = { "Солярис", "Станислав Лем", "Азбука-классика", "фантастика" };
    books[10] = { "О дивный новый мир", "Олдос Хаксли", "АСТ", "антиутопия" };
    books[11] = { "Путешествие в Икстлан", "Карлос Кастанеда", "София Медиа", "мистика" };
    books[12] = { "Сияние", "Стивен Кинг", "АСТ", "ужасы" };
    books[13] = { "Анна Каренина", "Лев Толстой", "Эксмо", "роман" };
    books[14] = { "Мы", "Евгений Замятин", "Эксмо", "антиутопия" };
    books[15] = { "Зеленая миля", "Стивен Кинг", "Эксмо", "мистика" };
    books[16] = { "Фирма", "Джон Гришэм", "Эксмо", "детектив" };
    books[17] = { "Отдельная реальность", "Карлос Кастанеда", "София Медиа", "мемуары" };
    books[18] = { "Остров", "Олдос Хаксли", "АСТ", "антиутопия" };
    books[19] = { "Деление на ноль", "Дмитрий Горчев", "АСТ", "сатира" };

    title();
    userMenu(books, size);

    return 0;
}

void title()
{
    cout << "\t\t\t\t\t === БИБЛИОТЕКА === \t\t\t\t\t" << endl << endl;
    cout << "Добро пожаловать в библиотеку, друг! Давай посмотрим что у нас есть!" << endl << endl;
}

Library* Create(int size)
{
    Library* books = new Library[size];

    return books;
}

Library Input()
{
    Library book;
    cout << "Название:" << endl;
    // Вместо стандартного cin используем функцию gets_s 
    // (она считывает строку из стандартного потока ввода и сохраняет в буфере)
    // Насколько я понял, она защищает от переполнения буфера, а функционал совпадает с cin
    // (такой вариант решения подсмотрел на форумах, можно заменить на cin - работает так же)
    gets_s(book.title, 80);
    cout << "Автор:" << endl;
    gets_s(book.author, 80);
    cout << "Издательство:" << endl;
    gets_s(book.publisher, 80);
    cout << "Жанр:" << endl;
    gets_s(book.genre, 80);

    return book;
}
void initBooks(Library books)
{
    cout << "Название: " << books.title << endl;
    cout << "Автор: " << books.author << endl;
    cout << "Издательство: " << books.publisher << endl;
    cout << "Жанр: " << books.genre << endl;
    cout << endl;
}

void userMenu(Library* books, int& size)
{
    int userChoice;
    do {
        cout << "1 - Показать все книги" << endl;
        cout << "2 - Добавить книгу в библиотеку" << endl;
        cout << "3 - Удалить книгу из библиотеки" << endl;
        cout << "4 - Найти книгу по названию" << endl;
        cout << "5 - Найти книгу по жанру" << endl;
        cout << "6 - Найти книгу по автору" << endl;
        cout << "7 - Отредактировать книгу" << endl;
        cout << "0 - ВЫХОД ИЗ ПРОГРАММЫ" << endl << endl;
        // Отсортировать книги по названию
        // Отсортировать книги по автору
        // Отсортировать книги по издательству

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
            showAll(books, size);
        }
        break;
        case AddBook:
        {
            system("cls");
            cout << "Заполните, пожалуйста, карточку новой книги!" << endl << endl;
            books = addBook(books, size, Input());
        }
        break;
        case DeleteBook:
        {
            system("cls");
            char searchName[40];
            showAll(books, size);
            cout << "Введите название книги, которую хотите удалить: ";
            gets_s(searchName, 40);
            system("cls");
            books = deleteBook(books, size, searchName);
        }
        break;
        case SearchTitle:
        {
            system("cls");
            char searchName[40];
            cout << "Введите название искомой книги: ";
            gets_s(searchName, 40);
            cout << endl;
            searchBookTitle(books, size, searchName);
        }
        break;
        case SearchAuthor:
        {
            system("cls");
            char searchGenre[40];
            cout << "Жанры: поэма, детектив, роман, пьеса, фантастика, эссе, фэнтези, сатира, стихи, мемуары, антиутопия, мистика, ужасы" << endl << endl;
            cout << "Введите жанр искомой книги: ";
            gets_s(searchGenre, 40);
            cout << endl;
            searchBookGenre(books, size, searchGenre);
        }
        break;
        case SearchGenre:
        {
            system("cls");
            char searchAuthor[40];
            cout << "Введите автора искомой книги: ";
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
    // В tmp увеличиваем размер библиотеки на 1 пункт
    Library* tmp = Create(size + 1);
    for (int i = 0; i < size; i++)
    {
        *(tmp + i) = *(books + i);
    }
    *(tmp + size) = book;
    cout << endl;
    system("cls");
    cout << "Вы добавили книгу: \"" << book.title << "\"  в библиотеку!" << endl << endl;
    deleteBooksDin(books);
    size++;
    return tmp;
}

Library* deleteBook(Library* books, int& size, char* searchBookTitle)
{
    // В tmp уменьшаем размер библиотеки на 1 пункт
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
    cout << "Вы удалили книгу: \"" << searchBookTitle << "\"  из библиотеки!" << endl << endl;
    deleteBooksDin(books);
    return tmp;
}

void searchBookTitle(Library* books, int& size, char* searchBookTitle)
{
    for (int i = 0; i < size; i++)
    {
        // Функция strcmp() сравнивает две строки и, если они совпадают, возвращает ноль
        // Здесь и далее используем для формирования ответа на запрос пользователя 
        // (сначала для поиска по названию, затем - по автору и жанру, соответственно)
        if (strcmp(searchBookTitle, books[i].title) == 0)
        {
            initBooks(books[i]);
            cout << endl;
        }
    }
}

// Добавил поиск по жанру, чтобы жанр хоть какую-то роль в задаче играл
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
    // При замене информации о книге при наличии пробела возникает ошибка 
    // (не считывает второе и последующие слова и делает Exit).
    // Пытался сделать через string и getline, но то там, то здесь при пересборке возникали ошибки
    // string newVal; - строка и под нее динам.массив сделать пытался
    // getline (cin, newVal); - в кейсы
    // В какой-то момент начало получаться, но не сохранил и забыл :(
    cout << "Выберите номер книги, которую необходимо отредактировать: " << endl;
    cin >> bookChoice;
    if (bookChoice > size || bookChoice < 1)
    {
        cout << "Книга с таким номером в библиотеке отсутствует!" << endl;
        return 1;
    }
    bookChoice--;
    cout << endl;
    cout << "Что вы хотите отредактировать: " << endl << endl;
    cout << "1 - Название книги" << endl;
    cout << "2 - Автора книги" << endl;
    cout << "3 - Издателя книги" << endl;
    cout << "4 - Жанр книги" << endl << endl;
    cin >> editBookVar;
    cout << endl;

    switch (editBookVar)
    {
    case Title:
        cout << "Введите верное название книги: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].title, newVal);
        cout << endl;
        break;
    case Author:
        cout << "Введите верного автора книги: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].author, newVal);
        cout << endl;
        break;
    case Publisher:
        cout << "Введите верного издателя книги: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].publisher, newVal);
        cout << endl;
        break;
    case Genre:
        cout << "Введите верный жанр: ";
        cin >> newVal;
        strcpy_s(books[bookChoice].genre, newVal);
        cout << endl;
        break;
    }
    cout << "Успешно исправлено!" << endl << endl;

    delete[] newVal;
}

void deleteBooksDin(Library* books)
{
    delete[]books;
}