#include <algorithm>
#include <iostream>
#include <map>
#include "toko.hpp"
#include "../gameData/gameData.hpp"

using namespace std;

std::map<Item*, int> Toko::listItemToko;
map<Item*, int>::iterator it;

void Toko::addItems(Item* item) {
    // Check if the item is already in the shop dengan pengecekan kode
    for (std::pair<Item *const, int> &it : listItemToko) {
        if (it.first->getCode() == item->getCode()) {
            // Check if the item is infinite
            if (it.second == -1) {
                return;
            }
            it.second++;
            return;
        }
    }

    // If the item is not in the shop, add the item to the shop
    listItemToko[item] = 1;
}

void Toko::initItem(Item *item, int quantity) {
    listItemToko[item] = quantity;
}

void Toko::decreaseItems(Item* item) {
    if(listItemToko.find(item) != listItemToko.end()) {
        if (listItemToko[item] > 0) {
            listItemToko[item]--;
        }
    }
}

bool Toko::isItemAvailable(Item* item) {
    if(listItemToko.find(item) != listItemToko.end()) {
        if (listItemToko[item] > 0 || listItemToko[item] == -1) {
            return true;
        }
    }
    return false;
}

void Toko::addItemsInfinite(Item* item) {
    listItemToko[item] = -1;
}

void Toko::removeItems(Item* item) {
    std::map<Item *, int>::iterator it = listItemToko.find(item);
    if (it != listItemToko.end()) {
        if(it->second > 1) {
            it->second--;
        } else {
            listItemToko.erase(it);
        }
    }
}

Item* Toko::getItemAt(int index) {
    int counter = 1;
    for(std::pair<Item *const, int> &it : listItemToko) {
        if (it.second == 0) {
            continue;
        }

        if (counter == index+1) {
            return it.first;
        }
        counter++;
    }
    return nullptr;
}

void Toko::displayToko(){
    int counter = 1;
    for(std::pair<Item *const, int> &it : listItemToko) {
        if (it.second == 0) {
            continue;
        }

        if (it.second == -1) {
            cout << counter << ". " << it.first->getNama() << " - " << it.first->getHarga() << endl;
        } else if (it.second > 0) {
            cout << counter << ". " << it.first->getNama() << " - " << it.first->getHarga() << " (" << it.second << ")" << endl;
        }

        counter++;
    }
}

Toko::Toko() {
    listItemToko.clear();

    // Add all items to the shop
    for (Plant &it : GameData::_plantConfig) {
        addItemsInfinite(new Plant(it));
    }

    for(Building &it : GameData::_buildingConfig) {
        initItem(new Building(it), 0);
    }

    for(Animal &it : GameData::_animalConfig) {
        addItemsInfinite(new Animal(it));
    }

    for(Product &it : GameData::_productConfig) {
        initItem(new Product(it),0);
    }
}

Toko::Toko(const Toko& T) {
    listItemToko = Toko::listItemToko;
}

void Toko::setListItems(std::map<Item*, int> setlistItemToko) {
    Toko::listItemToko = setlistItemToko;
}

void Toko::tambahListItems(std::map<Item*, int> listItemToko) {
    for (std::pair<Item *const, int> &it : listItemToko) {
        if (Toko::listItemToko.find(it.first) != Toko::listItemToko.end()) {
            Toko::listItemToko[it.first] += it.second;
        } else {
            Toko::listItemToko[it.first] = it.second;
        }
    }
}


