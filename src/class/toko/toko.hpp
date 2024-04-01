#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include "item.hpp"

using namespace std;

class Toko{
    private:
        vector<Item*> listItemToko;

    public:
        Toko();
        ~Toko();
        void addItems(Item* item);
        void removeItems(Item* item);
        void displayToko();
};

#endif