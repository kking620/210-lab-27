//COMSC-210 | Lab 27 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // declarations
    using villagerDetails = tuple<int, string, string>;
    map<string, villagerDetails> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {5, "Human", "Howdy partner!"};
    villagers["Raymond"] = {3, "Werewolf", "I'm not a wolf, I promise."};
    villagers.insert({"Marshal", {10, "Human", "This place is so cool!"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagers) {
        cout << pair.first << ": ";
        cout << "[" << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << "]\n";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, villagerDetails>::iterator it = villagers.begin(); it != villagers.end(); ++it) {
        cout << it->first << ": ";
        cout << "[" << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << "]\n";
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        cout << "[" << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << "]\n";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
