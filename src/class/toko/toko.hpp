#ifndef TOKO_HPP
#define TOKO_HPP
#include <map>
#include "../item/item.hpp"


class Toko {
    public:
        Toko();
        Toko(const Toko& toko);

        static void addItems(Item* item);
        static void removeItems(Item* item);
        static Item* getItemAt(int index);
        static void displayToko();


    static void setListItems(map<Item *, int> listItemToko);

    static void tambahListItems(map<Item *, int> listItemToko);

private:
        static std::map<Item*, int> listItemToko;

    static void addItemsInfinite(Item *item);

    static void decreaseItems(Item *item);

    static bool isItemAvailable(Item *item);

    static void initItem(Item *item, int quantity);

};


#endif