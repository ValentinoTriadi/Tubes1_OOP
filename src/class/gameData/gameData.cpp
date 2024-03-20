#include "gameData.hpp"

// Constructor
GameData::GameData() {}

// Destructor
GameData::~GameData() {
    AnimalConfig.clear();
    PlantConfig.clear();
    BuildingConfig.clear();
    ProductConfig.clear();
    GameConfig.clear();
}

// Method
void GameData::BacaConfigProduct() {
    ifstream file("config/product.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string code, name, type, origin;
        int id, weight, price;
        ss >> id >> code >> name >> type >> origin >> weight >> price;
        ProductConfig.push_back(Product(id, code, name, price, type, origin, weight));
    }
    file.close();
}

void GameData::BacaConfigBuilding() {
    ifstream file("config/recipe.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        map<string, int> Recipe;
        string code, name, recipe;
        int id, price, qty;
        ss >> id >> code >> name >> price;
        while (ss >> recipe >> qty) {
            Recipe[recipe] = qty;
        }


        BuildingConfig.push_back(Building(id, code, name, price, Recipe));
    }
    file.close();
}

void GameData::BacaConfigAnimal() {
    ifstream file("config/animal.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string code, name, type;
        int id, price, weight;
        ss >> id >> code >> name >> type >> weight >> price;
        AnimalConfig.push_back(Animal(id, code, name, price, type, weight, 0));
    }
    file.close();
}

void GameData::BacaConfigPlant() {
    ifstream file("config/plant.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string code, name, type;
        int id, price, duration;
        ss >> id >> code >> name >> type >> duration >> price;
        PlantConfig.push_back(Plant(id, code, name, price, type, duration, 0));
    }
    file.close();
}

/*
    Isi vector GameConfig:
    <index>: <keterangan>
    * 0: uang
    * 1: berat
    * 2: besar inventory n
    * 3: besar inventory m 
    * 4: besar lahan n
    * 5: besar lahan m 
    * 6: besar peternakan n
    * 7: besar peternakan m
*/
void GameData::BacaConfigGame() {
    ifstream file("config/misc.txt");
    string line;
    int temp, temp1;
    
    // uang, berat
    for (int i = 0; i < 2; i++){
        getline(file, line);
        stringstream ss(line);
        ss >> temp;
        GameConfig.push_back(temp);
    }

    // besar inventory, lahan, peternakan
    for (int i = 0; i < 3; i++){
        getline(file, line);
        stringstream ss(line);
        ss >> temp >> temp1;
        GameConfig.push_back(temp);
        GameConfig.push_back(temp1);
    }

    file.close();
}

void GameData::DisplayConfigProduct() {
    cout << endl << "==================PRODUCT CONFIG==================" << endl;
    for (int i = 0; i < ProductConfig.size(); i++) {
        ProductConfig[i].print();
    }
    cout << endl << "==================PRODUCT CONFIG==================" << endl;
}

void GameData::DisplayConfigBuilding() {
    cout << endl << "==================BUILDING CONFIG==================" << endl;
    for (int i = 0; i < BuildingConfig.size(); i++) {
        BuildingConfig[i].print();
    }
    cout << endl << "==================BUILDING CONFIG==================" << endl;
}

void GameData::DisplayConfigAnimal() {
    cout << endl << "==================ANIMAL CONFIG==================" << endl;
    for (int i = 0; i < AnimalConfig.size(); i++) {
        AnimalConfig[i].print();
    }
    cout << endl << "==================ANIMAL CONFIG==================" << endl;
}

void GameData::DisplayConfigPlant() {
    cout << endl << "==================PLANT CONFIG==================" << endl;
    for (int i = 0; i < PlantConfig.size(); i++) {
        PlantConfig[i].print();
    }
    cout << endl << "==================PLANT CONFIG==================" << endl;
}

void GameData::DisplayConfigGame() {
    cout << endl << "==================GAME CONFIG==================" << endl;
    cout << "Uang: " << GameConfig[0] << endl;
    cout << "Berat: " << GameConfig[1] << endl;
    cout << "Besar Inventory: " << GameConfig[2] << " x " << GameConfig[3] << endl;
    cout << "Besar Lahan: " << GameConfig[4] << " x " << GameConfig[5] << endl;
    cout << "Besar Peternakan: " << GameConfig[6] << " x " << GameConfig[7] << endl;
    cout << endl << "==================GAME CONFIG==================" << endl;
}