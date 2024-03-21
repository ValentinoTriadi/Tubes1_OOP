#include "plant.hpp"

// Constructor
Plant::Plant() : FarmEntity(), Age(0) {}
Plant::Plant(int Id, string Code, string Name, int Price, string Type, int HarvestLimit, int Age) : FarmEntity(Id, Code, Name, Price, Type, HarvestLimit), Age(Age) {}

// Destructor
Plant::~Plant() {}

// Getter
int Plant::getAge() const {
    return Age;
}

// Setter
void Plant::setAge(int Age) {
    this->Age = Age;
}

// Method
void Plant::print() const {
    FarmEntity::print();
    cout << "Duration to harvest: " << getHarvestLimit() << endl;
    cout << "Age: " << Age << endl;
}