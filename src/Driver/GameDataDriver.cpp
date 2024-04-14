#include "gameData.hpp"

int main(){
    GameData gameData;

    gameData.BacaConfigAnimal();
    gameData.BacaConfigBuilding();
    gameData.BacaConfigGame();
    gameData.BacaConfigPlant();
    gameData.BacaConfigProduct();

    gameData.DisplayConfigAnimal();
    gameData.DisplayConfigBuilding();
    gameData.DisplayConfigGame();
    gameData.DisplayConfigPlant();
    gameData.DisplayConfigProduct();
    return 0;
}