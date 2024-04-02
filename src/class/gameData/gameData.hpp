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
        static void BacaConfigProduct();
        /*Baca Config Recipe ```src/config/recipe.txt```*/
        static void BacaConfigBuilding();
        /*Baca Config Animal ```src/config/animal.txt```*/
        static void BacaConfigAnimal();
        /*Baca Config Plant ```src/config/plant.txt```*/
        static void BacaConfigPlant();
        /*Baca Config Misc ```src/config/misc.txt```*/

        static void BacaConfigGame();

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

        static vector<Product> _productConfig;
        static vector<Building> _buildingConfig;
        static vector<Animal> _animalConfig;
        static vector<Plant> _plantConfig;
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
        static vector<int> _gameConfig;
};

#endif