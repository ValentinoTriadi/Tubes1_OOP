#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include "../item.hpp"

class Product : public Item {
    public:
        /**
         * Default Constructor
         * Usage: ```Product product;```
        */
        Product();
        /**
         * Constructor
         * @param Id ID of Product
         * @param Code Code of Product
         * @param Name Name of Product
         * @param Price Price of Product
         * @param Type Type of Product
         * @param Origin Origin of Product
         * @param AddedWeight Added Weight of Product
        */
        Product(const int, const string&, const string&, const int, const string&, const string&, const int);
        /**
         * Destructor
         * !```Don't call this function directly```!
        */
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