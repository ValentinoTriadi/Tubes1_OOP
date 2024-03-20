#include "farmEntity.hpp"

// define the constructor
FarmEntity::FarmEntity() : Item(), Type(""), HarvestLimit(0) {}
FarmEntity::FarmEntity(int Id, string Code, string Name, int Price, string Type, int HarvestLimit) : Item(Id, Code, Name, Price), Type(Type), HarvestLimit(HarvestLimit) {}

// define the destructor
FarmEntity::~FarmEntity() {}

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