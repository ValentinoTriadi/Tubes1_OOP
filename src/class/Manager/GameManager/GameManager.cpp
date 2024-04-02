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
    this->_gameData.BacaConfigAnimal();
    this->_gameData.BacaConfigBuilding();
    this->_gameData.BacaConfigPlant();
    this->_gameData.BacaConfigProduct();
    this->_gameData.BacaConfigGame();

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
    StateManager::loadState();
    // TODO : set game state
}

void GameManager::AddUser(int type)
{
    try {
        if (type == 1)
        {
            auto* temp_mayor = new Mayor("Mayor",40, 40 , gameConfig[2], gameConfig[3]);
            this->_listPlayer.add(temp_mayor);
        } else if (type == 2) {
            auto* temp_farmer = new Farmer("Petani1",40, 40, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
            this->_listPlayer.add(temp_farmer);
        } else if (type == 3) {
            auto* temp_stockman = new Stockman("Peternak1",40, 40, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]);
            this->_listPlayer.add(temp_stockman);
        } else {
            throw AddUserException();
        }
    } catch (AddUserException &e) {
        cout << e.what() << endl;
    }
}

void GameManager::StartGameValidation()
{
    InputManager::NewGameInput();

    string data = InputManager::_inputData<string>;
    if (data == "1")
    {
        StartNewGame();
    }
    else if (data == "2")
    {
        ContinueGame();
    }
    else
    {
        cout << "Input Invalid! Please enter either 1 or 2" << endl;
        StartGameValidation();
    }
}

void GameManager::WinCheck()
{
    auto weight = float(_currentPlayer->GetWeight());
    int money = _currentPlayer->GetKeuangan();

    if (weight >= this->_weightToWin && money >= this->_moneyToWin)
    {
        cout << weight << " " << _weightToWin << endl;
        cout << money << " " << _moneyToWin << endl;
        GameManager::EndGame();
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
    try {
        switch (type) {
            case (1):
                InputManager::MayorMenuInputValidation();
                RunMayorSelection(stoi(InputManager::_inputData<string>));
                break;
            case (2):
                InputManager::FarmerMenuInputValidation();
                RunFarmerSelection(stoi(InputManager::_inputData<string>));
                break;
            case (3):
                InputManager::StockmanMenuInputValidation();
                RunStockmanSelection(stoi(InputManager::_inputData<string>));
                break;
            default:
                throw MenuException();
        }
    } catch (MenuException &e) {
        cout << e.what() << endl;
        MenuSelection(type);
    }

}

void GameManager::RunStockmanSelection(int input){
    switch (input) {
        case 1:
            _currentPlayer->cetakPenyimpanan();
            break;
        case 2:
            if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer)) {
                stockman->ternak();
            } else {
                throw PeopleException();
            }
            break;
        case 3:
            _currentPlayer->makan();
            break;
        case 4:
            if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer)) {
                stockman->memberiPangan();
            } else {
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
            if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer)) {
                stockman->panen();
            } else {
                throw PeopleException();
            }
            break;
        case 8:
            muat();
            break;
        case 9:

            break;
        case 10:
            nextTurn();
            break;
        default:
            throw RunException();
    }
}

void GameManager::RunMayorSelection(int input) {
    switch (input) {
        case 1:
            _currentPlayer->cetakPenyimpanan();
            break;
        case 2:
            pungutPajak();
            break;
        case 3:
            if (auto *mayor = dynamic_cast<Mayor *>(_currentPlayer)) {
                mayor->bangun();
            } else {
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
            if (auto *mayor = dynamic_cast<Mayor *>(_currentPlayer)) {
                mayor->tambahPemain(&_listPlayer);
            } else {
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

void GameManager::RunFarmerSelection(int input){
    switch (input) {
        case 1:
            if (auto *farmer = dynamic_cast<Farmer *>(_currentPlayer)) {
                farmer->tanam();
            } else {
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
            if (auto *farmer = dynamic_cast<Farmer *>(_currentPlayer)) {
                farmer->panen();
            } else {
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


void GameManager::Run() {
    StartGameValidation();
    StartTurn();
    while (!_isGameOver)
    {
        MenuSelection(_currentPlayer->GetType());
        WinCheck();
    }
}

void GameManager::pungutPajak() {
    int total = 0;

}

void GameManager::muat() {
    StateManager::loadState();
}

void GameManager::simpan() {

}
