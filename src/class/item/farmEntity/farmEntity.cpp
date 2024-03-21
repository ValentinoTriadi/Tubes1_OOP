#include "farmEntity.hpp"

// define the constructor
FarmEntity::FarmEntity() : Item(), Type(""), HarvestLimit(0) {}
FarmEntity::FarmEntity(const int Id, const string& Code, const string& Name, const int Price, const string& Type, const int HarvestLimit) : Item(Id, Code, Name, Price), Type(Type), HarvestLimit(HarvestLimit) {}

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