#include "ladang.hpp"

Ladang::Ladang() : Container() {
    // Inisialisasi Ladang
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            items[i][j] = nullptr;
        }
    }
}

Ladang::Ladang(int row, int col) : Container(row, col) {
    // Inisialisasi Ladang
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            items[i][j] = nullptr;
        }
    }
}

Ladang::Ladang(const Ladang& ladang) : Container(ladang) {
}

Ladang::~Ladang() {
}

Ladang& Ladang::operator=(const Ladang& ladang) {
    this->row = ladang.row;
    this->col = ladang.col;
    this->cellKosong = ladang.cellKosong;

    this->items.clear();
    this->items.resize(row, vector<Item*>(col, nullptr));

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            items[i][j] = ladang.items[i][j];
        }
    }
    return *this;
}

ostream& Ladang::printRow(ostream& os, int row) const {

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

void Ladang::showPlant(){
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

map<string, int> Ladang::getHarvest(){
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

ostream& operator<<(ostream& os, const Ladang& ladang) {
    os << "=================[ Ladang ]==================" << endl << endl;

    ladang.printColumnName(os);
    ladang.printSeparator(os);

    for (int i = 0; i < ladang.getRow(); i++) {
        ladang.printRow(os, i);
        ladang.printSeparator(os);
    }

    return os;
}

bool Ladang::isReadyToHarvest(Item* item) const {
    return dynamic_cast<Plant*>(item)->getAge() >= dynamic_cast<Plant*>(item)->getHarvestLimit();
}