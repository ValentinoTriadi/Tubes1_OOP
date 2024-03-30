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
        Stockman temp_stockman;
        this->_listPlayer.push_back(&temp_stockman);
    }
    else
    {
        // TODO: implement exception for add user
    }
}

void GameManager::StartGameValidation()
{
    cout << "Please enter a valid input" << endl;
    cout << "1. input (1) jika ingin buat game baru" << endl;
    cout << "2. input (2) jika ingin membaca berkas" << endl
         << endl;
    string data;
    cin >> data;
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
        cout << "Invalid Input" << endl;
        StartGameValidation();
    }
}

void GameManager::WinCheck()
{
    vector<People *>::iterator itr;
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
    cout << "Game Over" << endl;
    // TODO: implement stop all of the loops logic
}

void GameManager::nextTurn()
{
}

void GameManager::StartTurn()
{
    this->_currentPlayer = _listPlayer[0];
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
    }
}

void GameManager::MayorMenuSelection()
{
    // cout << "Menu Selection: "<< endl;
    // cout << "(1): "<<"Nyetak Simpenan"<<endl;
    // cout << "(2): "<<"Mungut Pajak"<<endl;
    // cout << "(3): "<<"Mangun Bangunan"<<endl;
    // cout << "(4): "<<"Dhahar"<<endl;
    // cout << "(5): "<<"Tumbas"<<endl;
    // cout << "(6): "<<"Dodolan"<<endl;
    // cout << "(7): "<<"Ngleboke"<<endl;
    // cout << "(8): "<<"Nyimpen"<<endl;

    cout << "Menu Selection: " << endl;
    cout << "(1): "
         << "Cetak Simpanan" << endl;
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

    try
    {
        int data;
        cout << "Pilihan: ";
        cin >> data;

        if (data < 1 && data > 9)
        {
            // TODO: implement data input exception
        }
    }
    catch (const exception &e) // TODO: replace with expection
    {
        // TODO: implement input exception
        cout << e.what() << endl;
    }
}

void GameManager::StockmanMenuSelection()
{
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
        int data;
        cout << "Pilihan: ";
        cin >> data;

        if (data < 1 && data > 9)
        {
            // TODO: implement data input exception
        }
    }
    catch (const exception &e) // TODO: replace with expection
    {
        // TODO: implement input exception
        cout << e.what() << endl;
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

        if (data < 1 && data > 8)
        {
            // TODO: implement data input exception
        }
    }
    catch (const exception &e) // TODO: replace with expection
    {
        // TODO: implement input exception
        cout << e.what() << endl;
    }
}