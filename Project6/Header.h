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

