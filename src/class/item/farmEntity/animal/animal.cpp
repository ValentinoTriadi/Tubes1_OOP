#include "animal.hpp"

// Constructor
Animal::Animal() : FarmEntity(), Weight(0) {}
Animal::Animal(int Id, string Code, string Name, int Price, string Type, int HarvestLimit, int Weight) : FarmEntity(Id, Code, Name, Price, Type, HarvestLimit), Weight(Weight) {}

// Destructor
Animal::~Animal() {}

// Getter
int Animal::getWeight() const {
    return Weight;
}

// Setter
void Animal::setWeight(int Weight) {
    this->Weight = Weight;
}

// Method
void Animal::print() const {
    FarmEntity::print();
    cout << "Weight to harvest: " << getHarvestLimit() << endl;
    cout << "Weight: " << Weight << endl;
}