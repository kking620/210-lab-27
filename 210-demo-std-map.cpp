//COMSC-210 | Lab 27 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

int menu();
void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);
void incFriendship(map<string, tuple<int, string, string>>&);
void decFriendship(map<string, tuple<int, string, string>>&);
void search(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    using villagerDetails = tuple<int, string, string>;
    map<string, villagerDetails> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {5, "Human", "Howdy partner!"};
    villagers["Raymond"] = {3, "Werewolf", "I'm not a wolf, I promise."};
    villagers.insert({"Marshal", {10, "Human", "This place is so cool!"}});

    while (true){
        // access the map using iterators
        cout << "\nVillagers and their friendship levels, species and catchphrases:" << endl;
        for (map<string, villagerDetails>::iterator it = villagers.begin(); it != villagers.end(); ++it) {
            cout << it->first << ": ";
            cout << "[" << get<0>(it->second) << ", ";
            cout << get<1>(it->second) << ", ";
            cout << get<2>(it->second) << "]\n";
        }

        cout << endl;

        int choice = menu();

        if (choice == 1)
            incFriendship(villagers);
        else if (choice == 2)
            decFriendship(villagers);
        else if (choice == 3)
            incFriendship(villagers);
        else if (choice == 4)
            decFriendship(villagers);
        else if (choice == 5)
            search(villagers);
        else if (choice == 6) 
            break;
        else
            cout << "Invalid input, please try again.\n";
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}

int menu () {
    int choice;
    
    cout << "What would you like to do?\n";
    cout << "1. Add Villager\n";
    cout << "2. Delete Villager\n";
    cout << "3. Increase Friendship\n";
    cout << "4. Decrease Friendship\n";
    cout << "5. Search for Villager\n";
    cout << "6. Exit\n";
    cin >> choice;

    return choice;
}

void search(map<string, tuple<int, string, string>> &v) {
    // search for an element using .find() to avoid errors
    string searchKey = "";
    cout << "Who would you like to find? ";
    cin >> searchKey;
    auto it = v.find(searchKey);
    if (it != v.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s friendship level, species, and catchphrase: \n";
        cout << "Friendship level: " << get<0>(it->second) << endl;
        cout << "Species: " << get<1>(it->second) << endl;
        cout << "Catchphrase: " << get<2>(it->second) << endl;
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;
}

void addVillager(map<string, tuple<int, string, string>>& v) {
    string name;
    cout << "Villager name: ";
    cin >> name;
    cout << endl;
    
    int fl;
    cout << "Friendship level: ";
    cin >> fl;
    cout << endl;

    string species;
    cout << "Species: ";
    cin >> species;
    cout << endl;

    string catchphrase;
    cout << "Catchphrase: ";
    getline(cin, catchphrase);
    cin.ignore();
    cout << endl;

    v.insert({name, {fl, species, catchphrase}});

    cout << name << " added.\n";
}

void deleteVillager(map<string, tuple<int, string, string>>& v) {
    string name;

    cout << "Which villager would you like to remove?\n";
    cin >> name;
    
    auto it = v.find(name);
    if (it != v.end()) {
        v.erase(name);
    }
    else    
        cout << endl << name << " not found." << endl;
}

void incFriendship(map<string, tuple<int, string, string>> &v) {
    string searchKey = "";
    cout << "Who's friendship level do you wish to increase? ";
    cin >> searchKey;

    auto it = v.find(searchKey);
    if (it != v.end()) {
         if (get<0>(it->second) >= 0 && get<0>(it->second) <= 10)
            get<0>(it->second)++;
        else if (get<0>(it->second) > 10)
            cout << "The villager can't get any more friendly.\n";
    }
    else    
        cout << endl << searchKey << " not found." << endl;
}

void decFriendship(map<string, tuple<int, string, string>> &v) {
    string searchKey = "";
    cout << "Who's friendship level do you wish to decrease? ";
    cin >> searchKey;

    auto it = v.find(searchKey);
    if (it != v.end()) {
        if (get<0>(it->second) >= 0 && get<0>(it->second) <= 10)
            get<0>(it->second)--;
        else if (get<0>(it->second) < 0)
            cout << "The villager can't get any less friendly.\n";
    }
    else    
        cout << endl << searchKey << " not found." << endl;
}
