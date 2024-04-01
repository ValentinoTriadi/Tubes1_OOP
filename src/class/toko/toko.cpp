#include <algorithm>
#include <iostream>
#include "toko.hpp"

using namespace std;

Toko::Toko() {
    // Constructor implementation
}

Toko::~Toko() {
    // Destructor implementation
    for(auto item : listItemToko) {
        delete item;
    }
    listItemToko.clear();
}


void Toko::addItems(Item* item) {
    listItemToko.push_back(item);
}

void Toko::removeItems(Item* item) {
    auto it = find(listItemToko.begin(), listItemToko.end(), item);
    if (it != listItemToko.end()) {
        delete *it;
        listItemToko.erase(it);
    }
}

void Toko::displayToko(){
    // Display implementation
}