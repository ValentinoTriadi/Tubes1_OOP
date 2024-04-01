#include "building.hpp"

#include <iostream>

// define the constructor
Building::Building() : Item(), Recipe() {}
Building::Building(int Id,const string& Code,const string& Name,int Price,const map<string, int>& Recipe) : Item(Id, Code, Name, Price, 3), Recipe(Recipe) {}

// define the destructor
Building::~Building() {
    Recipe.clear();
}

// define the getter
map<string, int> Building::getRecipe() const {
    return Recipe;
}

// define method
void Building::print() const {
    Item::print();
    cout << "Recipe: " << endl;
    for (const auto &[fst, snd] : Recipe) {
        cout << fst << ": " << snd << endl;
    }
}