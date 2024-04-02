#include "item.hpp"

#include <iostream>
#include <ostream>
#include <utility>

// define the constructor
Item::Item() : Id(0), Price(0), ItemType(0) {}
Item::Item(int Id, string Code, string Name, int Price, int ItemType) : Id(Id), Code(std::move(Code)), Name(std::move(Name)), Price(Price), ItemType(ItemType) {}

// define the destructor
Item::~Item() = default;

// define the getter
int Item::getId() const {
    return Id;
}
string Item::getCode() const {
    return Code;
}
string Item::getNama() const {
    return Name;
}
int Item::getHarga() const {
    return Price;
}
int Item::getItemType() const {
    return ItemType;
}

// define method
void Item::print() const {
    cout << endl << "----------ITEM----------" << endl;
    cout << "Id: " << Id << endl;
    cout << "Code: " << Code << endl;
    cout << "Name: " << Name << endl;
    cout << "Price: " << Price << endl;
}