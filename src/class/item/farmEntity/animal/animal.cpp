#include "animal.hpp"

#include <iostream>

// Constructor
Animal::Animal() : FarmEntity(), Weight(0) {}
Animal::Animal(const int Id, const string& Code, const string& Name, const int Price, const string& Type, const int HarvestLimit, const int Weight) : FarmEntity(Id, Code, Name, Price, Type, HarvestLimit), Weight(Weight) {}

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