#include "farmEntity.hpp"

#include <iostream>
#include <utility>

// define the constructor
FarmEntity::FarmEntity() : HarvestLimit(0) {}
FarmEntity::FarmEntity(int Id, const string &Code, const string &Name, int Price, string Type, int HarvestLimit, int ItemType) : Item(Id, Code, Name, Price, ItemType), Type(std::move(Type)), HarvestLimit(HarvestLimit) {}

// define the destructor
FarmEntity::~FarmEntity() = default;

// define the getter
string FarmEntity::getType() const {
    return Type;
}
int FarmEntity::getHarvestLimit() const {
    return HarvestLimit;
}

// define method
void FarmEntity::print() const {
    Item::print();
    cout << "Type: " << Type << endl;
}