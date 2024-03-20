#include "building.hpp"

// define the constructor
Building::Building() : Item(), Recipe() {}
Building::Building(int Id, string Code, string Name, int Price, map<string, int> Recipe) : Item(Id, Code, Name, Price), Recipe(Recipe) {}

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
    map<string, int>::const_iterator iter;
    cout << "Recipe: " << endl;
    for (iter = Recipe.begin(); iter != Recipe.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
}