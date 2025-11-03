//COMSC-210 | Lab 27 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

//prototype functions to display menu and modify the list as determined by the user
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

    //while loop that continuously displays the menu and requests a user input until the sentry value is inputted
    while (true){
        //displays the current population of the village, as well as their friendship levels, species and catchphrases
        cout << "\nVillagers and their friendship levels, species and catchphrases:" << endl;
        for (map<string, villagerDetails>::iterator it = villagers.begin(); it != villagers.end(); ++it) {
            cout << it->first << ": ";
            cout << "[" << get<0>(it->second) << ", ";
            cout << get<1>(it->second) << ", ";
            cout << get<2>(it->second) << "]\n";
        }
        cout << endl;

        //displays the options for the user to modify the current village population
        int choice = menu();

        if (choice == 1)
            addVillager(villagers);
        else if (choice == 2)
            deleteVillager(villagers);
        else if (choice == 3)
            incFriendship(villagers);
        else if (choice == 4)
            decFriendship(villagers);
        else if (choice == 5)
            search(villagers);
        else if (choice == 6) 
            break;
        //if the input does not fall within our bounds, this message will be outputted
        else
            cout << "Invalid input, please try again.\n";
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}

//function that displays the options for the user in which they can interact with the village population
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

    //returns the number corresponding to the user's input
    return choice;
}

//void function that dins and displays a specific villager's information
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

//void function that gathers data from the user's input and adds it to the map once all data has been gathered
void addVillager(map<string, tuple<int, string, string>>& v) {
    string name;
    cout << "Villager name: ";
    cin >> name;
    cin.ignore();

    int fl;
    cout << "Friendship level: ";
    cin >> fl;
    cin.ignore();

    string species;
    cout << "Species: ";
    cin >> species;
    cin.ignore();

    string catchphrase;
    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    cout << name << " added.\n";
    v.insert({name, {fl, species, catchphrase}});
}

//void function that deletes a specific villager found from user input and if they are not found, returns a villager not found message
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

//void function that increases the friendship level of a villager as long as their friendship level is already within our bounds and will not exceed it
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

//void function that decreases the friendship level of a villager as long as their friendship level is already within our bounds and will not go below it
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