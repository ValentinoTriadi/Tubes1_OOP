#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>
using namespace std;

class Item {
    public:
        Item();
        Item(int, string, string, int);

    protected:
        ~Item();

    public:
        [[nodiscard]] int getId() const;
        [[nodiscard]] string getCode() const;
        [[nodiscard]] string getNama() const;
        [[nodiscard]] int getHarga() const;

        virtual void print() const;

    private:
        const int Id;
        const string Code;
        const string Name;
        const int Price;
};

#endif