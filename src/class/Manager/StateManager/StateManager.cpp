#include "StateManager.hpp"
#include <filesystem>

vector<People *> StateManager::_listPlayer;

map<Item *, int> StateManager::_listItemToko;

StateManager::StateManager() = default;

StateManager::~StateManager() = default;

void StateManager::defaultState(){}

void StateManager::loadState(){

    bool input = InputManager::receiveBooleanInput("Apakah anda ingin memuat state dari file? (y/n) : ");

    if (input){
        loadFromFile();
    } else {
        throw BackToMenuState();
    }
}

Farmer *StateManager::readFarmer(ifstream &file, string name, int money, int weight, vector<int> gameConfig)
{
    Farmer *farmer = new Farmer(name, weight, money, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
    int countItems, plantCount;

    file >> countItems;

    Container *inventory = new Container(gameConfig[2], gameConfig[3]);

    int row = 0, col = 0;
    for (int i = 0; i < countItems; i++)
    {
        file >> name;
        inventory->setItem(row, col++, getItemByName(name));

        if (col == gameConfig[3])
        {
            col = 0;
            row++;
        }
    }

    file >> plantCount;

    Ladang *ladang = new Ladang(gameConfig[4], gameConfig[5]);

    string slot, plantName;
    int age;


    for (int i = 0; i < plantCount; i++){

        file >> slot >> plantName >> age;

        Plant *plant = dynamic_cast<Plant *>(getItemByName(plantName));
        plant->setAge(age);
        ladang->setItem(slot, plant);
    }

    farmer->setLadang(*ladang);
    farmer->setStorage(*inventory);

    return farmer;
}

Stockman *StateManager::readStockman(ifstream &file, string name, int money, int weight, vector<int> gameConfig)
{
    Stockman *stockman = new Stockman(name, weight, money, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
    int countItems, countAnimal;

    file >> countItems;

    Container *inventory = new Container(gameConfig[2], gameConfig[3]);

    int row = 0, col = 0;
    for (int i = 0; i < countItems; i++)
    {
        string name;
        file >> name;
        inventory->setItem(row, col++, getItemByName(name));

        if (col == gameConfig[3])
        {
            col = 0;
            row++;
        }
    }

    file >> countAnimal;

    Peternakan *peternakan = new Peternakan(gameConfig[4], gameConfig[5]);

    string slot, animalName;
    int weightAnimal;


    for (int i = 0; i < countAnimal; i++){
        file >> slot >> name >> weightAnimal;
        Animal *animal = dynamic_cast<Animal *>(getItemByName(name));
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

    Container *inventory = new Container(gameConfig[2], gameConfig[3]);

    int row = 0, col = 0;
    for (int i = 0; i < countItems; i++)
    {
        file >> name;
        inventory->setItem(row, col++, getItemByName(name));

        if (col == gameConfig[3])
        {
            col = 0;
            row++;
        }
    }

    mayor->setStorage(*inventory);

    return mayor;
}

void StateManager::readShop(ifstream &file)
{
    int countItems;

    file >> countItems;

    for (int i = 0; i < countItems; i++)
    {
        string name;
        int stock;

        file >> name >> stock;
        _listItemToko[getItemByName(name)] = stock;
    }
}

void StateManager::loadFromFile(){

    InputManager::receiveInput("Masukkan lokasi berkas state : ");
    string filename = InputManager::_inputDataString;

    ifstream file("save/" + filename);

    while (!file.is_open()){
        InputManager::receiveInput("Berkas tidak valid. Silakan masukkan lokasi berkas yang valid: ");
        filename = InputManager::_inputDataString;
        file.open("save/" + filename);
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


void StateManager::saveState() {
    InputManager::receiveInput("Masukkan lokasi berkas state : ");
    string userInput = InputManager::_inputDataString;
    string path = "save/" + userInput;

    filesystem::path pathObj(userInput);
    string directory = "save/" + pathObj.parent_path().string();

    // Create the directory if it doesn't exist
    if (!filesystem::exists(directory)) {
        filesystem::create_directories(directory);
    }

    ofstream file(path);

    vector<People*> _listPlayer = StateManager::_listPlayer;

    file << _listPlayer.size() << "\n";
    for (People *player : _listPlayer) {
        string tipe = player->GetType() == 1 ? "Walikota" : player->GetType() == 2 ? "Petani" : "Peternak";
        file << player->GetName() << " " << tipe << " " << player->GetKeuangan() << " " << player->GetWeight() << "\n";
        file << player->getStorage().getRow() * player->getStorage().getCol() - player->getStorage().getCellKosong() << "\n";


        for (int j = 0; j < player->getStorage().getRow(); j++) {
            for (int k = 0; k < player->getStorage().getCol(); k++) {
                if (player->getStorage()(j, k) != nullptr) {
                    file << player->getStorage()(j, k)->getNama() << "\n";
                }
            }
        }

        if (Farmer* temp = dynamic_cast<Farmer*>(player)) {
            saveLadang(file, temp);
        } else if (Stockman* temp = dynamic_cast<Stockman*>(player)) {
            savePeternakan(file, temp);
        }
    }

    file << _listItemToko.size() << "\n";
    for (std::pair<Item *const, int> &i : _listItemToko) {
        file << i.first->getNama() << " " << i.second << "\n";
    }

    cout << "State berhasil disimpan.\n";
    file.close();
}


void StateManager::saveLadang(ofstream& file, Farmer* temp) {
    file << temp->getLadang().getRow() * temp->getLadang().getCol() - temp->getLadang().getCellKosong() << "\n";
    for (int j = 0; j < temp->getLadang().getRow(); j++) {
        for (int k = 0; k < temp->getLadang().getCol(); k++) {
            if (temp->getLadang()(j, k) != nullptr) {
                file << idxToSlot(j, k) << " " << temp->getLadang()(j, k)->getNama() << " " << dynamic_cast<Plant*>(temp->getLadang()(j, k))->getAge() << "\n";
            }
        }
    }
}


void StateManager::savePeternakan(ofstream& file, Stockman* temp) {
    file << temp->getPeternakan().getRow() * temp->getPeternakan().getCol() - temp->getPeternakan().getCellKosong() << "\n";
    for (int j = 0; j < temp->getPeternakan().getRow(); j++) {
        for (int k = 0; k < temp->getPeternakan().getCol(); k++) {
            if (temp->getPeternakan()(j, k) != nullptr) {
                file << idxToSlot(j, k) << " " << temp->getPeternakan()(j, k)->getNama() << " " << dynamic_cast<Animal*>(temp->getPeternakan()(j, k))->getWeight() << "\n";
            }
        }
    }
}

Item *StateManager::getItemByName(const string &name)
{
    for (Product &i : GameData::_productConfig)
    {
        if ((i.getNama()) == name)
        {
            return &i;
        }
    }

    for (Animal &i : GameData::_animalConfig)
    {
        if ((i.getNama()) == name)
        {
            return new Animal(i.getId(), i.getCode(), i.getNama(), i.getHarga(), i.getType(), i.getHarvestLimit(), i.getWeight());
        }
    }

    for (Plant &i : GameData::_plantConfig)
    {
        if ((i.getNama()) == name)
        {
            return new Plant(i.getId(), i.getCode(), i.getNama(), i.getHarga(), i.getType(), i.getHarvestLimit(), i.getAge());
        }
    }

    for (Building &i : GameData::_buildingConfig)
    {
        if ((i.getNama()) == name)
        {
            return &i;
        }
    }

    cout << name << "Item tidak ditemukan dalam game config." << endl;

    return nullptr;
}

string StateManager::idxToSlot(int i, int j)
{
    string slot;

    slot += (char)('A' + i);
    slot += std::to_string(j + 1);

    return slot;
}
