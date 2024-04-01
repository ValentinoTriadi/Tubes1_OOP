#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include "../item.hpp"
#include <map>

class Building final : public Item {
    public:
        Building();
        Building(int, const string&, const string&, int, const map<string, int>&);

        ~Building() override;

        [[nodiscard]] map<string, int> getRecipe() const;

        void print() const override;

    private:
        map<string, int> Recipe;
};

#endif