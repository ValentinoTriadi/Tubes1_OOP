#include "plant.hpp"

// Constructor
Plant::Plant() : FarmEntity(), Age(0) {}
Plant::Plant(int Id, const string& Code, const string& Name, int Price, const string& Types, int HarvestLimit, int Age) : FarmEntity(Id, Code, Name, Price, Types, HarvestLimit, 2), Age(Age) {}

// Destructor
Plant::~Plant() = default;

// Getter
int Plant::getAge() const {
    return Age;
}

// Setter
void Plant::setAge(int SetAge) {
    this->Age = SetAge;
}

// Method
void Plant::print() const {
    FarmEntity::print();
    cout << "Duration to harvest: " << getHarvestLimit() << endl;
    cout << "Age: " << Age << endl;
}

void Plant::grow() {
    Age++;
}
