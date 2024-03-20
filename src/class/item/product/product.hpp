#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include "../item.hpp"

class Product : public Item {
    public:
        Product();
        Product(int, string, string, int, string, string, int);
        ~Product();

        string getType() const;
        string getOrigin() const;
        int getAddedWeight() const;

        void print() const;

    private:
        const string Type;
        const string Origin;
        const int AddedWeight;
};

#endif