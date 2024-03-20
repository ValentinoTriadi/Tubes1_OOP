#ifndef __BUILDING_HPP__
#define __BUILDING_HPP__

#include "../item.hpp"
#include <map>

class Building : public Item {
    public:
        Building();
        Building(int, string, string, int, map<string, int>);
        ~Building();

        map<string, int> getRecipe() const;

        void print() const;

    private:
        map<string, int> Recipe;
};

#endif