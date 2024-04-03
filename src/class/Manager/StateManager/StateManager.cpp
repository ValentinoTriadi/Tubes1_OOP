#include "StateManager.hpp"

vector<People*> StateManager::_listPlayer;
map<Item*, int> StateManager::_listItemToko;

StateManager::StateManager()= default;

StateManager::~StateManager()= default;

void StateManager::defaultState(){

}

void StateManager::loadState(){
    std::cout << "Apakah Anda ingin memuat state? (y/n) ";

    bool input;
    while (true) {
        try {
            input = InputManager::receiveBooleanInput();
            break;
        } catch (GameException& e){
            cout << e.what() << endl;
        }
    }

    if (input){
        loadFromFile();
    } else {
        defaultState();
    }
}

Farmer* StateManager::readFarmer(ifstream& file, string name, int money, int weight, vector<int> gameConfig){
    Farmer* farmer = new Farmer(name, weight, money, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
    int countItems, plantCount;

    file >> countItems;

    Container* inventory = new Container(gameConfig[2], gameConfig[3]);

    int row = 0, col = 0;
    for (int i = 0; i < countItems; i++){
        file >> name;
        inventory->setItem(row, col++, getItemByName(name));

        if (col == gameConfig[3]){
            col = 0;
            row++;
        }
    }

    file >> plantCount;

    Ladang* ladang = new Ladang(gameConfig[4], gameConfig[5]);

    string slot, plantName;
    int age;

    for (int i = 0; i < plantCount; i++){
        file >> slot >> plantName >> age;
        
        Plant* plant = dynamic_cast<Plant*>(getItemByName(plantName));
        plant->setAge(age);
        ladang->setItem(slot, plant);
    }

    farmer->setLadang(*ladang);
    farmer->setStorage(*inventory);

    return farmer;
}

Stockman* StateManager::readStockman(ifstream& file, string name, int money, int weight, vector<int> gameConfig){
    Stockman* stockman = new Stockman(name, weight, money, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
    int countItems, countAnimal;

    file >> countItems;

    Container* inventory = new Container(gameConfig[2], gameConfig[3]);

    int row = 0, col = 0;
    for (int i = 0; i < countItems; i++){
        string name;
        file >> name;
        inventory->setItem(row, col++, getItemByName(name));

        if (col == gameConfig[3]){
            col = 0;
            row++;
        }
    }

    file >> countAnimal;

    Peternakan* peternakan = new Peternakan(gameConfig[4], gameConfig[5]);

    string slot, animalName;
    int weightAnimal;

    for (int i = 0; i < countAnimal; i++){
        file >> slot >> name >> weightAnimal;
        Animal* animal = dynamic_cast<Animal*>(getItemByName(name));
        animal->setWeight(weightAnimal);
        peternakan->setItem(slot, animal);
    }

    stockman->setPeternakan(*peternakan);
    stockman->setStorage(*inventory);

    return stockman;
}

Mayor* StateManager::readMayor(ifstream& file, string name, int money, int weight, vector<int> gameConfig){
    Mayor* mayor = new Mayor(name, weight, money, gameConfig[2], gameConfig[3]);
    int countItems;

    file >> countItems;

    Container* inventory = new Container(gameConfig[2], gameConfig[3]);

    int row = 0, col = 0;
    for (int i = 0; i < countItems; i++){
        file >> name;
        inventory->setItem(row, col++, getItemByName(name));

        if (col == gameConfig[3]){
            col = 0;
            row++;
        }
    }

    mayor->setStorage(*inventory);

    return mayor;
}

void StateManager::readShop(ifstream& file){
    int countItems;

    file >> countItems;

    for (int i = 0; i < countItems; i++){
        string name;
        int stock;

        file >> name >> stock;
        _listItemToko[getItemByName(name)] = stock;
    }
}

void StateManager::loadFromFile(){
    std::cout << "Masukkan lokasi berkas state : ";

    InputManager::receiveStringInput();
    string filename = InputManager::_inputData<string>;

    ifstream file(filename);

    while (!file.is_open()){
        std::cout << "Berkas tidak valid. Silakan masukkan lokasi berkas yang valid: ";
        InputManager::receiveStringInput();
        filename = InputManager::_inputData<string>;
        file.open(filename);
    }

    vector<int> gameConfig = GameData::_gameConfig;

    // Load player count
    int n;
    file >> n;

    for (int i = 0; i < n; i++){
        string name, type;
        int money, weight;

        file >> name >> type >> money >> weight;

        if (type == "Petani"){
            _listPlayer.push_back(readFarmer(file, name, money, weight, gameConfig));
        } else if (type == "Peternak"){
            _listPlayer.push_back(readStockman(file, name, money, weight, gameConfig));
        } else if (type == "Walikota"){
            _listPlayer.push_back(readMayor(file, name, money, weight, gameConfig));
        } else {
            std::cout << "Tipe pemain tidak valid." << std::endl;
        }
    }

    // Load shop items
    readShop(file);
    file.close();
}

void StateManager::saveState(){
    std::cout << "Masukkan lokasi berkas state : ";

    InputManager::receiveStringInput();

    ofstream file(InputManager::_inputData<string>);

    file << _listPlayer.size() << std::endl;

    for (int i = 0; i < _listPlayer.size(); i++){
        string tipe;

        if (_listPlayer[i]->GetType() == 1){
            tipe = "Walikota";
        } else if (_listPlayer[i]->GetType() == 2){
            tipe = "Petani";
        } else if (_listPlayer[i]->GetType() == 3){
            tipe = "Peternak";
        }

        file << _listPlayer[i]->GetName() << " " << tipe << " " << _listPlayer[i]->GetKeuangan() << " " << _listPlayer[i]->GetWeight() << std::endl;

        file << _listPlayer[i]->getStorage().getRow() * _listPlayer[i]->getStorage().getCol() - _listPlayer[i]->getStorage().getCellKosong() << std::endl;

        for (int j = 0; j < _listPlayer[i]->getStorage().getRow(); j++){
            for (int k = 0; k < _listPlayer[i]->getStorage().getCol(); k++){
                if (_listPlayer[i]->getStorage()(j, k) != nullptr){
                    file << _listPlayer[i]->getStorage()(j, k)->getNama() << endl;
                }
            }
        }

        if (tipe == "Petani"){
            Farmer* temp = dynamic_cast<Farmer*>(_listPlayer[i]);

            file << temp->getLadang().getRow() * temp->getLadang().getCol() - temp->getLadang().getCellKosong() << std::endl;

            for (int j = 0; j < temp->getLadang().getRow(); j++){
                for (int k = 0; k < temp->getLadang().getCol(); k++){
                    if (temp->getLadang()(j, k) != nullptr){
                        file << idxToSlot(i, j) << " " << temp->getLadang()(j, k)->getNama() << " " << dynamic_cast<Plant*>(temp->getLadang()(j, k))->getAge() << std::endl;
                    }
                }
            }
        } else if (tipe == "Peternak"){
            Stockman* temp = dynamic_cast<Stockman*>(_listPlayer[i]);

            file << temp->getPeternakan().getRow() * temp->getPeternakan().getCol() - temp->getPeternakan().getCellKosong() << std::endl;

            for (int j = 0; j < temp->getPeternakan().getRow(); j++){
                for (int k = 0; k < temp->getPeternakan().getCol(); k++){
                    if (temp->getPeternakan()(j, k) != nullptr){
                        file << idxToSlot(i, j) << " " << temp->getPeternakan()(j, k)->getNama() << " " << dynamic_cast<Animal*>(temp->getPeternakan()(j, k))->getWeight() << std::endl;
                    }
                }
            }
        }
    }

    file << _listItemToko.size() << std::endl;

    for (auto & i : _listItemToko){
        file << i.first->getNama() << " " << i.second << std::endl;
    }

    cout << "State berhasil disimpan." << endl;

    file.close();
}

Item* StateManager::getItemByName(const string& name){
    for (auto & i : GameData::_productConfig){
        if ((i.getNama() )== name){
            return &i;
        }
    }

    for (auto & i : GameData::_animalConfig){
        if ((i.getNama() )== name){
            return new Animal(i.getId(), i.getCode(), i.getNama(), i.getHarga(), i.getType(), i.getWeight(), i.getHarvestLimit());
        }
    }

    for (auto & i : GameData::_plantConfig){
        if ((i.getNama() )== name){
            return new Plant(i.getId(), i.getCode(), i.getNama(), i.getHarga(), i.getType(), i.getHarvestLimit(), i.getAge());
        }
    }

    for (auto & i : GameData::_buildingConfig){
        if ((i.getNama() )== name){
            return &i;
        }
    }

    cout << name << "Item tidak ditemukan dalam game config." << endl;

    return nullptr;
}

string StateManager::idxToSlot(int i, int j){
    string slot;

    slot += (char)('A' + i);
    slot += std::to_string(j + 1);

    return slot;
}
