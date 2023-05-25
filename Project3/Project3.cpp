// Игра 21.
//Раздать игрокам и дилеру две начальные карты
//Спрятать первую карту дилера
//Отобразить руки игроков и дилера
//Раздать игрокам дополнительные карты
//Показать первую карту дилера
//Раздать дополнительные карты дилеру
//Если у дилера перебор
//Все игроки без перебора выигрывают
//Иначе
//Для каждого игрока
//Если у игрока нет перебора
//Если сумма очков игрока больше, чем у дилера
//Игрок побеждает
//Иначе если сумма очков игрока меньше, чем у дилера
//Игрок проигрывает
//Иначе
//Объявляется ничья
//Удалить карты всех игроков


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
    enum rank {
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
    if (mIsFaceUp) //если карта перевернута, читаем значение.
    {
        value = mRank;
        if (value > 10)
        {
            value = 10;
        }
    }
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
    mCards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

inline void Hand::add(Card* pCard)
{
    mCards.push_back(pCard);
}

void Hand::clear()
{
    vector<Card*>::iterator iter = mCards.begin();
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        delete* iter;
        *iter = nullptr;
    }
    //очищаем вектор указателей
    mCards.clear();
}

int Hand::getTotal() const
{
    //если карт в руке нет. возвращает значение О 
    if (mCards.empty())
    {
        return 0;
    }

    //если первая карта имеет значение О. 
    //то она лежит рубашкой вверх: 
    if (mCards[0]->getValue() == 0)
    {
        return 0;
    }

    //находит сумму очков всех карт. каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    //определяет. держит ли рука туз 
    bool containsAce = false;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    //если рука держит туз и сумма довольно маленькая. 
    //туз дает 11 очков 
    if (containsAce && total <= 11)
    {
        //добавляем только 10 очков. т.к. тузы уже добавили +1
        total += 10;
    }
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
    return (getTotal() > 21);
}
// Сообщить о Переполнении
void GenericPlayer::bust() const
{
    cout << mName << " Перебор. \n";
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
    mCards.reserve(52);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();
    //создаем стандартную колоду
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(mCards.begin(), mCards.end());
}

void Deck::deal(Hand& aHand) // обратить внимание на ссылку - Рука.
{
    if (!mCards.empty())
    {
        aHand.add(mCards.back());
        mCards.pop_back();
    }
    else
    {
        cout << "Карты закончились. Не могу сдать. ";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)  // обратить внимание на ссылку - ОбобщенныйИгрок.
{
    cout << endl;
    //продолжаем сдавать (если не перебор и готов брать)
    while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting())
    {
        deal(aGenericPlayer);
        cout << aGenericPlayer << endl;
        if (aGenericPlayer.isBusted())
        {
            aGenericPlayer.bust();
        }
    }
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
    cout << mName << ", Вам нужна еще? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << mName << ". Вы выиграли! \n";
}

void Player::lose() const
{
    cout << mName << " Проиграл. \n";
}

void Player::push() const
{
    cout << mName << " Ничья. \n";
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
    return (getTotal() <= 16);
}

// перевернуть карту
void HouseKeeper::flipFirstCard() const
{
    if (!(mCards.empty()))
    {
        mCards[0]->flip();
    }
    else
    {
        cout << "Нет карт для переворота!\n";
    }
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
    //создаем массив игроков
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        mPlayers.push_back(Player(*pName));
    }
    //инициализируем ГСЧ
    srand(static_cast<unsigned int>(time(NULL)));// преобразование time_t
    mDeck.populate();
    mDeck.shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    //Сдать всем по 2 карты
    vector<Player>::iterator pPlayer;

    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            mDeck.deal(*pPlayer);
        }
        mDeck.deal(mHouse);
    }
    //Скрыть первую карту казино
    mHouse.flipFirstCard();

    //показать все карты на руках
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << mHouse << endl;
    // сдать дополнительные карты игрокам
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        mDeck.additionalCards(*pPlayer);
    }

    //перевернуть первую карту Казино
    mHouse.flipFirstCard();
    cout << endl << mHouse;

    //раздать дополнительную карту казино
    mDeck.additionalCards(mHouse);
    if (mHouse.isBusted())
    {
        //проверить на выигрыш
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                pPlayer->win();
            }
        }
    }
    else
    {
        //сравнить карты игроков и казино
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()) && (pPlayer->getTotal() > mHouse.getTotal()))
            {//Если не перебор и больше диллера
                pPlayer->win();
            }
            else if ((pPlayer->isBusted()) || (!(pPlayer->isBusted()) && pPlayer->getTotal() < mHouse.getTotal()))
            {
                pPlayer->lose();
            }
            else
            {
                pPlayer->push(); //ничья
            }

        }
    }
    //очистить карты в руках
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    mHouse.clear();
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
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };
    if (aCard.mIsFaceUp)
    {
        os << RANKS[aCard.mRank] << SUITS[aCard.mSuit];
    }
    else {
        os << "XX";
    }
    return os;
}

ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.mName << " :\t";
    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.mCards.empty())
    {
        for (pCard = aGenericPlayer.mCards.begin();
            pCard != aGenericPlayer.mCards.end();
            ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.getTotal() != 0)
        {
            cout << "(" << aGenericPlayer.getTotal() << ")";
        }
    }
    else
    {
        os << "<пусто>";
    }
    return os;
}
