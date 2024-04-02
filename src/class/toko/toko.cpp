#include <algorithm>
#include <iostream>
#include <map>
#include "toko.hpp"

using namespace std;

map<Item*, int> listItemToko;
map<Item*, int>::iterator it;

void Toko::addItems(Item* item) {
    if(listItemToko.find(item) != listItemToko.end()) {
        listItemToko[item]++;
    } else {
        listItemToko[item] = 1;
    }
}

void Toko::removeItems(Item* item) {
    auto it = listItemToko.find(item);
    if (it != listItemToko.end()) {
        if(it->second > 1) {
            it->second--;
        } else {
            listItemToko.erase(it);
        }
    }
}

Item* Toko::getItemAt(int index) {
    if(index >= 0 && index < listItemToko.size()) {
        auto it = listItemToko.begin();
        advance(it, index);
        return it->first;
    }
    return nullptr;
}

void Toko::displayToko(){
    int counter = 1;
    for(auto it = listItemToko.begin(); it != listItemToko.end(); ++it) {
        cout << counter << ". " << it->first->getNama() << " - " << it->first->getHarga() << " (" << it->second << ")" << endl;
        counter++;
    }
}