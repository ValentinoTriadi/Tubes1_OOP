#ifndef TOKO_HPP
#define TOKO_HPP
#include <map>
#include "../item/item.hpp"


class Toko {
    public:
        static void addItems(Item* item);
        static void removeItems(Item* item);
        static Item* getItemAt(int index);
        static void displayToko();

        static std::map<Item*, int> getListItemToko() {return listItemToko;}

    private:
        static std::map<Item*, int> listItemToko;
};


#endif