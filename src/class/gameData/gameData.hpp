#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

#include "../item/building/building.hpp"
#include "../item/farmEntity/animal/animal.hpp"
#include "../item/farmEntity/plant/plant.hpp"
#include "../item/product/product.hpp"
#include <vector>

class GameData {
    public:
        GameData();
        ~GameData();

        static void BacaConfigProduct();
        void BacaConfigBuilding();
        void BacaConfigAnimal();
        void BacaConfigPlant();
        void BacaConfigGame();

        void DisplayConfigProduct() const;
        void DisplayConfigBuilding() const;
        void DisplayConfigAnimal() const;
        void DisplayConfigPlant() const;
        void DisplayConfigGame() const;
        

    private:
        vector<Product> _productConfig{};
        vector<Building> _buildingConfig{};
        vector<Animal> _animalConfig{};
        vector<Plant> _plantConfig{};
        vector<int> _gameConfig{};
};

#endif