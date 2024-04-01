#include "StateManager.hpp"

StateManager::StateManager(){
    _listPlayer = vector<People*>();
    _listItemToko = vector<Item*>();
};

StateManager::~StateManager(){
    for (int i = 0; i < _listPlayer.size(); i++){
        delete _listPlayer[i];
    }
    for (int i = 0; i < _listItemToko.size(); i++){
        delete _listItemToko[i];
    }
};

void StateManager::defaultState(const vector<int>& gameConfig){
    // Petani petani1 = Petani("Petani1", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100);
}

void StateManager::loadState(const vector<int>& gameConfig){
    std::cout << "Apakah Anda ingin memuat state? (y/n) ";

    char answer;
    std::cin >> answer;

    while ((char)tolower(answer) != 'y' && (char)tolower(answer) != 'n'){
        std::cout << "Masukkan tidak valid. Silakan masukkan 'y' atau 'n'." << std::endl;
        std::cin >> answer;
    }

    if ((char)tolower(answer) == 'y'){
        loadFromFile();
    } else {
        defaultState();
    }
}


StateManager::~StateManager() = default;

void StateManager::defaultState(){
    Petani petani1 = Petani("Petani1", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100);
}
