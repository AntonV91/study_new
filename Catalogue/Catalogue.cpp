// Создайте приложение «Каталог текстов песен».
// Приложение должно иметь следующие возможности :
// ❖ Добавление текста песни :
// ➢ Текст песни может быть :
// ▪ введен с клавиатуры;
// ▪ загружен из файла.
// ➢ Для каждой песни нужно указывать
// ▪ название песни, автора текста и год создания песни(если он известен).
// ❖ Удаление текста песни.
// ❖ Изменение текста песни.
// ❖ Отображение текста песни на экран.
// ❖ Сохранение текста песни в файл.
// ❖ Поиск и отображение всех песен одного автора.
// ❖ Поиск и отображение всех песен, содержащих слово, указанное пользователем.

#pragma once // Директива препроцессора для защиты от повторного включения

#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <string> // для работы со string (getline)
#include <vector> // для работы с вектором
#include <windows.h> // для работы функции SetConsole

using namespace std;

// Перечисляемый тип для именования кейсов в меню
enum userChoice
{
    Exit = 0,
    AddTrack = 1,
    DeleteLyrics = 2,
    EditLyrics = 3,
    ShowTracks = 4,
    SearchByAuthor = 5,
    SearchByWord = 6,
    SaveList = 7,
};

// Структура "Трек" из 4 элементов: название, автор, год, текст
struct Track
{
    string title;
    string author;
    int year;
    string lyrics;
};

// Прототипы функций для работы с каталогом
void showCover(string& filename); // Для вывода обложки на экран
void addTrack(vector<Track>& catalogue); // Для добавления трека
void getInput(Track& track); // Для ввода названия, исполнителя и года
void showTrack(const Track& track); // Для показа трека
void showCatalogue(const vector<Track>& catalogue); // Для показа каталога
void searchByAuthor(const vector<Track>& catalogue); // Для поиска треков по автору
void searchByWord(const vector<Track>& catalogue); // Для поиска треков по слову
void deleteTrack(vector<Track>& catalogue); // Для удаления трека
void editTrack(vector<Track>& catalogue); // Для редактирования трека
void saveCatalogueToFile(const vector<Track>& catalogue, const string& trackList); // Для сохранения списка треков в файл

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Track> catalogue; // Создаем пустой вектор структур

    // 1-й способ: Добавляем трек простым вводом значений структуры ("\n" - перенос строки)
    catalogue.push_back({ "Her Majesty", "The Beatles", 1969, "Her Majesty is a pretty nice girl\nBut she doesn't have a lot to say\nHer Majesty is a pretty nice girl\nBut she changes from day to day\nI wanna tell her that I love her a lot\nBut I gotta get a belly full of wine\nHer Majesty is a pretty nice girl\nSomeday I'm gonna make her mine, oh yeah\nSomeday I'm gonna make her mine\n" });

    // 2-й способ: Добавляем трек посредством передачи в lyrics пути к файлу с текстом
    Track track;
    track.title = "Босоногий мальчик";
    track.author = "Леонид Агутин";
    track.year = 1994;
    string path = "Босоногий мальчик.txt";
    //string path = "C:\\Users\\Anton\\source\\repos\\Catalogue\\Босоногий мальчик.txt";
    ifstream file(path);
    if (file.is_open())
    {
        string lyrics; // string для чтения текста из файла
        getline(file, lyrics, '\0'); // читаем текст из файла целиком
        track.lyrics = lyrics; // приравниваем lyrics из структуры к string, считанному из файла
        file.close(); // закрываем файл
        catalogue.push_back(track);
    }

    int choice;
    string filename = "Обложка.txt"; // Путь к файлу с обложкой
    showCover(filename);
    do
    {
        cout << endl << "1 - Добавить песню" << endl;
        cout << "2 - Удалить песню" << endl;
        cout << "3 - Изменить текст песни" << endl;
        cout << "4 - Показать песни" << endl;
        cout << "5 - Найти песни по автору" << endl;
        cout << "6 - Найти песни по содержащемуся в тексте слову" << endl;
        cout << "7 - Сохранить список треков в файл" << endl;
        cout << "0 - Выход из программы" << endl << endl;
        cout << "Выберите нужный вариант: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case AddTrack:
            system("cls");
            addTrack(catalogue);
            break;
        case DeleteLyrics:
            system("cls");
            deleteTrack(catalogue);
            break;
        case EditLyrics:
            system("cls");
            editTrack(catalogue);
            break;
        case ShowTracks:
            system("cls");
            showCatalogue(catalogue);
            break;
        case SearchByAuthor:
            system("cls");
            searchByAuthor(catalogue);
            break;
        case SearchByWord:
            system("cls");
            searchByWord(catalogue);
            break;
        case SaveList:
            system("cls");
            // В вызове функции вторым аргументом указывем имя файла, в который сохраняем список
            saveCatalogueToFile(catalogue, "Все треки.txt");
            break;
        case Exit:
            cout << "\nДо встречи в каталоге!" << endl;
            exit(0);
            break;
        default:
            cout << "Вы ввели неверное число! Попробуйте еще раз!" << endl;
            break;
        }
        cout << endl;
    } while (choice != Exit);

    system("pause");
    return 0;
}

void showCover(string& filename) // Формируем обложку каталога
{
    ifstream file(filename); // открываем файл для чтения

    // Проверяем, открылся ли файл
    if (!file.is_open())
    {
        cout << "Ошибка: не удалось открыть файл! " << filename << endl;
        return;
    }

    string line; // читаем содержимое файла построчно и выводим на экран
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close(); // закрываем файл
}

void getInput(Track& track) // Функция для ввода названия, исполнителя и года
{
    cout << "\nВведите название песни: ";
    getline(cin, track.title);
    cout << "Введите исполнителя: ";
    getline(cin, track.author);
    cout << "Введите год релиза (0, если неизвестен): ";
    cin >> track.year;
    cin.ignore();
}

void addTrack(vector<Track>& catalogue) // Функция для добавления трека
{
    Track track;
    // "Вилка" пользовательского ввода для выбора заполнения текста (ввод или загрузка из файла)
    cout << "Выберите вариант добавления текста: " << endl << endl;
    cout << "1 - Ввести текст с клавиатуры" << endl;
    cout << "2 - Добавить текст из файла" << endl;
    cout << "\nВыберите вариант (1 или 2): ";
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        getInput(track);
        cout << "\nВведите текст песни (заканчивайте пустой строкой): " << endl;
        string inputLine; // string для вводимого текста песни

        // Цикл while считывает ввод пользователя построчно до тех пор,
        // пока не введена пустая строка
        while (getline(cin, inputLine) && !inputLine.empty())
        {
            // Конкатенация (при помощи оператора +=) новой строки со строкой lyrics
            // Символ '\n' добавляется, чтобы в результирующей строке все считывалось построчно 
            track.lyrics += inputLine + '\n';
        }
        cout << "Трек: " << track.author << " - " << track.title << " (" << track.year << ") " << "добавлен в каталог!" << endl << endl;

        // Опция сохранения введенного текста в файл
        cout << "Хотите сохранить текст песни в файл? (Y/N): ";
        char saveChoice;
        cin >> saveChoice;
        cin.ignore();
        if (saveChoice == 'y' || saveChoice == 'Y')
        {
            cout << "Введите имя файла (в формате 'имя файла'.txt): ";
            string filename; // string для вводимого имени файла с текстом
            getline(cin, filename);
            ofstream file(filename); // создаем файл для сохранения текста
            file << track.lyrics; // помещаем текст в файл
            file.close(); // закрываем файл после записи
            cout << "\nТекст песни: " << track.author << " - " << track.title << " (" << track.year << ") " << "успешно сохранен в файл " << filename << endl << endl;
        }
    }
    break;

    case 2:
    {
        getInput(track);
        string filenameInput;
        cout << "Введите имя файла с текстом (в формате имя файла.txt): ";
        getline(cin, filenameInput);
        ifstream file_input(filenameInput);
        if (!file_input)
        {
            cout << "Ошибка: не удается открыть файл " << filenameInput << "!" << endl;
            return;
        }
        string fileLine;
        while (getline(file_input, fileLine))
        {
            track.lyrics += fileLine + '\n';
        }
        cout << "\nТрек: " << track.author << " - " << track.title << " (" << track.year << ") " << "добавлен в каталог!" << endl << endl;
        file_input.close();
    }
    break;

    default:
        cout << "Ошибка: некорректный выбор!" << endl;
        return;
    }
    catalogue.push_back(track);
}

void deleteTrack(vector<Track>& catalogue) // Удаляем трек (по названию)
{
    cout << "Введите название песни для удаления: ";
    string title;
    getline(cin, title);
    for (int i = 0; i < catalogue.size(); i++)
    {
        if (catalogue[i].title == title)
        {
            // Удаляем элемент вектора по указанному индексу i
            catalogue.erase(catalogue.begin() + i);
            cout << "Песня удалена!" << endl;
            return;
        }
    }
    cout << "Ошибка: файл не найден!";
}

void editTrack(vector<Track>& catalogue) // Редактируем трек (по названию)
{
    cout << "Введите название песни, в которой необходимо изменить текст: ";
    string title;
    getline(cin, title);
    for (int i = 0; i < catalogue.size(); i++)
    {
        if (catalogue[i].title == title)
        {
            cout << "Введите новый текст песни: " << endl;
            string line;
            catalogue[i].lyrics = ""; // существующий текст песни удаляется из поля lyrics

            // Здесь пользователем вводится новый текст
            while (getline(cin, line) && !line.empty())
            {
                catalogue[i].lyrics += line + '\n';
            }
            cout << "Текст  изменен!" << endl;
            return;
        }
    }
    cout << "Ошибка: песня не найдена!" << endl;
}

void showTrack(const Track& track) // Функция для показа трека
{
    cout << endl;
    cout << track.author << " - " << track.title << " (" << track.year << "):" << endl << endl;
    cout << track.lyrics << endl;
}

void showCatalogue(const vector<Track>& catalogue) // Функция для показа всех треков из каталога
{
    if (catalogue.empty()) // при отсутствии треков, программа оповестит об этом пользователя
    {
        cout << "Каталог пуст!" << endl;
        return;
    }
    // auto позволяет автоматически определить тип переменной 
    for (const auto& track : catalogue)
    {
        cout << track.author << " - " << track.title << " (" << track.year << "):" << endl << endl;
        cout << track.lyrics << endl;
        cout << endl;
    }
}

void searchByAuthor(const vector<Track>& catalogue) // Поиск песен по автору
{
    string author; // string для автора и поиска по нему
    cout << "Введите исполнителя: ";
    getline(cin, author);
    bool found = false; // флаг, показывающий найдены ли песни автора
    for (const Track& track : catalogue)
    {
        if (track.author == author) // если введенный автор совпадает с автором из каталога
        {
            showTrack(track); // вызываем функцию для вывода информации о найденной песне
            found = true;
        }
    }
    if (!found) // если песни автора не найдены
    {
        cout << "Треки автора " << author << " не найдены!" << endl;
    }
    cout << endl;
}

void searchByWord(const vector<Track>& catalogue) // Поиск песен по слову
{
    string word; // string для введенного слова и поиска по нему
    cout << "Введите слово: ";
    getline(cin, word);
    bool found = false; // флаг, показывающий найдены ли песни с введенным словом
    for (const Track& track : catalogue)
    {
        // Метод find возвращает индекс первого вхождения подстроки word в строке lyrics
        // Если подстрока не найдена, метод возвращает константу (string::npos)
        if (track.lyrics.find(word) != string::npos)
        {
            showTrack(track); // вызываем функцию для вывода информации о найденной песне
            found = true;
        }
    }
    // Переместили блок кода с проверкой на found за пределы цикла for, 
    // чтобы проверка выполнялась после того, как все элементы в catalogue будут пройдены
    if (!found) // если слово не найдено
    {
        cout << "\nТреки со словом '" << word << "' не найдены!" << endl;
    }
    cout << endl;
}

// Сохраняем каталог в текстовый файл
void saveCatalogueToFile(const vector<Track>& catalogue, const string& trackList)
{
    ofstream outputFile(trackList, ios::app); // добавляем флаг ios::app, чтобы дозаписывать в файл 
    // (можем убрать, чтобы не дублировать при перезаписи, и каждый раз записывать "с нуля")

    if (!outputFile.is_open()) // Проверяем, удалось ли открыть файл для записи
    {
        cout << "Ошибка: невозможно открыть файл для записи!" << endl;
        return;
    }

    for (const auto& track : catalogue)
    {
        outputFile << track.author << " - " << track.title << " (" << track.year << "):" << endl << endl;
        outputFile << track.lyrics << endl;
        outputFile << endl;
    }
    cout << "Песни сохранены в файл 'Все треки.txt'!" << endl;
    outputFile.close();
}