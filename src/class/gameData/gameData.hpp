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
        /**
         * Default Constructor
         * Usage: ```GameData gameData;```
        */
        GameData();
        /**
         * Destructor
         * ```Don't call this function directly!```
        */
        ~GameData();

        /*Baca Config Product ```src/config/product.txt```*/
        void BacaConfigProduct();
        /*Baca Config Recipe ```src/config/recipe.txt```*/
        void BacaConfigBuilding();
        /*Baca Config Animal ```src/config/animal.txt```*/
        void BacaConfigAnimal();
        /*Baca Config Plant ```src/config/plant.txt```*/
        void BacaConfigPlant();
        /*Baca Config Misc ```src/config/misc.txt```*/
        void BacaConfigGame();

        /*Tampilkan Config Product ```src/config/product.txt```*/
        void DisplayConfigProduct();
        /*Tampilkan Config Recipe ```src/config/recipe.txt```*/
        void DisplayConfigBuilding();
        /*Tampilkan Config Animal ```src/config/animal.txt```*/
        void DisplayConfigAnimal();
        /*Tampilkan Config Plant ```src/config/plant.txt```*/
        void DisplayConfigPlant();
        /*Tampilkan Config Misc ```src/config/misc.txt```*/
        void DisplayConfigGame();
        

    private:
        vector<Product> ProductConfig;
        vector<Building> BuildingConfig;
        vector<Animal> AnimalConfig;
        vector<Plant> PlantConfig;
        vector<int> GameConfig;
};

#endif