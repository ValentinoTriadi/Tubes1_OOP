#include "GameManager.hpp"

using namespace std;

roundRobin<People *> GameManager::_listPlayer;
roundRobin<int> GameManager::_seasons;
bool GameManager::_isGameOver = false;

void GameManager::StartNewGame()
{
    this->ReadConfig();
    _toko = Toko();

    // Add user to the list player
    // User default settings 50 gulden, 40 weight
    for (int i = 1; i <= 3; i++)
    {
        this->AddUser(i);
    }
}

void GameManager::ReadConfig()
{
    GameData::BacaConfigAnimal();
    GameData::BacaConfigBuilding();
    GameData::BacaConfigPlant();
    GameData::BacaConfigProduct();
    GameData::BacaConfigGame();

    // Save local settings for win conditions
    gameConfig = GameData::_gameConfig;

    this->_moneyToWin = gameConfig[0];
    this->_weightToWin = float(gameConfig[1]);
}

GameManager::GameManager(){
    _seasons.add(1);
    _seasons.add(2);
    _seasons.add(3);
    _seasons.add(4);
};

GameManager::~GameManager()
{
    _listPlayer.clear();
}

void GameManager::ContinueGame()
{
    this->ReadConfig();
    try
    {
        muat();
    }
    catch (BackToMenuState &e)
    {
        throw;
    }
}

void GameManager::AddUser(int type)
{
    try
    {
        if (type == 1)
        {
            Mayor *temp_mayor = new Mayor("Mayor", 40, 50, gameConfig[2], gameConfig[3]);
            GameManager::_listPlayer.add(temp_mayor);
        }
        else if (type == 2)
        {
            Farmer *temp_farmer = new Farmer("Petani1", 40, 50, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
            GameManager::_listPlayer.add(temp_farmer);
        }
        else if (type == 3)
        {
            Stockman *temp_stockman = new Stockman("Peternak1", 40, 50, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]);
            GameManager::_listPlayer.add(temp_stockman);
        }
        else
        {
            throw AddUserException();
        }
    }
    catch (AddUserException &e)
    {
        cout << e.what() << endl;
    }
}

void GameManager::StartGameValidation()
{
    try
    {
        InputManager::NewGameInput();

        int data = InputManager::_inputDataInt;
        if (data == 1)
        {
            StartNewGame();
        }
        else
        {
            try
            {
                ContinueGame();
            }
            catch (BackToMenuState &e)
            {
                cout << e.what() << endl;
                StartGameValidation();
            }
        }
    }
    catch (InputException e)
    {
        cout << e.what() << endl;
        StartGameValidation();
    }
}

void GameManager::WinCheck()
{
    for (People *player : _listPlayer)
    {
        if (player->GetKeuangan() >= _moneyToWin && player->GetWeight() >= _weightToWin)
        {
            cout << "Player " << player->GetName() << " has won the game!" << endl;
            EndGame();
        }
    }
}

void GameManager::EndGame()
{
    cout << endl
         << "Game Over" << endl;
    _isGameOver = true;
}

void GameManager::nextTurn()
{
    _listPlayer.next();
    std::cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    this->_currentPlayer = _listPlayer.top();
    // change season
    if (_currentPlayer->GetType() == 1){
        _seasons.next();
    }
    // Kalau Fall tanaman ga tumbuh
    if (getCurrentSeason() != 3){
        addAge();
    }else{
        cout << "Musim Fall Sedang berlangsung, umur tumbuhan tidak akan bertambah!!" << endl;
    }
}

void GameManager::addAge()
{
    for (People *player : _listPlayer)
    {
        // If the player is a farmer, add the plant age
        if (player->GetType() == 2)
        {
            Farmer *farmer = dynamic_cast<Farmer *>(player);
            farmer->addPlantAge();
            // Kalau Spring tanaman tumbuh 2x
            if (getCurrentSeason() == 1){
                cout << "Musim Spring sedang berjalan, umur tumbuhan bertambah 2" << endl; 
                farmer->addPlantAge();
            }
        }
    }
}

void GameManager::StartTurn()
{
    this->_currentPlayer = _listPlayer.top();
}

void GameManager::MenuSelection(int type)
{
    try
    {
        switch (type)
        {
        case (1):
            InputManager::MayorMenuInputValidation();
            RunMayorSelection(InputManager::_inputDataInt);
            break;
        case (2):
            InputManager::FarmerMenuInputValidation();
            RunFarmerSelection(InputManager::_inputDataInt);
            break;
        case (3):
            InputManager::StockmanMenuInputValidation();
            RunStockmanSelection(InputManager::_inputDataInt);
            break;
        default:
            throw MenuException();
        }
    }
    catch (MenuException &e)
    {
        cout << e.what() << endl;
        MenuSelection(type);
    }
}

void GameManager::RunStockmanSelection(int input)
{
    try
    {
        // Casting ke Stockman
        Stockman *stockman = dynamic_cast<Stockman *>(_currentPlayer);
        if (stockman == nullptr)
        {
            throw PeopleException();
        }
        switch (input)
        {
        case 1:
            stockman->cetakPeternakan();
            stockman->getPeternakan().showAnimal();
            break;
        case 2:
            _currentPlayer->cetakPenyimpanan();
            cout << "\nTotal Slot kosong: "<< _currentPlayer->getStorage().getCellKosong() << endl;
            break;
        case 3:
            if (getCurrentSeason() == 4) {
                cout << "Musim dingin tiba, Ternakmu Sedang berhibernasi! Tidak bisa ternak\n" << endl;
                break;
            }
            stockman->ternak();
            break;
        case 4:
            _currentPlayer->makan();
            break;
        case 5:
            stockman->memberiPangan(getCurrentSeason());
            break;
        case 6:
            _currentPlayer->membeli();
            break;
        case 7:
            if(getCurrentSeason() == 2){
                _currentPlayer->menjual(2);
            }
            else{
                _currentPlayer->menjual();
            }
            break;
        case 8:
            stockman->panen();
            break;
        case 9:
            simpan();
            break;
        case 10:
            infoSeason();
            break;
        case 11:
            nextTurn();
            break;
        default:
            throw RunException();
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
}

void GameManager::RunMayorSelection(int input)
{
    try
    {
        Mayor *mayor = dynamic_cast<Mayor *>(_currentPlayer);
        if (mayor == nullptr)
        {
            throw PeopleException();
        }
        switch (input)
        {
        case 1:
            _currentPlayer->cetakPenyimpanan();
            cout << "\nTotal Slot kosong: "<< _currentPlayer->getStorage().getCellKosong() << endl;
            break;
        case 2:
            mayor->TagihPajak(&_listPlayer, getCurrentSeason());
            break;
        case 3:
            mayor->bangun();
            break;
        case 4:
            _currentPlayer->makan();
            break;
        case 5:
            _currentPlayer->membeli();
            break;
        case 6:
            _currentPlayer->menjual();
            break;
        case 7:
            simpan();
            break;
        case 8:
            mayor->tambahPemain(&_listPlayer);
            break;
        case 9:
            infoSeason();
            break;
        case 10:
            nextTurn();
            break;
        default:
            throw RunException();
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
}

void GameManager::RunFarmerSelection(int input)
{
    try
    {
        Farmer *farmer = dynamic_cast<Farmer *>(_currentPlayer);
        if (farmer == nullptr)
        {
            throw PeopleException();
        }
        switch (input)
        {
        case 1:
            _currentPlayer->cetakPenyimpanan();
            cout << "\nTotal Slot kosong: "<< _currentPlayer->getStorage().getCellKosong() << endl;
            break;
        case 2:
            farmer->cetakLadang();
            farmer->getLadang().showPlant();
            break;
        case 3:
            if (getCurrentSeason() == 4) {
                cout << "Sedang musim winter, Tangan mu kedinginan! Kau tidak bisa menanam\n" << endl;
                break;
            }
            farmer->tanam();
            break;
        case 4:
            _currentPlayer->makan();
            break;
        case 5:
            _currentPlayer->membeli();
            break;
        case 6:
            if(getCurrentSeason() == 2){
                _currentPlayer->menjual(2);
            }
            else{
                _currentPlayer->menjual();
            }
            break;
        case 7:
            farmer->panen();
            break;
        case 8:
            simpan();
            break;
        case 9:
            infoSeason();
            break;
        case 10:
            nextTurn();
            break;
        default:
            throw RunException();
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
}

void GameManager::Run()
{
    StartGameValidation();
    StartTurn();
    while (!_isGameOver)
    {
        // Show player Name, Occupation, Money, Weight
        ShowCurrentPlayerInfo();
        MenuSelection(_currentPlayer->GetType());
        WinCheck();
    }
}

void GameManager::ShowCurrentPlayerInfo()
{
    // switch (_currentPlayer->GetType())
    // {
    //     case 1:
    //         cout;
    //         break;
    //     case 2:
    //         cout;
    //         break;
    //     case 3:
    //         cout;
    //         break;
    //     default:
    //         break;
    // }
    cout << "\n\n===== Current Player Info ===== " << endl;
    cout << "Current Season: ";

    switch (getCurrentSeason())
    {
        case 1:
            cout << "\e[32m" << "Spring" << endl;
            break;
        case 2:
            cout << "\e[33m" << "Summer" << endl;
            break;
        case 3:
            cout << "\e[31m" << "Fall" << endl;
            break;
        case 4:
            cout << "\e[36m" << "Winter" << endl;
            break;
        default:
            break;
    }

    cout << "\e[0m";
    cout << "Player Name: " << _currentPlayer->GetName();
    cout << "\nOccupation: ";

    switch (_currentPlayer->GetType())
    {
        case 1:
            cout << "\e[35m" << "Mayor" << endl;
            break;
        case 2:
            cout << "\e[32m" << "Farmer" << endl;
            break;
        case 3:
            cout << "\e[34m" << "Stockman" << endl;
            break;
        default:
            break;
    }
    cout << "\e[0m";
    cout << "Money: " << _currentPlayer->GetKeuangan();
    cout << "\nWeight: " << _currentPlayer->GetWeight() << endl
         << endl;
}

void GameManager::muat()
{
    _toko = Toko();
    StateManager::loadState();
    _listPlayer = StateManager::_listPlayer;
    Toko::tambahListItems(StateManager::_listItemToko);
}

void GameManager::simpan()
{
    StateManager::_listPlayer = _listPlayer.getBuffer();
    StateManager::_listItemToko = Toko::getListToko();
    StateManager::saveState();
}


void GameManager::infoSeason(){
    int currSeason = getCurrentSeason();
    switch (currSeason){
        case 1:
            cout << "\e[32m" << "=========================[ Spring ]==========================\n"
                 << "- Farmer   : Pertumbuhan tumbuhan meningkat menjadi 2x lebih cepat\n"
                 << "- Mayor    : Pajak yang ditarik turun menjadi 75%\n"
                 << "- Stockman : Penambahan berat hewan meningkat menjadi 2x lipat\n" << "\e[0m";
            break;
        case 2:
            cout << "\e[33m" << "=========================[ Summer ]==========================\n"
                 << "- Farmer   : Harga jual produk menjadi 2x lipat\n"
                 << "- Stockman : Harga jual produk menjadi 2x lipat\n" << "\e[0m";
            break;
        case 3:
            cout << "\e[31m" << "=========================[ Fall ]==========================\n"
                 << "- Farmer   : Tumbuhan tidak mengalami pertumbuhan\n"
                 << "- Mayor    : Pajak yang ditarik naik menjadi 125%\n"
                 << "- Stockman : Penambahan berat hewan menurun menjadi 50%\n" << "\e[0m";
            break;
        case 4:
            cout << "\e[36m" << "=========================[ Winter ]==========================\n"
                 << "- Farmer   : Tidak bisa menanam\n"
                 << "- Stockman : Tidak bisa beternak\n" << "\e[0m";
            break;
        default:
            break;
    }

}