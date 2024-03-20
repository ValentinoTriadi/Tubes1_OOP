#ifndef __GAMEDATA_HPP__
#define __GAMEDATA_HPP__

#include "../item/building/building.hpp"
#include "../item/farmEntity/animal/animal.hpp"
#include "../item/farmEntity/plant/plant.hpp"
#include "../item/product/product.hpp"
#include <fstream>
#include <sstream>

class GameData {
    public:
        GameData();
        ~GameData();

        void BacaConfigProduct();
        void BacaConfigBuilding();
        void BacaConfigAnimal();
        void BacaConfigPlant();
        void BacaConfigGame();

        void DisplayConfigProduct();
        void DisplayConfigBuilding();
        void DisplayConfigAnimal();
        void DisplayConfigPlant();
        void DisplayConfigGame();
        

    private:
        vector<Product> ProductConfig;
        vector<Building> BuildingConfig;
        vector<Animal> AnimalConfig;
        vector<Plant> PlantConfig;
        vector<int> GameConfig;
};

#endif