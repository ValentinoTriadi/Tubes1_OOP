#include "animal.hpp"

#include <iostream>

// Constructor
Animal::Animal() : FarmEntity(), Weight(0) {}
Animal::Animal(int Id, const string& Code, const string& Name, int Price, const string& Type, int HarvestLimit, int Weight) : FarmEntity(Id, Code, Name, Price, Type, HarvestLimit, 1), Weight(Weight) {}

// Destructor
Animal::~Animal() = default;

// Getter
int Animal::getWeight() const {
    return Weight;
}

// Setter
void Animal::setWeight(int SetWeight) {
    this->Weight = SetWeight;
}

// Method
void Animal::print() const {
    FarmEntity::print();
    cout << "Weight to harvest: " << getHarvestLimit() << endl;
    cout << "Weight: " << Weight << endl;
}