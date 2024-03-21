#include "GameManager.hpp"

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
    vector<int> data = _gameData.GetGameConfig();
    this->_moneyToWin = data[0];
    this->_weightToWin = data[1];
}

GameManager::GameManager() = default;

GameManager::~GameManager() = default;

void GameManager::ContinueGame()
{
    this->ReadConfig();
    // TODO: implement State Config reader
    // TODO: create exception if the state is inavailable
}

void GameManager::ReadInput(string data)
{
    this->_inputChecker = data;
}

string GameManager::GetInputChecker()
{
    return this->_inputChecker;
}

void GameManager::AddUser(int weight, int Keuangan, int type)
{
    if (type == 1)
    {
        // TODO: Assign mayor to the list player
    }
    else if (type == 2)
    {
        // TODO: assign farmer to the list player
        Farmer temp_farmer;
        this->_listPlayer.push_back(&temp_farmer);
    }
    else if (type == 3)
    {
        // TODO: assign stockman to the list player
        vector<int> tempGameDate = _gameData.GetGameConfig();
        Stockman temp_stockman(weight, Keuangan, type, tempGameDate[2], tempGameDate[3], tempGameDate[6], tempGameDate[7]);
        this->_listPlayer.push_back(&temp_stockman);
    }
    else
    {
        // TODO: implement exception for add user
    }
}

void GameManager::StartGameValidation()
{
    if (_inputChecker == "1")
    {
        StartNewGame();
    }
    else if (_inputChecker == "2")
    {
        ContinueGame();
    }
    else
    {
        std::cout << "Invalid Input" << endl;
        std::cout << "Please enter a valid input" << endl;
        cout << "1. input (1) jika ingin buat game baru" << endl;
        cout << "2. input (2) jika ingin membaca berkas" << endl
             << endl;
        string data;
        std::cin >> data;
        this->ReadInput(data);
        StartGameValidation();
    }
}

void GameManager::WinCheck()
{
    std::vector<People *>::iterator itr;
    for (itr = _listPlayer.begin(); itr != _listPlayer.end(); ++itr)
    {
        if (*itr)
        {
            float weight = (*itr)->GetWeight();
            float money = (*itr)->GetKeuangan();

            if (weight >= this->_weightToWin && money >= this->_moneyToWin)
            {
                // End the game
                this->EndGame();
            }
        }
    }
}

void GameManager::EndGame()
{
    std::cout << "Game Over" << endl;
    // TODO: implement stop all of the loops logic
}

void GameManager::nextTurn()
{

}

void GameManager::StartTurn()
{
    this->_currentPlayer = _listPlayer[0];
}

void GameManager::MenuSelection(const int type){
    switch(type){
        case(1) : 
            
    }
}
