// �������� ���������� "���������� �����".
// ���������� ������� ������ (���, ��������, ������� � ���.��������, ���.���������� � ��������) 
// ������ ���������������� ������. ��������� ����� �����������-�������, ���������-�������, 
// ��������������, inline-��������� - �������, ����������� ��������������, ���������� ����������.
// ����������� ���������� �������� ����������� ������ ��� ���. 
// ������������ ������������ ����������� ��������� ����� ���������, ������� ���������, 
// ������ ��������� �� ���, ���������� ���� ���������, ��������� � ���� � ��������� �� �����.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Contact // ������� ����� �������
{
private:
    string fullName; // ��������� �� ����������� ���������� ������ ��� �������� ��� ��������
    string homePhone; // ����� ��������� ��������
    string workPhone; // ����� �������� ��������
    string mobilePhone; // ����� ���������� ��������
    string additionalInfo; // �������������� ���������� � ��������

public:
    // �����������, ����������� ���, ������ ��������� � �������������� ����������
    Contact(string name, string home, string work, string mobile, string info) :
        fullName(string(name)), homePhone(home), workPhone(work),
        mobilePhone(mobile), additionalInfo(info) {}

    // ����������� �����������, ��������� ����� �������� other
    Contact(const Contact& other) :
        fullName(string(other.fullName)), homePhone(other.homePhone),
        workPhone(other.workPhone), mobilePhone(other.mobilePhone),
        additionalInfo(other.additionalInfo) {}

    // �������� ������������
    Contact& operator=(const Contact& other)
    {
        if (this != &other) // �������� �� ������������ ������� ������ ����
        {
            // ����������� �������� �����
            fullName = other.fullName;
            homePhone = other.homePhone;
            workPhone = other.workPhone;
            mobilePhone = other.mobilePhone;
            additionalInfo = other.additionalInfo;
        }
        return *this;
    }

    // ���������� ����������� ������, ���������� ��� ��� ��������
    ~Contact(){};

    // inline �������-����� ��� ������� � �����

    // �������:
    const string& getName() const { return fullName; } // �������� �������� ��� ��������
    // �������� �������� ��������������� ������� ��������� (���, ��� � ���)
    const string& getHomePhone() const { return homePhone; }
    const string& getWorkPhone() const { return workPhone; }
    const string& getMobilePhone() const { return mobilePhone; }
    // �������� ���. ���������� � ��������
    const string& getAdditionalInfo() const { return additionalInfo; }

    // �������:
    // ������������� �������� ����� ������� (�� ��� �� ���. ����������)
    void setName(const string& name) { fullName = name; }
    void setHomePhone(const string& phone) { homePhone = phone; }
    void setWorkPhone(const string& phone) { workPhone = phone; }
    void setMobilePhone(const string& phone) { mobilePhone = phone; }
    void setAdditionalInfo(const string& info) { additionalInfo = info; }
};

class PhoneBook // ������� ����� ���������� �����
{
private:
    vector<Contact*> contacts; // ������ ���������
    string enterName; // ��������� ���������� ������ ��� �������� ����� ��������
public:
    // ���������� ������ �������� � �����
    void addContact()
    {
        string name, home, work, mobile, info;
        cout << "������� ��� ��������: ";
        getline(cin, name);
        cout << "������� ���.������� ��������: ";
        getline(cin, home);
        cout << "������� ���.������� ��������: ";
        getline(cin, work);
        cout << "������� ���.������� ��������: ";
        getline(cin, mobile);
        cout << "������� ���.���������� �� ��������: ";
        getline(cin, info);
        contacts.push_back(new Contact(name, home, work, mobile, info)); // ��������� � ����� ������
    }

    void removeContact()
    {
        int number;
        cout << "������� ���������� ����� ��������, ������� ����� �������: ";
        cin >> number;
        cin.ignore(); // ���������� ������ �������� ������

        int index = number - 1; // ��������� ��������������� ������ � �������

        if (index < 0 || index >= contacts.size()) // ���������, ��� ������ ��������� � ���������� ��������
        {
            cout << "�������� ����� ��������!" << endl;
            return;
        }
        delete contacts[index]; // ����������� ������, ���������� ��� ������ �� ���������� �������
        contacts.erase(contacts.begin() + index); // ������� ��������� �� ������� �� ���������� �������
    }

    // ��������� ���������� ��������� � �����
    int getCount() const
    {
        return contacts.size(); // ���������� ������ ������� (= ���-�� ���������)
    }

    // ��������� �������� �� �������
    const Contact& getContact(int index) const
    {
        return *contacts[index]; // ���������� ������ �� ������ �� ���������� �������
    }

    void enterContactName() // ��������� ����� ������ ��� ���������� ���������� enterName
    {
        cout << "������� ��� ��������, �������� ����� �����: ";
        getline(cin, enterName);
    }

    vector<int> searchContacts() const
    {
        // ������ ������, � ������� ����� ����������� ������� ������ ���������
        vector<int> result;
        for (int i = 0; i < contacts.size(); i++) // �������� ������ �� ���� ���������
        {
            const Contact& contact = *contacts[i]; // ������ ������ �� ������ �� �������� �������
            if (contact.getName() == enterName) // ���� ��� �������� ����� ����������� �� ������
            {
                result.push_back(i); // ��������� ������ �������� �������� � ������ result
            }
        }

        if (result.empty()) // ���� ������ �� �������
        {
            cout << "������� �� ������!" << endl;
        }
        else // ����� ������� ���������� � ��������� ���������
        {
            cout << "\n������� ��������� ��������:\n\n";
            for (int i : result)
            {
                const Contact& contact = *contacts[i];
                cout << contact.getName() << endl;
                cout << "�������� �������: " << contact.getHomePhone() << endl;
                cout << "������� �������: " << contact.getWorkPhone() << endl;
                cout << "��������� �������: " << contact.getMobilePhone() << endl;
                cout << "���. ����������: " << contact.getAdditionalInfo() << endl;
                cout << endl;
            }
        }
        return result;
    }

    // ������� ��� ������ ���� ���������
    void showAllContacts() const
    {
        if (contacts.empty()) // ���� ��������� � ����� ���
        {
            cout << "� ���������� ����� ����������� ��������!" << endl;
            return;
        }

        for (int i = 0; i < contacts.size(); i++) // ����� �� ����� � ��������� ������� �� �����
        {
            const Contact& contact = *contacts[i];
            cout << "������� �" << i + 1 << endl;
            cout << contact.getName() << endl;
            cout << "�������� �������: " << contact.getHomePhone() << endl;
            cout << "������� �������: " << contact.getWorkPhone() << endl;
            cout << "��������� �������: " << contact.getMobilePhone() << endl;
            cout << "���. ����������: " << contact.getAdditionalInfo() << endl;
            cout << endl;
        }
    }

    // ������� ��� ���������� ��������� � ����
    void saveContacts(const PhoneBook& book, const string& filename)
    {
        ofstream out(filename);//, ios::app);;
        if (!out) // ���� ���� �� ��������
        {
            cout << "�� ������� ������� ���� " << filename << " ��� ������!" << endl;
            return;
        }

        //�������� �� ���� ���������, �������� �� ������ � ���������� � ���� (���������)
        for (int i = 0; i < book.getCount(); i++)
        {
            const Contact& contact = book.getContact(i);
            out << contact.getName() << '\n';
            out << contact.getHomePhone() << '\n';
            out << contact.getWorkPhone() << '\n';
            out << contact.getMobilePhone() << '\n';
            out << contact.getAdditionalInfo() << '\n';
            out << '\n'; // ���������� ������ ������ ����� ����������
        }
        out.close();
        cout << "�������� ��������� � ���� ��������.txt";
    }

    void loadContacts(const string& filename)
    {
        ifstream in(filename);
        if (!in) // ���� ���� �� ��������
        {
            cout << "�� ������� ������� ���� " << filename << " ��� ������!" << endl;
            return;
        }

        // ������� ��������� ������ ��� ���������, ����� �� ��������������
        // �������� ������ �� ��� ���, ���� �� ����� ��������� ��� ��������
        vector<Contact*> tempContacts;

        // ��������� ������ �� ����� ���������, ������� ������ �������
        string name, home, work, mobile, info;

        // ����� ������ ������ ������ (�����) �����������, �������� �� ��� ������
        // ���� ��, �� �������� continue ���������� ������� �������� �����, 
        // � ������ ������������ �� ��������� ������
        while (getline(in, name))
        {
            if (name.empty()) // ���� ������ ������, ���������� �� (��������, ����� �������� ������ ������)
            {
                continue;
            }

            getline(in, home);
            getline(in, work);
            getline(in, mobile);
            getline(in, info);

            // ������� ��������� ������ ��������
            Contact* tempContact = new Contact(name, home, work, mobile, info);
            tempContacts.push_back(tempContact); // ��������� ��� �� ��������� ������
        }

        if (tempContacts.empty()) // ���� ���� ������, �� ��������� ���� � ������� �� �������
        {
            in.close();
            return;
        }

        // ����������� ������, ���������� ��� ������ �������� � �������� �������
        for (auto& contact : contacts)
        {
            delete contact;
        }

        // �������� ������ ������ �����, ����������� �� �����
        contacts = tempContacts;
        in.close();
        cout << "�������� ��������� �� ����� ��������.txt";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook book; // ������� ������ book ������ PhoneBook ��� ������ �������
    int choice;
    cout << "���������� ���������� ���� ���������:" << endl;
    do
    {
        cout << endl << "1 - �������� ��������" << endl;
        cout << "2 - ������� ��������" << endl;
        cout << "3 - ����� �������� �� ���" << endl;
        cout << "4 - �������� ���� ���������" << endl;
        cout << "5 - ��������� ���������� � ����" << endl;
        cout << "6 - ��������� ���������� �� �����" << endl;
        cout << "0 - ����� �� ���������" << endl << endl;
        cout << "�������� ������ �������: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            system("cls");
            book.addContact();
            break;
        case 2:
            system("cls");
            book.showAllContacts();
            book.removeContact();
            break;
        case 3:
            system("cls");
            book.enterContactName();
            book.searchContacts();
            break;
        case 4:
            system("cls");
            book.showAllContacts();
            break;
        case 5:
            system("cls");
            book.saveContacts(book, "��������.txt");
            break;
        case 6:
            system("cls");
            book.loadContacts("��������.txt");
            break;
        case 0:
            cout << "\n�� ������� � �����������!" << endl;
            exit(0);
            break;
        default:
            cout << "�� ����� �������� �����! ���������� ��� ���!" << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);

    system("pause");
    return 0;
}