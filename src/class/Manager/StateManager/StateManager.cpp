#include "StateManager.hpp"

StateManager::StateManager(){
    _listPlayer = vector<People*>();
    _listToko = vector<Item*>();
};

StateManager::~StateManager(){
    for (int i = 0; i < _listPlayer.size(); i++){
        delete _listPlayer[i];
    }
    for (int i = 0; i < _listToko.size(); i++){
        delete _listToko[i];
    }
};

void StateManager::defaultState(){

}

void StateManager::loadState(){
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

void StateManager::defaultState(){
    Petani petani1 = Petani("Petani1", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100);
}