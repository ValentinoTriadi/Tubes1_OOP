#include "product.hpp"

#include <iostream>
#include <utility>

// define the constructor
Product::Product() : AddedWeight(0), price_(0) {}
Product::Product(const int Id, const string &Code, const string &Name, const int Price, string Type, string Origin, const int AddedWeight) : Item(Id, Code, Name, Price, 0), Type(std::move(Type)), Origin(std::move(Origin)), AddedWeight(AddedWeight), price_(Price) {}
Product::Product(const Product &P) : Item(P), Type(P.Type), Origin(P.Origin), AddedWeight(P.AddedWeight), price_(P.price_) {}

// define the destructor
Product::~Product(){};

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