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
        loadFromFile(gameConfig);
    } else {
        defaultState(gameConfig);
    }
}

Farmer& readFarmer(ifstream& file, int rowStorage, int colStorage, int rowLand, int colLand){
    string line;
    int countItems, countAnimal;

    file >> countItems;

    Container inventory = Container(rowStorage, colStorage);

    for (int i = 0; i < countItems; i++){
        string name;
        file >> name;
        cout << name << endl;
    }

    file >> countAnimal;

    string kode, name;
    int numofCurrentItem;

    for (int i = 0; i < countAnimal; i++){
        file >> kode >> name >> numofCurrentItem;
        cout << kode << " " << name << " " << numofCurrentItem << endl;
    }
}

void StateManager::loadFromFile(const vector<int>& gameConfig){
    std::cout << "Masukkan lokasi berkas state : ";

    string filename;
    cin >> filename;

    ifstream file(filename);

    while (!file.is_open()){
        std::cout << "Berkas tidak ditemukan. Silakan masukkan lokasi berkas yang valid: ";
        cin >> filename;
        file.open(filename);
    }

    string line;

    // Load player count
    int n;
    file >> n;

    for (int i = 0; i < n; i++){
        string name, type;
        int money, weight;

        if (type == "Petani"){

        } else if (type == "Peternak"){

        } else if (type == "Walikota"){

        }
    }



    file.close();
}