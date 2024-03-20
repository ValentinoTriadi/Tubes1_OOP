#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    public:
        Item();
        Item(int, string, string, int);
        ~Item();

        int getId() const;
        string getCode() const;
        string getNama() const;
        int getHarga() const;

        virtual void print() const;

    private:
        const int Id;
        const string Code;
        const string Name;
        const int Price;
};

#endif