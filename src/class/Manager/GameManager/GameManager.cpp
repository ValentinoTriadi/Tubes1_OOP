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
        this->AddUser(40, 40, i);
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
    // TODO: implement State Config reader
    // TODO: create exception if the state is inavailable
}

void GameManager::AddUser(int weight, int Keuangan, int type)
{
    if (type == 1)
    {
        // TODO: Assign mayor to the list player
        auto* temp_mayor = new Mayor("Mayor",40, 40, type , gameConfig[2], gameConfig[3]);
        this->_listPlayer.add(temp_mayor);
    } else if (type == 2) {
        // TODO: assign farmer to the list player
        auto* temp_farmer = new Farmer("Petani1",40, 40, type, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
        this->_listPlayer.add(temp_farmer);
    } else if (type == 3) {
        // TODO: assign stockman to the list player
        auto* temp_stockman = new Stockman("Peternak1",40, 40, type, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]);
        this->_listPlayer.add(temp_stockman);
    } else {
        // TODO: implement exception for add user
    }
}

void GameManager::StartGameValidation()
{
    InputManager::NewGameInput();

    string data = InputManager::_inputData;
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
    float weight = float(_currentPlayer->GetWeight());
    int money = _currentPlayer->GetKeuangan();

    if (weight >= this->_weightToWin && money >= this->_moneyToWin)
    {
        cout << weight << " " << _weightToWin << endl;
        cout << money << " " << _moneyToWin << endl;
        // End the game
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

void GameManager::MenuSelection(const int type)
{
    try
    {
        switch (type)
        {
        case (1):
            InputManager::MayorMenuInputValidation();
            break;
        case (2):
            InputManager::FarmerMenuInputValidation();
            break;
        case (3):
            InputManager::StockmanMenuInputValidation();
            break;
        default:
            // Throw exception
            cout << "Error Type occured" << endl;
            break;
        }
    }
    catch (MenuException e)
    {
        cout << e.what() << endl;
        MenuSelection(type);
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

void GameManager::pungutPajak() {
    int total = 0;

}
