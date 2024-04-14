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
    // User default settings 40 gulden, 40 weight
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
            Mayor *temp_mayor = new Mayor("Mayor", 40, 40, gameConfig[2], gameConfig[3]);
            GameManager::_listPlayer.add(temp_mayor);
        }
        else if (type == 2)
        {
            Farmer *temp_farmer = new Farmer("Petani1", 40, 40, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
            GameManager::_listPlayer.add(temp_farmer);
        }
        else if (type == 3)
        {
            Stockman *temp_stockman = new Stockman("Peternak1", 40, 40, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]);
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

        int data = InputManager::_inputData<int>;
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
    catch (InputException &e)
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
            RunMayorSelection(InputManager::_inputData<int>);
            break;
        case (2):
            InputManager::FarmerMenuInputValidation();
            RunFarmerSelection(InputManager::_inputData<int>);
            break;
        case (3):
            InputManager::StockmanMenuInputValidation();
            RunStockmanSelection(InputManager::_inputData<int>);
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
            break;
        case 2:
            _currentPlayer->cetakPenyimpanan();
            break;
        case 3:
            if (getCurrentSeason() == 4) {
                cout << "Musim dingin! Ternakmu Sedang berhibernasi! Tidak jadi ternak\n" << endl;
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
            _currentPlayer->menjual();
            break;
        case 8:
            stockman->panen();
            break;
        case 9:
            simpan();
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
            break;
        case 2:
            Mayor::TagihPajak(&_listPlayer, getCurrentSeason());
            break;
        case 3:
            if (getCurrentSeason() == 4) {
                cout << "Musim dingin! Kuli meminta kenaikan harga!\n" << endl;
                mayor->bangun(1.25);
                break;
            }
            mayor->bangun(1);
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
            break;
        case 2:
            farmer->cetakLadang();
            break;
        case 3:
            if (getCurrentSeason() == 4) {
                cout << "Tangan mu kedinginan! Kau tidak jadi menanam\n" << endl;
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
            _currentPlayer->menjual();
            break;
        case 7:
            farmer->panen();
            break;
        case 8:
            simpan();
            break;
        case 9:
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
    cout << "\n\n ===== Current Player Info ===== " << endl;
    cout << "current Season: ";

    if (getCurrentSeason() == 1)
    {
        cout << "Spring" << endl;
    }
    else if (getCurrentSeason() == 2)
    {
        cout << "Summer" << endl;
    }
    else if (getCurrentSeason() == 3)
    {
        cout << "Fall" << endl;
    }
    else if (getCurrentSeason() == 4)
    {
        cout << "Winter" << endl;
    }

    cout << "Player Name: " << _currentPlayer->GetName();
    cout << "\nOccupation: ";

    if (_currentPlayer->GetType() == 1)
    {
        cout << "Mayor" << endl;
    }
    else if (_currentPlayer->GetType() == 2)
    {
        cout << "Farmer" << endl;
    }
    else if (_currentPlayer->GetType() == 3)
    {
        cout << "Stockman" << endl;
    }

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
    StateManager::saveState();
}

