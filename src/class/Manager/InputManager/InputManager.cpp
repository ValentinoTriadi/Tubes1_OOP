#include <iostream>
#include <string>
#include <algorithm>
#include "InputManager.hpp"
#include <fstream>

InputManager::InputManager() = default;
ifstream InputManager::_file_data;


template <typename T>
T InputManager::_inputData;

std::vector<std::string> InputManager::yes = {
        "true",
        "yes",
        "y",
        "1",
        "ya",
        "benar",
        "iya",
        "betul",
        "bener",
        "ril",
        "iyalah",
        "yup",
        "yap",
        "yoi",
        "yups",
        "yay",
};

std::vector<std::string> InputManager::no = {
        "n",
        "no",
        "false",
        "0",
        "tidak",
        "tak",
        "nggak",
        "ngga",
        "gak",
        "g",
        "t",
        "nein",
        "ora",
        "hell no",
};

void InputManager::receiveInput(const string& message)
{
    std::cout << message;
    std::cin >> _inputData<string>;
    std::cout << "\n";
}

void InputManager::NewGameInput()
{
    try
    {
        cout << "Please enter a valid input\n";
        cout << "1. input New_Game jika ingin buat game baru\n";
        cout << "2. input Continue jika ingin memulai game dengan membaca berkas\n" << endl;
        receiveInput("Pilihan: ");


        string data = DataConverter::LowerCase(_inputData<string>);


        if (data == "new_game") {
            _inputData<int> = 1;
        } else if (data == "continue") {
            _inputData<int> = 2;
        } else {
            throw InputException("Input Invalid: Masukan belum benar");
        }
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void InputManager::ShowMayorMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "(1): "
         << "Cetak_Penyimpanan \n";
    cout << "(2): "
         << "Pungut_Pajak\n";
    cout << "(3): "
         << "Bangun\n";
    cout << "(4): "
         << "Makan\n";
    cout << "(5): "
         << "Beli\n";
    cout << "(6): "
         << "Jual\n";
    cout << "(7): "
         << "Simpan\n";
    cout << "(8): "
         << "Tambah_Pemain\n";
    cout << "(9): "
         << "Next_Turn\n";
    cout << endl;
}

void InputManager::MayorMenuInputValidation()
{
    try {
        ShowMayorMenu();
        receiveInput("Pilihan : ");
      
        _inputData<string> = DataConverter::LowerCase(_inputData<string>);
        string data = _inputData<string>;
        if (data == "cetak_penyimpanan") {
            _inputData<int> = 1;
        } else if (data == "pungut_pajak") {
            _inputData<int> = 2;
        } else if (data == "bangun_bangunan") {
            _inputData<int> = 3;
        } else if (data == "makan") {
            _inputData<int> = 4;
        } else if (data == "beli") {
            _inputData<int> = 5;
        } else if (data == "jual") {
            _inputData<int> = 6;
        } else if (data == "muat") {
            _inputData<int> = 7;
        } else if (data == "simpan") {
            _inputData<int> = 8;
        } else if (data == "tambah_pemain") {
            _inputData<int> = 9;
        } else if (data == "next") {
            _inputData<int> = 10;
        } else {
            throw MenuException("Invalid Input: Masukan belum benar");
        }
    } catch (GameException& e){
        cout << e.what() << endl;
        MayorMenuInputValidation();
    }
}

void InputManager::ShowStockmanMenu()
{
    std::cout << "===== Menu Selection =====\n";
    std::cout << "(1): "
              << "Cetak Peternakan\n";
    std::cout << "(2): "
              << "Cetak Penyimpanan\n";
    std::cout << "(3): "
              << "Ternak\n";
    std::cout << "(4): "
              << "Makan\n";
    std::cout << "(5): "
              << "Memberi Pangan\n";
    std::cout << "(6): "
              << "Membeli\n";
    std::cout << "(7): "
              << "Menjual\n";
    std::cout << "(8): "
              << "Memanen\n";
    std::cout << "(9): "
              << "Simpan\n";
    std::cout << "(10): "
              << "Next Turn\n";
}

void InputManager::StockmanMenuInputValidation()
{
    try {
        ShowStockmanMenu();
        receiveInput("Pilihan : ");
      
        _inputData<string> = DataConverter::LowerCase(_inputData<string>);
        if (_inputData<string> == "cetak_peternakan") {
            _inputData<int> = 1;
        } else if (_inputData<string> == "cetak_penyimpanan") {
            _inputData<int> = 2;
        } else if (_inputData<string> == "ternak") {
            _inputData<int> = 3;
        } else if (_inputData<string> == "makan") {
            _inputData<int> = 4;
        } else if (_inputData<string> == "memberi_pangan") {
            _inputData<int> = 5;
        } else if (_inputData<string> == "membeli") {
            _inputData<int> = 6;
        } else if (_inputData<string> == "menjual") {
            _inputData<int> = 7;
        } else if (_inputData<string> == "memanen") {
            _inputData<int> = 8;
        } else if (_inputData<string> == "simpan") {
            _inputData<int> = 9;
        } else if (_inputData<string> == "next") {
            _inputData<int> = 10;
        } else {
            throw MenuException("Invalid Input: Masukan belum benar");
        }
    } catch (GameException& e){
        cout << e.what() << endl;
        StockmanMenuInputValidation();
    }
}

void InputManager::ShowFarmerMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "(1): "
         << "Cetak_Penyimpanan\n";
    cout << "(2): "
         << "Cetak_Ladang\n";
    cout << "(3): "
         << "Tanam\n";
    cout << "(4): "
         << "Makan\n";
    cout << "(5): "
         << "Beli\n";
    cout << "(6): "
         << "Jual\n";
    cout << "(7): "
         << "Panen\n";
    cout << "(8): "
         << "Simpan\n";
    cout << "(9): "
         << "Next_Turn\n";
    cout << endl;
}

void InputManager::FarmerMenuInputValidation()
{
    try {
        ShowFarmerMenu();
        receiveInput("Pilihan : ");

        _inputData<string> = DataConverter::LowerCase(_inputData<string>);
        string data = _inputData<string>;
        if (data == "cetak_penyimpanan")
        {
            _inputData<int> = 1;
        }
        else if (data == "cetak_ladang")
        {
            _inputData<int> = 2;
        }
        else if (_inputData<string> == "tanam")
        {
            _inputData<int> = 3;
        }
        else if (data == "makan")
        {
            _inputData<int> = 4;
        }
        else if (data == "beli")
        {
            _inputData<int> = 5;
        }
        else if (data == "jual")
        {
            _inputData<int> = 6;
        }
        else if (data == "panen")
        {
            _inputData<int> = 7;
        }
        else if (data == "simpan")
        {
            _inputData<int> = 8;
        }
        else if (data == "next")
        {
            _inputData<int> = 9;
        }
        else
        {
            throw MenuException("Invalid Input: Masukan belum benar");
        }
    } catch (MenuException& e){
        cout << e.what() << endl;
        FarmerMenuInputValidation();
    }
}

void InputManager::receiveIntInput(const string& message)
{

    while (true)
    {
        try {
            receiveInput(message);


            if (!DataConverter::isNumber(_inputData<string>))
            {
                throw InputException("Invalid Input: Please input a number");
            }

            _inputData<int> = stoi(_inputData<string>);
            break;
        } catch (InputException& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void InputManager::receiveFloatInput(const string& message)
{

    while (true){
        try {
            receiveInput(message);

            if (!DataConverter::isNumber(_inputData<string>))
            {
                throw InputException("Invalid Input: Please input a number");
            }

            _inputData<float> = stof(_inputData<string>);
            break;
        } catch (InputException& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

bool InputManager::receiveBooleanInput(const string& message)
{
    while (true) {
        try{
            receiveInput(message);

            _inputData<string> = DataConverter::LowerCase(_inputData<string>);


            if (find(yes.begin(), yes.end(), _inputData<string>) != yes.end())
            {
                return true;
            }
            else if (find(no.begin(), no.end(), _inputData<string>) != no.end())
            {
                return false;
            }
            throw InputException("Invalid Input: Please input true or false");
        } catch (InputException& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void InputManager::StateManagerLoadStateInputValidation()
{
    try
    {
        try
        {
            _inputData<bool> = receiveBooleanInput("Masukkan 'y' atau 'n' :");
        }
        catch (InputException& e)
        {
            throw InputException("Masukkan tidak valid. Silakan masukkan 'y' atau 'n' atau yes or no apapun yang dapat kamu pikirkan .");
        }
    }
    catch (InputException& e)
    {
        cout << e.what() << endl;
    }
}

void InputManager::StateManagerLoadStateFromFileInputValidation()
{
    receiveInput("");
    _file_data.open(_inputData<string>);

    string data_check = DataConverter::LowerCase(_inputData<string>);
    if (!_file_data.is_open())
    {
        throw InputException("File tidak bisa dibuka, Berkas tidak ditemukan !!! ");
    }
}

void InputManager::MembeliInputValidationPickingItems(int ItemsMaxSize)
{
    receiveIntInput("Barang yang ingin dibeli: ");
    cout << endl;
    if (_inputData<int> <= 0 || _inputData<int> > ItemsMaxSize)
    {
        throw InputException("Barang yang ingin dibeli tidak valid");
    }
}

void InputManager::QuantityValidation(int ItemsQuantity)
{
    receiveIntInput("Kuantitas : ");
    cout << endl;
    if (_inputData<int> <= 0 || _inputData<int> > ItemsQuantity)
    {
        string errorMessage = "Kuantitas " + to_string(_inputData<int>) + " tidak valid";
        throw InputException(errorMessage);
    }
}