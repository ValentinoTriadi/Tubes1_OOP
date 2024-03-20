#include "item.hpp"

// define the constructor
Item::Item() : Id(0), Code(""), Name(""), Price(0) {}
Item::Item(int Id, string Code, string Name, int Price) : Id(Id), Code(Code), Name(Name), Price(Price) {}

// define the destructor
Item::~Item() {}

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

// define method
void Item::print() const {
    cout << endl << "----------ITEM----------" << endl;
    cout << "Id: " << Id << endl;
    cout << "Code: " << Code << endl;
    cout << "Name: " << Name << endl;
    cout << "Price: " << Price << endl;
}