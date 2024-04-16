#include <iostream>
#include <string>
#include <algorithm>
#include "InputManager.hpp"
#include <fstream>

InputManager::InputManager() = default;
ifstream InputManager::_file_data;

int InputManager::_inputDataInt;
float InputManager::_inputDataFloat;
string InputManager::_inputDataString;
bool InputManager::_inputDataBool;

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

void InputManager::receiveInput(const string &message)
{
    std::cout << message;
    std::cin >> _inputDataString;
    std::cout << "\n";
}

void InputManager::NewGameInput()
{
    try
    {
        cout << "Please enter a valid input\n";
        cout << "1. input New_Game jika ingin buat game baru\n";
        cout << "2. input Continue jika ingin memulai game dengan membaca berkas\n"
             << endl;
        receiveInput("Pilihan: ");

        string data = DataConverter::LowerCase(_inputDataString);

        if (data == "new_game")
        {
            _inputDataInt = 1;
        }
        else if (data == "continue")
        {
            _inputDataInt = 2;
        }
        else
        {
            throw InputException("Input Invalid: Masukan belum benar");
        }
    }
    catch (InputException &e)
    {
        throw e;
    }
}

void InputManager::ShowMayorMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "1. "
         << "CETAK_PENYIMPANAN\n";
    cout << "2. "
         << "PUNGUT_PAJAK\n";
    cout << "3. "
         << "BANGUN\n";
    cout << "4. "
         << "MAKAN\n";
    cout << "5. "
         << "BELI\n";
    cout << "6. "
         << "JUAL\n";
    cout << "7. "
         << "SIMPAN\n";
    cout << "8. "
         << "TAMBAH_PEMAIN\n";
    cout << "9. "
         << "INFO_SEASON\n";
    cout << "10. "
         << "NEXT\n";
    cout << endl;
}

void InputManager::MayorMenuInputValidation()
{
    try
    {
        ShowMayorMenu();
        receiveInput("> ");

        _inputDataString = DataConverter::LowerCase(_inputDataString);
        string data = _inputDataString;
        if (data == "cetak_penyimpanan")
        {
            _inputDataInt = 1;
        }
        else if (data == "pungut_pajak")
        {
            _inputDataInt = 2;
        }
        else if (data == "bangun")
        {
            _inputDataInt = 3;
        }
        else if (data == "makan")
        {
            _inputDataInt = 4;
        }
        else if (data == "beli")
        {
            _inputDataInt = 5;
        }
        else if (data == "jual")
        {
            _inputDataInt = 6;
        }
        else if (data == "simpan")
        {
            _inputDataInt = 7;
        }
        else if (data == "tambah_pemain")
        {
            _inputDataInt = 8;
        }
        else if (data == "info_season"){
            _inputDataInt = 9;
        }
        else if (data == "next")
        {
            _inputDataInt = 10;
        }
        else
        {
            throw MenuException("Invalid Input: Masukan belum benar");
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
        MayorMenuInputValidation();
    }
}

void InputManager::ShowStockmanMenu()
{
    std::cout << "===== Menu Selection =====\n";
    std::cout << "1. "
              << "CETAK_PETERNAKAN\n";
    std::cout << "2. "
              << "CETAK_PENYIMPANAN\n";
    std::cout << "3. "
              << "TERNAK\n";
    std::cout << "4. "
              << "MAKAN\n";
    std::cout << "5. "
              << "KASIH_MAKAN\n";
    std::cout << "6. "
              << "BELI\n";
    std::cout << "7. "
              << "JUAL\n";
    std::cout << "8. "
              << "PANEN\n";
    std::cout << "9. "
              << "SIMPAN\n";
    std::cout << "10. "
              << "INFO_SEASON\n";
    std::cout << "11. "
              << "NEXT\n";
    std::cout << endl;
}

void InputManager::StockmanMenuInputValidation()
{
    try
    {
        ShowStockmanMenu();
        receiveInput("> ");

        _inputDataString = DataConverter::LowerCase(_inputDataString);
        if (_inputDataString == "cetak_peternakan")
        {
            _inputDataInt = 1;
        }
        else if (_inputDataString == "cetak_penyimpanan")
        {
            _inputDataInt = 2;
        }
        else if (_inputDataString == "ternak")
        {
            _inputDataInt = 3;
        }
        else if (_inputDataString == "makan")
        {
            _inputDataInt = 4;
        }
        else if (_inputDataString == "kasih_makan")
        {
            _inputDataInt = 5;
        }
        else if (_inputDataString == "beli")
        {
            _inputDataInt = 6;
        }
        else if (_inputDataString == "jual")
        {
            _inputDataInt = 7;
        }
        else if (_inputDataString == "panen")
        {
            _inputDataInt = 8;
        }
        else if (_inputDataString == "simpan")
        {
            _inputDataInt = 9;
        }
        else if (_inputDataString == "info_season")
        {
            _inputDataInt = 10;
        }
        else if (_inputDataString == "next")
        {
            _inputDataInt = 11;
        }
        else
        {
            throw MenuException("Invalid Input: Masukan belum benar");
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
        StockmanMenuInputValidation();
    }
}

void InputManager::ShowFarmerMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "1. "
         << "CETAK_PENYIMPANAN\n";
    cout << "2. "
         << "CETAK_LADANG\n";
    cout << "3. "
         << "TANAM\n";
    cout << "4. "
         << "MAKAN\n";
    cout << "5. "
         << "BELI\n";
    cout << "6. "
         << "JUAL\n";
    cout << "7. "
         << "PANEN\n";
    cout << "8. "
         << "SIMPAN\n";
    cout << "9. "
         << "INFO_SEASON  \n";
    cout << "10. "
         << "NEXT  \n";
    cout << endl;
}

void InputManager::FarmerMenuInputValidation()
{
    try
    {
        ShowFarmerMenu();
        receiveInput("> ");

        _inputDataString = DataConverter::LowerCase(_inputDataString);
        string data = _inputDataString;
        if (data == "cetak_penyimpanan")
        {
            _inputDataInt = 1;
        }
        else if (data == "cetak_ladang")
        {
            _inputDataInt = 2;
        }
        else if (_inputDataString == "tanam")
        {
            _inputDataInt = 3;
        }
        else if (data == "makan")
        {
            _inputDataInt = 4;
        }
        else if (data == "beli")
        {
            _inputDataInt = 5;
        }
        else if (data == "jual")
        {
            _inputDataInt = 6;
        }
        else if (data == "panen")
        {
            _inputDataInt = 7;
        }
        else if (data == "simpan")
        {
            _inputDataInt = 8;
        }
        else if (data == "info_season")
        {
            _inputDataInt = 9;
        }
        else if (data == "next")
        {
            _inputDataInt = 10;
        }
        else
        {
            throw MenuException("Invalid Input: Masukan belum benar");
        }
    }
    catch (MenuException &e)
    {
        cout << e.what() << endl;
        FarmerMenuInputValidation();
    }
}

void InputManager::receiveIntInput(const string &message)
{

    while (true)
    {
        try
        {
            receiveInput(message);

            if (!DataConverter::isNumber(_inputDataString))
            {
                throw InputException("Invalid Input: Please input a number");
            }

            _inputDataInt = stoi(_inputDataString);
            break;
        }
        catch (InputException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void InputManager::receiveFloatInput(const string &message)
{

    while (true)
    {
        try
        {
            receiveInput(message);

            if (!DataConverter::isNumber(_inputDataString))
            {
                throw InputException("Invalid Input: Please input a number");
            }

            _inputDataFloat = stof(_inputDataString);
            break;
        }
        catch (InputException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

bool InputManager::receiveBooleanInput(const string &message)
{
    while (true)
    {
        try
        {
            receiveInput(message);

            _inputDataString = DataConverter::LowerCase(_inputDataString);

            if (find(yes.begin(), yes.end(), _inputDataString) != yes.end())
            {
                return true;
            }
            else if (find(no.begin(), no.end(), _inputDataString) != no.end())
            {
                return false;
            }
            throw InputException("Invalid Input: Please input true or false");
        }
        catch (InputException &e)
        {
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
            _inputDataBool = receiveBooleanInput("Masukkan 'y' atau 'n' :");
        }
        catch (InputException &e)
        {
            throw InputException("Masukkan tidak valid. Silakan masukkan 'y' atau 'n' atau yes or no apapun yang dapat kamu pikirkan .");
        }
    }
    catch (InputException &e)
    {
        cout << e.what() << endl;
    }
}

void InputManager::StateManagerLoadStateFromFileInputValidation()
{
    receiveInput("");
    _file_data.open(_inputDataString);

    string data_check = DataConverter::LowerCase(_inputDataString);
    if (!_file_data.is_open())
    {
        throw InputException("File tidak bisa dibuka, Berkas tidak ditemukan !!! ");
    }
}

void InputManager::QuantityValidation(int ItemsQuantity, const string& messages)
{
    receiveIntInput(messages + " : ");
    cout << endl;

    if (ItemsQuantity == -1 && _inputDataInt > 0) {
        return;
    }
    else if(_inputDataInt <= 0){
        string errorMessage = "Kuantitas " + to_string(_inputDataInt) + " tidak valid";
        throw InputException(errorMessage);
    }
    else{
        if (_inputDataInt <= 0 || _inputDataInt > ItemsQuantity)
        {
            string errorMessage = "Kuantitas " + to_string(_inputDataInt) + " tidak valid";
            throw InputException(errorMessage);
        }
    }

}