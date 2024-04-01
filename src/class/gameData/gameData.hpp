#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

#include "../item/building/building.hpp"
#include "../item/farmEntity/animal/animal.hpp"
#include "../item/farmEntity/plant/plant.hpp"
#include "../item/product/product.hpp"
#include <vector>

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
        void DisplayConfigProduct() const;
        /*Tampilkan Config Recipe ```src/config/recipe.txt```*/
        void DisplayConfigBuilding() const;
        /*Tampilkan Config Animal ```src/config/animal.txt```*/
        void DisplayConfigAnimal() const;
        /*Tampilkan Config Plant ```src/config/plant.txt```*/
        void DisplayConfigPlant() const;
        /*Tampilkan Config Misc ```src/config/misc.txt```*/
        void DisplayConfigGame() const;

        /*getter for game config*/
        /*
        Isi vector GameConfig:
        <index>: <keterangan>
        * 0: max uang
        * 1: max berat
        * 2: besar inventory n
        * 3: besar inventory m 
        * 4: besar lahan n
        * 5: besar lahan m 
        * 6: besar peternakan n
        * 7: besar peternakan m
        */
        vector<int> GetGameConfig()const {return _gameConfig; }
        

    private:
        vector<Product> _productConfig{};
        vector<Building> _buildingConfig{};
        vector<Animal> _animalConfig{};
        vector<Plant> _plantConfig{};
        vector<int> _gameConfig{};
};

#endif