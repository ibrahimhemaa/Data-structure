#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// sort based on the name
template < class T >
void selection_sort(vector< pair < T, T >> &list, string s)

{
    int i, j, min_indx;
    if (s == "name") {
        for (i = 0; i < list.size() - 1; ++i)
        {
            min_indx = i;
            for (j = i + 1; j < list.size(); ++j)
            {
                if (list[j].second < list[min_indx].second)
                {
                    min_indx = j;
                }
            }
            swap(list[min_indx], list[i]);
        }
    }
    else
    {
        for (i = 0; i < list.size() - 1; ++i)
        {
            min_indx = i;
            for (j = i + 1; j < list.size(); ++j)
            {
                if (list[j].first < list[min_indx].first)
                {
                    min_indx = j;
                }
            }
            swap(list[min_indx], list[i]);
        }
    }
}

template < class T >
void insertion_sort(vector< pair < T, T >> &list)
{
    int i, j;
    T tmp, tmp2;
    for (i = 1; i < list.size(); ++i)
    {
        tmp = list[i].second;
        tmp2 = list[i].first;
        for (j = i - 1; j >= 0 && list[j].second > tmp; --j)
        {
            list[j + 1] = list[j];
        }
        list[j + 1].first = tmp2, list[j + 1].second = tmp;
    }
}

template < class T >
void bubble_sort(vector< pair < T, T >> &list)
{
    for (int i = 0; i < list.size() ; ++i)
    {
        for (int j = 0; j < list.size() - 1; ++j)
        {
            if (list[j].second > list[j + 1].second)
            {
                swap(list[j], list[j + 1]);
            }
        }
    }
}
class PhoneDirctory {
private:
    string phone_number;
    string name;
public:
    PhoneDirctory(); // defaulte constractor
    virtual ~PhoneDirctory();
    // declare vector of pairs to store phone number in
    vector<pair<string, string>> directry;
    // create function to set phone number
    void setNumber(string num);
    // create function to set names
    void setName(string Name);
    // create function to get phone number
    string getNumber();
    // create function to get name
    string getName();
    // create function to add phone number in directry
    void addNumber();
    // create function to search about phone number
    void search_by_number();
    // create function to print the result
    void search_by_name();
    // create function to show the directrly
    void displayAllDirectry();
    // crearte funtion to delete the entry
    void delete_entry();

};

PhoneDirctory::PhoneDirctory() {} // defalte cons
PhoneDirctory ::~PhoneDirctory() {} // destractor

// function to set phone number
void PhoneDirctory::setNumber(string num) {
    phone_number = num;
}

void PhoneDirctory::setName(string Name) {
    name = Name;
}

string PhoneDirctory::getNumber() {
    return phone_number;
}

string PhoneDirctory::getName() {
    return name;
}

void PhoneDirctory::addNumber() {
    string num, name;
    cout << "enter the phone number: "; cin >> num;
    while (num.size() < 11)
    {
        cout << "Incorrect num!\n" << "Please enter the correct one\n";
        cin >> num;
    }
    cin.ignore();
    cout << "enter the name: ";
    getline(cin, name);
    setNumber(num);
    setName(name);
    directry.push_back({ num, name});
    insertion_sort(directry);
    bubble_sort(directry);
    cout << "Added sucssfuly\n";
}
void PhoneDirctory::displayAllDirectry() {
    // in case the list is empty
    if (directry.empty())
    {
        cout << "\nThe list t is empty!\n";
        return;
    }
    cout << "\n \n";
    cout << "Name" << "\t \t" << "phone number" << '\n';
    for (int i = 0; i < directry.size(); ++i)
    {
        cout << directry[i].second << '\t' << directry[i].first << '\n';
    }
}

void PhoneDirctory::search_by_number() {
    selection_sort(directry,"number");
    string number;
    cout << "Enter the number: "; cin >> number;
    int l = 0, r = directry.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (number == directry[mid].first)
        {
            cout << "Name: " << directry[mid].second << ' ' << "Number: " << directry[mid].first << '\n';
            insertion_sort(directry);
            bubble_sort(directry);
            return;
        }
        if (number > directry[mid].first)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "Not found!\n";
    insertion_sort(directry);
    bubble_sort(directry);
}

void PhoneDirctory::search_by_name() {
    cout << "enter the name: ";
    string n; cin >> n; int s = n.size();
    int l = 0, r = directry.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        while (directry[mid].second.substr(0, s) == n)
        {
            cout << "Name: " <<directry[mid].second << " " << "Number: " << directry[mid].first << '\n';
            return;
        }
        if (n < directry[mid].second)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "Not found!\n";
}

void PhoneDirctory::delete_entry() {
    string name;
    cout << "Enter the name\n";
    cin >> name;
    for (int i = 0; i < directry.size(); ++i)
    {
        int s = name.size();
        if (directry[i].second.substr(0, s) == name)
        {
            auto it = directry.begin() + i;
            directry.erase(it);
            cout << "deleted sucssfuly\n";
            return;
        }
    }
    cout << "This number not found!\n";
}

void printMenu()
{
    cout << "1. Add an entry to the directory\n"
         << "2. Look up a phone number\n"
         << "3. Look up by first name\n"
         << "4. Delete an entry from the directory\n"
         << "5. List All entries in phone directory\n"
         << "6. Exit form this program\n";
}
int main()
{
    PhoneDirctory dirc;
    while (true)
    {
        printMenu();
        cout << "\nEnter your choice\n";
        int choice; cin >> choice;
        switch (choice) {
            case 1:
                dirc.addNumber(); cout << '\n';
                break;
            case 2:
                dirc.search_by_number(); cout << '\n';
                break;
            case 3:
                dirc.search_by_name(); cout << '\n';
                break;
            case 4:
                dirc.delete_entry(); cout << '\n';
                break;
            case 5:
                dirc.displayAllDirectry(); cout << '\n';
                break;
            case 6:
                cout << "This program was exited\n";
                return 0;
        }
    }
}
