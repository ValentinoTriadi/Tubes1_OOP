#include "peternakan.hpp"

Peternakan::Peternakan() : Container() {
    // Inisialisasi Peternakan
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            items[i][j] = nullptr;
        }
    }
}

Peternakan::Peternakan(int row, int col) : Container(row, col) {
    // Inisialisasi Peternakan
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            items[i][j] = nullptr;
        }
    }
}

Peternakan::Peternakan(const Peternakan& peternakan) : Container(peternakan) {
}

Peternakan::~Peternakan() {
}

Peternakan& Peternakan::operator=(const Peternakan& peternakan) {
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            items[i][j] = peternakan.items[i][j];
        }
    }
    return *this;
}

ostream& Peternakan::printRow(ostream& os, int row) const {

    if (row < 9) {
        os << "0";
    }

    // Print the row number
    os << row + 1 << " ";

    // Print the items in the row
    for (int i = 0; i < col; i++) {
        os << "|";

        // Print the item code if it is not nullptr
        if (items[row][i] != nullptr) {
            if (isReadyToHarvest(items[row][i])){
                os << "\033[32m " << items[row][i]->getCode() << "\033[0m ";
            } else {
                os << "\033[31m " << items[row][i]->getCode() << "\033[0m ";
            }
        } else {
            os << "     ";
        }
    }

    os << "|" << endl;

    return os;
}

void Peternakan::showAnimal(){
    set<string> temp;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (items[i][j] != nullptr){
                if (temp.find(items[i][j]->getCode()) == temp.end()){
                    temp.insert(items[i][j]->getCode());
                    std::cout <<  " - " << items[i][j]->getCode() << " : " << items[i][j]->getNama() << endl;
                }
            }
        }
    }
}

map<string, int> Peternakan::getHarvest(){
    map<string, int> temp;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (items[i][j] != nullptr){
                if (isReadyToHarvest(items[i][j])) temp[items[i][j]->getCode()]++;
            }
        }
    }

    return temp;
}

ostream& operator<<(ostream& os, const Peternakan& ladang) {
    os << "=================[ Peternakan ]==================" << endl << endl;

    ladang.printColumnName(os);
    ladang.printSeparator(os);

    for (int i = 0; i < ladang.getRow(); i++) {
        ladang.printRow(os, i);
        ladang.printSeparator(os);
    }

    return os;
}

bool Peternakan::isReadyToHarvest(Item* item) const {
    return dynamic_cast<Animal*>(item)->getWeight() >= dynamic_cast<Animal*>(item)->getHarvestLimit();
}