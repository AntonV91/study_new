#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class Card  //карта
{
public:
    enum rank
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        TEN, JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    Card(rank r = ACE, suit s = CLUBS, bool ifu = true);

    int getValue() const; // собщает значение карты

    void flip(); //переворачивает карту

    friend ostream& operator<<(ostream& os, const Card& aCard);

private:
    rank mRank;
    suit mSuit;
    bool mIsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) :mRank{ r }, mSuit{ s }, mIsFaceUp{ ifu }
{}

int Card::getValue() const
{
    int value = 0;
    return value;
}

void Card::flip()
{
    mIsFaceUp = !(mIsFaceUp);
}

// набор карт
class Hand
{
public:
    Hand();
    virtual ~Hand();
    inline void add(Card* pCard);
    void clear();
    int getTotal() const;
protected:
    vector<Card*> mCards;
};

// реализация методов Hand
Hand::Hand()
{
}

Hand::~Hand()
{
}

inline void Hand::add(Card* pCard)
{
}

void Hand::clear()
{
}

int Hand::getTotal() const
{
    return total;
}

//:Hand обобщенный игрок
class GenericPlayer :public Hand
{
    friend ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();
    // продолжать ли сдавать игроку
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;
protected:
    string mName;
};

GenericPlayer::GenericPlayer(const string& name) :mName{ name }
{}
GenericPlayer::~GenericPlayer()
{}
// переполнение, больше 21
bool GenericPlayer::isBusted() const
{
}
// Сообщить о Переполнении
void GenericPlayer::bust() const
{
}

//:Hand набор + доп функционал 
class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();

    //создаем стандартную колоду 52 карты
    void populate();

    //перемешиваем карты
    void shuffle();

    //сдаем по одной карте в руку
    void deal(Hand& aHand);

    //даем дополнительную карту игроку, если нужно
    void additionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck()
{
}

Deck::~Deck()
{}

void Deck::populate()
{
}

void Deck::shuffle()
{
}

void Deck::deal(Hand& aHand) // обратить внимание на ссылку - Рука.
{
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)  // обратить внимание на ссылку - ОбобщенныйИгрок.
{
}

//class Player; // :GenericPlayer  игрок-человек
class Player : public GenericPlayer//  игрок-человек
{
public:
    Player(const string& name = "");
    virtual ~Player();
    // нужна ли карта еще
    virtual bool isHitting() const;
    void win() const;  // победил
    void lose() const; // проиграл
    void push() const; // сдать
};

Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
}

void Player::win() const
{
}

void Player::lose() const
{
}

void Player::push() const
{
}

//class HouseKeeper; // :GenericPlayer игрок-компьютер
class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const std::string& name = "Казино");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    // перевернуть карту
    virtual void flipFirstCard() const;

};

HouseKeeper::HouseKeeper(const std::string& name) : GenericPlayer(name) {}
HouseKeeper::~HouseKeeper() {};

bool HouseKeeper::isHitting() const
{
}

// перевернуть карту
void HouseKeeper::flipFirstCard() const
{
}

// Основная логика игры
class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //Играем в игру!
    void Play();
private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;
};

Game::Game(const vector<string>& names)
{
}

Game::~Game()
{}

void Game::Play()
{
}

//прототипы функций
ostream& operator <<(ostream& os, const Card& aCard);
ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t\tДобро пожаловать в казино!\n";
    cout << "\t\t\tИграем в БлэкДжэк21 !\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "Сколько человек будет играть? (1-7): \n";
        cin >> numPlayers;
    }

    vector<string>names;
    string name;

    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Введите имя игрока: \n";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    //Основной цикл игры

    Game aGame(names);

    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\n Хотите сыграть еще? (Y/N): \n";
        cin >> again;
    }

    return 0;
}

ostream& operator <<(ostream& os, const Card& aCard)
{
    return os;
}

ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    return os;
}
