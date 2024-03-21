#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "../item.hpp"

class Product final : public Item {
    public:
        Product();

        Product(int Id, const string &Code, const string &Name, int Price, string Type, string Origin,
                int AddedWeight);

        virtual ~Product();

        [[nodiscard]] string getType() const;
        [[nodiscard]] string getOrigin() const;
        [[nodiscard]] int getAddedWeight() const;

        void print() const override;

    private:
        const string Type;
        const string Origin;
        const int AddedWeight;
        int price_;
};

#endif