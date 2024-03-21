#include "product.hpp"

// define the constructor
Product::Product() : Item(), Type(""), Origin(""), AddedWeight(0) {}
Product::Product(const int Id, const string& Code, const string& Name, const int Price, const string& Type, const string& Origin, const int AddedWeight) : Item(Id, Code, Name, Price), Type(Type), Origin(Origin), AddedWeight(AddedWeight) {}

// define the destructor
Product::~Product() {}

// define the getter
string Product::getType() const {
    return Type;
}
string Product::getOrigin() const {
    return Origin;
}
int Product::getAddedWeight() const {
    return AddedWeight;
}

// define method
void Product::print() const {
    Item::print();
    cout << "Type: " << Type << endl;
    cout << "Origin: " << Origin << endl;
    cout << "Added Weight: " << AddedWeight << endl;
}