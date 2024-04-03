#include "GameManager.hpp"

using namespace std;

bool GameManager::_isGameOver = false;

void GameManager::StartNewGame()
{
    this->ReadConfig();

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

GameManager::GameManager() = default;

GameManager::~GameManager()
{
    _listPlayer.clear();
}

void GameManager::ContinueGame()
{
    this->ReadConfig();
    muat();
}

void GameManager::AddUser(int type)
{
    try
    {
        if (type == 1)
        {
            auto *temp_mayor = new Mayor("Mayor", 40, 40, gameConfig[2], gameConfig[3]);
            this->_listPlayer.add(temp_mayor);
        }
        else if (type == 2)
        {
            auto *temp_farmer = new Farmer("Petani1", 40, 40, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
            this->_listPlayer.add(temp_farmer);
        }
        else if (type == 3)
        {
            auto *temp_stockman = new Stockman("Peternak1", 40, 40, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]);
            this->_listPlayer.add(temp_stockman);
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
    InputManager::NewGameInput();

    int data = InputManager::_inputData<int>;
    if (data == 1)
    {
        StartNewGame();
    }
    else
    {
        ContinueGame();
    }
}

void GameManager::WinCheck()
{
    for (auto &player : _listPlayer)
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
    this->_currentPlayer = _listPlayer.top();
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
    switch (input)
    {
    case 1:
        _currentPlayer->cetakPenyimpanan();
        break;
    case 2:
        if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer))
        {
            stockman->ternak();
        }
        else
        {
            throw PeopleException();
        }
        break;
    case 3:
        _currentPlayer->makan();
        break;
    case 4:
        if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer))
        {
            stockman->memberiPangan();
        }
        else
        {
            throw PeopleException();
        }
        break;
    case 5:
        _currentPlayer->membeli();

        break;
    case 6:
        _currentPlayer->menjual();
        break;
    case 7:
        if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer))
        {
            stockman->panen();
        }
        else
        {
            throw PeopleException();
        }
        break;
    case 8:
        muat();
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

void GameManager::RunMayorSelection(int input)
{
    switch (input)
    {
    case 1:
        _currentPlayer->cetakPenyimpanan();
        break;
    case 2:
        pungutPajak();
        break;
    case 3:
        if (auto *mayor = dynamic_cast<Mayor *>(_currentPlayer))
        {
            mayor->bangun();
        }
        else
        {
            throw PeopleException();
        }
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
        muat();
        break;
    case 8:
        simpan();
        break;
    case 9:
        if (auto *mayor = dynamic_cast<Mayor *>(_currentPlayer))
        {
            mayor->tambahPemain(&_listPlayer);
        }
        else
        {
            throw PeopleException();
        }
        break;
    case 10:
        nextTurn();
        break;
    default:
        throw RunException();
    }
}

void GameManager::RunFarmerSelection(int input)
{
    switch (input)
    {
    case 1:
        if (auto *farmer = dynamic_cast<Farmer *>(_currentPlayer))
        {
            farmer->tanam();
        }
        else
        {
            throw PeopleException();
        }
        break;
    case 2:
        _currentPlayer->cetakPenyimpanan();
        break;
    case 3:
        _currentPlayer->makan();
        break;
    case 4:
        _currentPlayer->membeli();
        break;
    case 5:
        _currentPlayer->menjual();
        break;
    case 6:
        if (auto *farmer = dynamic_cast<Farmer *>(_currentPlayer))
        {
            farmer->panen();
        }
        else
        {
            throw PeopleException();
        }
        break;
    case 7:
        muat();
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

void GameManager::Run()
{
    StartGameValidation();
    StartTurn();
    while (!_isGameOver)
    {
        MenuSelection(_currentPlayer->GetType());
        WinCheck();
    }
}

void GameManager::pungutPajak()
{
    int total = 0;
    for (auto &player : _listPlayer)
    {
    }
}

void GameManager::muat()
{
    StateManager::loadState();
    _listPlayer = StateManager::_listPlayer;

    // TODO : Implement load shop items
}

void GameManager::simpan()
{
    StateManager::saveState();
}
