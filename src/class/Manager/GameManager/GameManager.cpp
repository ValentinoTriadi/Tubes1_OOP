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
    // TODO: implement State Config reader
    // TODO: create exception if the state is inavailable
}

void GameManager::AddUser(int type)
{
    if (type == 1)
    {
        // TODO: Assign mayor to the list player
        auto* temp_mayor = new Mayor(40, 40, type , gameConfig[2], gameConfig[3]);
        this->_listPlayer.push_back(temp_mayor);
    } else if (type == 2) {
        // TODO: assign farmer to the list player
        auto* temp_farmer = new Farmer(40, 40, type, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]);
        this->_listPlayer.push_back(temp_farmer);
    } else if (type == 3) {
        // TODO: assign stockman to the list player
        auto* temp_stockman = new Stockman(40, 40, type, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]);
        this->_listPlayer.push_back(temp_stockman);
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

    switch (type)
    {
    case (1):
        MayorMenuSelection();
        break;
    case (2):
        FarmerMenuSelection();
        break;
    case (3):
        StockmanMenuSelection();
        break;
    default:
        // Throw exception
        break;
    }
}

void GameManager::MayorMenuSelection()
{
    cout << "Menu Selection: " << endl;
    cout << "(1): "
         << "Cetak Penyimpanan" << endl;
    cout << "(2): "
         << "Pungut Pajak" << endl;
    cout << "(3): "
         << "Bangun Bangunan" << endl;
    cout << "(4): "
         << "Makan" << endl;
    cout << "(5): "
         << "Beli" << endl;
    cout << "(6): "
         << "Jual" << endl;
    cout << "(7): "
         << "Muat" << endl;
    cout << "(8): "
         << "Simpan" << endl;
    cout << "(9): "
         << "Tambah Pemain" << endl;

    try {
        int data;
        cout << "Pilihan: ";
        cin >> data;
        cout << endl;

        if (data < 1 || data > 9) {
            // TODO: implement data input exception
        }

        // Jalankan fungsi sesuai dengan pilihan
        RunMayorSelection(data);
    }
    catch (const exception &e) // TODO: replace with expection
    {
        // TODO: implement input exception
        cout << e.what() << endl;
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
                // Exception for invalid type
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
//           muat();
            break;
        case 8:
//           simpan();
            break;
        case 9:
            if (auto *mayor = dynamic_cast<Mayor *>(_currentPlayer)) {
                mayor->tambahPemain();
            } else {
                // Exception for invalid type
            }
            break;
        default:
            // Exception
            break;
    }
}

void GameManager::StockmanMenuSelection() {
    cout << "Menu Selection: " << endl;
    cout << "(1): "
         << "Cetak Peternakan" << endl;
    cout << "(2): "
         << "Ternak" << endl;
    cout << "(3): "
         << "Makan" << endl;
    cout << "(4): "
         << "Memberi Pangan" << endl;
    cout << "(5): "
         << "Membeli" << endl;
    cout << "(6): "
         << "Menjual" << endl;
    cout << "(7): "
         << "Memanen" << endl;
    cout << "(8): "
         << "Muat" << endl;
    cout << "(9): "
         << "Simpan" << endl;

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

        // Jalankan fungsi sesuai dengan pilihan
        RunStockmanSelection(data);
    }
    catch (MenuException e)
    {
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
                // Exception for invalid type
            }
            break;
        case 3:
            _currentPlayer->makan();
            break;
        case 4:
            if (auto *stockman = dynamic_cast<Stockman *>(_currentPlayer)) {
                stockman->memberiPangan();
            } else {
                // Exception for invalid type
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
                // Exception for invalid type
            }
            break;
        case 8:
            // muat();
            break;
        case 9:
            // simpan();
            break;
        default:
            // Exception
            break;
    }
}

void GameManager::FarmerMenuSelection()
{
    cout << "Menu Selection: " << endl;
    cout << "(1): "
         << "Tanam" << endl;
    cout << "(2): "
         << "Cetak Ladang" << endl;
    cout << "(3): "
         << "Makan" << endl;
    cout << "(4): "
         << "Membeli" << endl;
    cout << "(5): "
         << "Menjual" << endl;
    cout << "(6): "
         << "Memanen" << endl;
    cout << "(7): "
         << "Muat" << endl;
    cout << "(8): "
         << "Simpan" << endl;

    try
    {
        int data;
        cout << "Pilihan: ";
        cin >> data;

        if (data < 1 || data > 8)
        {
            // TODO: implement data input exception
        }

        // Jalankan fungsi sesuai dengan pilihan
        RunFarmerSelection(data);
    }
    catch (const exception &e) // TODO: replace with expection
    {
        // TODO: implement input exception
        cout << e.what() << endl;
    }
}

void GameManager::RunFarmerSelection(int input){
    switch (input) {
        case 1:
            if (auto *farmer = dynamic_cast<Farmer *>(_currentPlayer)) {
                farmer->tanam();
            } else {
                // Exception for invalid type
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
                // Exception for invalid type
            }
            break;
        case 7:
            // muat();
            break;
        case 8:
            // simpan();
            break;
        default:
            // Exception
            break;
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
    for (auto & i : _listPlayer)
    {
        if (i->GetType() != 1){

        }
    }

}