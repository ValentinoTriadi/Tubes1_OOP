#include "gameData.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

using namespace std;

vector<Product> GameData::_productConfig;
vector<Building> GameData::_buildingConfig;
vector<Animal> GameData::_animalConfig;
vector<Plant> GameData::_plantConfig;
vector<int> GameData::_gameConfig;

// Constructor
GameData::GameData() = default;

// Destructor
GameData::~GameData() = default;

// Method
void GameData::BacaConfigProduct() {
    ifstream file("config/product.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string code, name, type, origin;
        int id, weight, price;
        ss >> id >> code >> name >> type >> origin >> weight >> price;
        _productConfig.emplace_back(id, code, name, price, type, origin, weight);
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
        _buildingConfig.emplace_back(id, code, name, price, Recipe);
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
        _animalConfig.emplace_back(id, code, name, price, type, weight, 0);
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
        _plantConfig.emplace_back(id, code, name, price, type, duration, 0);
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
        _gameConfig.push_back(temp);
    }

    // besar inventory, lahan, peternakan
    for (int i = 0; i < 3; i++){
        getline(file, line);
        stringstream ss(line);
        ss >> temp >> temp1;
        _gameConfig.push_back(temp);
        _gameConfig.push_back(temp1);
    }

    file.close();
}

void GameData::DisplayConfigProduct() {
    cout << endl << "==================PRODUCT CONFIG==================" << endl;
    for (const Product &i : _productConfig) {
        i.print();
    }
    cout << endl << "==================PRODUCT CONFIG==================" << endl;
}

void GameData::DisplayConfigBuilding() {
    cout << endl << "==================BUILDING CONFIG==================" << endl;
    for (const Building &i : _buildingConfig) {
        i.print();
    }
    cout << endl << "==================BUILDING CONFIG==================" << endl;
}

void GameData::DisplayConfigAnimal() {
    cout << endl << "==================ANIMAL CONFIG==================" << endl;
    for (const Animal &i : _animalConfig) {
        i.print();
    }
    cout << endl << "==================ANIMAL CONFIG==================" << endl;
}

void GameData::DisplayConfigPlant() {
    cout << endl << "==================PLANT CONFIG==================" << endl;
    for (const Plant &i : _plantConfig) {
        i.print();
    }
    cout << endl << "==================PLANT CONFIG==================" << endl;
}

void GameData::DisplayConfigGame() {
    cout << endl << "==================GAME CONFIG==================" << endl;
    cout << "Uang: " << _gameConfig[0] << endl;
    cout << "Berat: " << _gameConfig[1] << endl;
    cout << "Besar Inventory: " << _gameConfig[2] << " x " << _gameConfig[3] << endl;
    cout << "Besar Lahan: " << _gameConfig[4] << " x " << _gameConfig[5] << endl;
    cout << "Besar Peternakan: " << _gameConfig[6] << " x " << _gameConfig[7] << endl;
    cout << endl << "==================GAME CONFIG==================" << endl;
}