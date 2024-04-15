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

void InputManager::receiveInput(const string &message)
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
        cout << "2. input Continue jika ingin memulai game dengan membaca berkas\n"
             << endl;
        receiveInput("Pilihan: ");

        string data = DataConverter::LowerCase(_inputData<string>);

        if (data == "new_game")
        {
            _inputData<int> = 1;
        }
        else if (data == "continue")
        {
            _inputData<int> = 2;
        }
        else
        {
            throw InputException("Input Invalid: Masukan belum benar");
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
}

void InputManager::ShowMayorMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "1. "
         << "CETAK_PENYIMPANAN\n";
    cout << "2. "
         << "PUNGUT PAJAK\n";
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
         << "NEXT\n";
    cout << endl;
}

void InputManager::MayorMenuInputValidation()
{
    try
    {
        ShowMayorMenu();
        receiveInput("> ");

        _inputData<string> = DataConverter::LowerCase(_inputData<string>);
        string data = _inputData<string>;
        if (data == "cetak_penyimpanan")
        {
            _inputData<int> = 1;
        }
        else if (data == "pungut_pajak")
        {
            _inputData<int> = 2;
        }
        else if (data == "bangun")
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
        else if (data == "simpan")
        {
            _inputData<int> = 7;
        }
        else if (data == "tambah_pemain")
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
              << "NEXT\n";
    std::cout << endl;
}

void InputManager::StockmanMenuInputValidation()
{
    try
    {
        ShowStockmanMenu();
        receiveInput("> ");

        _inputData<string> = DataConverter::LowerCase(_inputData<string>);
        if (_inputData<string> == "cetak_peternakan")
        {
            _inputData<int> = 1;
        }
        else if (_inputData<string> == "cetak_penyimpanan")
        {
            _inputData<int> = 2;
        }
        else if (_inputData<string> == "ternak")
        {
            _inputData<int> = 3;
        }
        else if (_inputData<string> == "makan")
        {
            _inputData<int> = 4;
        }
        else if (_inputData<string> == "kasih_makan")
        {
            _inputData<int> = 5;
        }
        else if (_inputData<string> == "beli")
        {
            _inputData<int> = 6;
        }
        else if (_inputData<string> == "jual")
        {
            _inputData<int> = 7;
        }
        else if (_inputData<string> == "panen")
        {
            _inputData<int> = 8;
        }
        else if (_inputData<string> == "simpan")
        {
            _inputData<int> = 9;
        }
        else if (_inputData<string> == "next")
        {
            _inputData<int> = 10;
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
         << "NEXT  \n";
    cout << endl;
}

void InputManager::FarmerMenuInputValidation()
{
    try
    {
        ShowFarmerMenu();
        receiveInput("> ");

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

            if (!DataConverter::isNumber(_inputData<string>))
            {
                throw InputException("Invalid Input: Please input a number");
            }

            _inputData<int> = stoi(_inputData<string>);
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

            if (!DataConverter::isNumber(_inputData<string>))
            {
                throw InputException("Invalid Input: Please input a number");
            }

            _inputData<float> = stof(_inputData<string>);
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
            _inputData<bool> = receiveBooleanInput("Masukkan 'y' atau 'n' :");
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
    _file_data.open(_inputData<string>);

    string data_check = DataConverter::LowerCase(_inputData<string>);
    if (!_file_data.is_open())
    {
        throw InputException("File tidak bisa dibuka, Berkas tidak ditemukan !!! ");
    }
}

void InputManager::QuantityValidation(int ItemsQuantity, const string& messages)
{
    receiveIntInput(messages + " : ");
    cout << endl;

    if (ItemsQuantity == -1) {
        return;
    }

    if (_inputData<int> <= 0 || _inputData<int> > ItemsQuantity)
    {
        string errorMessage = "Kuantitas " + to_string(_inputData<int>) + " tidak valid";
        throw InputException(errorMessage);
    }
}