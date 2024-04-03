#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "../item.hpp"

class Product final : public Item {
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
        Product(int Id, const string &Code, const string &Name, int Price, string Type, string Origin, int AddedWeight);

        /**
         * Destructor
         * !```Don't call this function directly```!
        */
        ~Product() override;


        /**
         * Get Type of Product
         * @return Type of Product
        */
        [[nodiscard]] string getType() const;
        /**
         * Get Origin of Product
         * @return Origin of Product
        */
        [[nodiscard]] string getOrigin() const;
        /**
         * Get Added Weight of Product
         * @return Added Weight of Product
        */
        [[nodiscard]] int getAddedWeight() const;

        void print() const override;

    private:
        const string Type;
        const string Origin;
        const int AddedWeight;
        int price_;
};

#endif