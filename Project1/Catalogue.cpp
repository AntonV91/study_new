#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Track
{
    string title;
    string author;
    int year;
    string lyrics;
};

vector<Track> catalogue;

void displaySong(int index)
{
    cout << "Title: " << catalogue[index].title << endl;
    cout << "Author: " << catalogue[index].author << endl;
    cout << "Year: " << catalogue[index].year << endl;
    cout << "Lyrics: " << endl << catalogue[index].lyrics << endl;
}

void displayAllSongs()
{
    for (int i = 0; i < catalogue.size(); i++)
    {
        cout << "Song " << i + 1 << endl;
        displaySong(i);
        cout << endl;
    }
}

int main()
{
    // Example usage
    Track song1 = { "Bohemian Rhapsody", "Queen", 1975 };
    Track song2 = { "Stairway to Heaven", "Led Zeppelin", 1971 };
    catalogue.push_back(song1);
    catalogue.push_back(song2);

    displaySong(0);
    cout << endl;
    displayAllSongs();

    return 0;
}