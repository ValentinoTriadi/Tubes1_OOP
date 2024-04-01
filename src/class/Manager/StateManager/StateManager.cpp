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
    int umur;

    for (int i = 0; i < countAnimal; i++){
        file >> kode >> name >> umur;
        cout << kode << " " << name << " " << umur << endl;
    }

    return Farmer();
}

Stockman& readStockman(ifstream& file, int rowStorage, int colStorage, int rowLand, int colLand){
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
    int umur;

    for (int i = 0; i < countAnimal; i++){
        file >> kode >> name >> umur;
        cout << kode << " " << name << " " << umur << endl;
    }

    return Stockman();
}

Mayor& readMayor(ifstream& file, int rowStorage, int colStorage, int rowLand, int colLand){
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
    int umur;

    for (int i = 0; i < countAnimal; i++){
        file >> kode >> name >> umur;
        cout << kode << " " << name << " " << umur << endl;
    }

    return Mayor();
}

void readShop(ifstream& file){
    int countItems;

    file >> countItems;

    for (int i = 0; i < countItems; i++){
        string name;
        int price;

        file >> name >> price;
        cout << name << " " << price << endl;
    }
}

void StateManager::loadFromFile(const vector<int>& gameConfig){
    std::cout << "Masukkan lokasi berkas state : ";

    string filename;
    cin >> filename;

    ifstream file(filename);

    while (!file.is_open()){
        std::cout << "Berkas tidak valid. Silakan masukkan lokasi berkas yang valid: ";
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
            Farmer temp = readFarmer(file, gameConfig[3], gameConfig[4], gameConfig[5], gameConfig[6]);

            _listPlayer.push_back(&temp);
        } else if (type == "Pedagang"){
            Stockman temp = readStockman(file, gameConfig[3], gameConfig[4], gameConfig[5], gameConfig[6]);

            _listPlayer.push_back(&temp);
        } else if (type == "Walikota"){
            Mayor temp = readMayor(file, gameConfig[3], gameConfig[4], gameConfig[5], gameConfig[6]);

            _listPlayer.push_back(&temp);
        } else {
            std::cout << "Tipe pemain tidak valid." << std::endl;
        }
    }

    // Load shop items
    readShop(file);

    file.close();
}

void StateManager::saveStateToFile(){
    std::cout << "Masukkan lokasi berkas state : ";

    string filename;
    cin >> filename;

    ofstream file(filename);

    file << _listPlayer.size() << std::endl;

    for (int i = 0; i < _listPlayer.size(); i++){
        file << _listPlayer[i]->getName() << " " << _listPlayer[i]->getType() << " " << _listPlayer[i]->getMoney() << " " << _listPlayer[i]->getWeight() << std::endl;

        for (int j = 0; j < _listPlayer[i]->getInventory().getRowCount(); j++){
            for (int k = 0; k < _listPlayer[i]->getInventory().getColCount(); k++){
                if (_listPlayer[i]->getInventory()(j, k) != nullptr){
                    file << _listPlayer[i]->getInventory()(j, k)->getName() << " ";
                }
            }
        }

        if (_listPlayer[i]->getType() == "Petani"){
            Farmer* temp = dynamic_cast<Farmer*>(_listPlayer[i]);

            file << temp->getAnimalCount() << std::endl;

            for (int j = 0; j < temp->getAnimalCount(); j++){
                file << temp->getAnimal(j)->getKode() << " " << temp->getAnimal(j)->getName() << " " << temp->getAnimal(j)->getUmur() << std::endl;
            }
        } else if (_listPlayer[i]->getType() == "Pedagang"){
            Stockman* temp = dynamic_cast<Stockman*>(_listPlayer[i]);

            file << temp->getAnimalCount() << std::endl;

            for (int j = 0; j < temp->getAnimalCount(); j++){
                file << temp->getAnimal(j)->getKode() << " " << temp->getAnimal(j)->getName() << " " << temp->getAnimal(j)->getUmur() << std::endl;
            }
        }
    }

    file << _listItemToko.size() << std::endl;

    for (int i = 0; i < _listItemToko.size(); i++){
        file << _listItemToko[i]->getName() << " " << _listItemToko[i]->getPrice() << std::endl;
    }

    file.close();
}
