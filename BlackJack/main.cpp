#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "GenericPlayer.h"
#include "Game.h"
#include "Hand.h"
#include "HouseKeeper.h"
#include <windows.h>

//ОПНРНРХОШ ТСМЙЖХИ
ostream& operator <<(ostream& os, const Card& aCard);
ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t\tдНАПН ОНФЮКНБЮРЭ Б ЙЮГХМН!\n";
    cout << "\t\t\tхЦПЮЕЛ Б аКЩЙдФЩЙ21 !\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "яЙНКЭЙН ВЕКНБЕЙ АСДЕР ХЦПЮРЭ? (1-7): \n";
        cin >> numPlayers;
    }

    vector<string>names;
    string name;

    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "бБЕДХРЕ ХЛЪ ХЦПНЙЮ: \n";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    //нЯМНБМНИ ЖХЙК ХЦПШ

    Game aGame(names);

    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\n уНРХРЕ ЯШЦПЮРЭ ЕЫЕ? (Y/N): \n";
        cin >> again;
    }

    return 0;

}

// опх педюйрхпнбюмхх опнцпюллш бяе онкнлюкняэ: опнцпюллю йнлохкхпсеряъ, мн с йпсоэе мю псйюу
// я яюлнцн мювюкю мер йюпр. йнцдю опнцпюллю ашкю б бхде 1 уедеп, 1 MAIN б CPP бя╗ пюанрюкн - 
// нмн кефхр б оюойе BLACKJACK опхлхрхбмши
// б хмрепмере мюохяюмн, врн бяе йкюяяш фекюрекэмн нрдекърэ дпсц нр дпсцю, онрнлс ядекюк мюяйнпн рюй
// онопнасч онгфе хяопюбхрэ х нркюдхрэ (б щрнр пюг бпелемх мю пюанрс онврх ме ашкн)

