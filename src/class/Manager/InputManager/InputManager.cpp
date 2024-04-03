#include <iostream>
#include <string>
#include <algorithm>
#include "InputManager.hpp"
#include <fstream>
InputManager::InputManager() = default;

template <typename T>
T InputManager::_inputData;

ifstream InputManager::_file_data;

void InputManager::receiveInput()
{
    cout << "Pilihan: ";
    cin >> _inputData<string>;
    cout << "\n";
}

void InputManager::NewGameInput()
{
    cout << "Please enter a valid input\n";
    cout << "1. input New_Game jika ingin buat game baru\n";
    cout << "2. input Continue jika ingin memulai game dengan membaca berkas" << endl
         << endl;
    receiveInput();

    string data = DataConverter::LowerCase(_inputData<string>);

    if (data == "new_game" || data == "continue")
    {
        if (data == "new_game")
        {
            _inputData<int> = 1;
        }
        else
        {
            _inputData<int> = 2;
        }
    }
    else
    {
        throw InputException("Input Invalid: Masukan belum benar");
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
    ShowMayorMenu();
    receiveInput();

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
    else if (data == "next_turn")
    {
        _inputData<int> = 9;
    }
    else
    {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::ShowStockmanMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "(1): "
         << "Cetak_Peternakan\n";
    cout << "(2): "
         << "Ternak\n";
    cout << "(3): "
         << "Makan\n";
    cout << "(4): "
         << "Kasih_Makan\n";
    cout << "(5): "
         << "Beli\n";
    cout << "(6): "
         << "Jual\n";
    cout << "(7): "
         << "Panen\n";
    cout << "(8): "
         << "Simpan\n";
    cout << "(9): "
         << "Next Turn\n";
    cout << endl;
}

void InputManager::StockmanMenuInputValidation()
{
    ShowStockmanMenu();
    receiveInput();

    _inputData<string> = DataConverter::LowerCase(_inputData<string>);
    if (_inputData<string> == "cetak_peternakan")
    {
        _inputData<int> = 1;
    }
    else if (_inputData<string> == "ternak")
    {
        _inputData<int> = 2;
    }
    else if (_inputData<string> == "makan")
    {
        _inputData<int> = 3;
    }
    else if (_inputData<string> == "kasih_makan")
    {
        _inputData<int> = 4;
    }
    else if (_inputData<string> == "beli")
    {
        _inputData<int> = 5;
    }
    else if (_inputData<string> == "jual")
    {
        _inputData<int> = 6;
    }
    else if (_inputData<string> == "panen")
    {
        _inputData<int> = 7;
    }
    else if (_inputData<string> == "simpan")
    {
        _inputData<int> = 8;
    }
    else if (_inputData<string> == "next turn")
    {
        _inputData<int> = 9;
    }
    else
    {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::ShowFarmerMenu()
{
    cout << "===== Menu Selection ===== \n";
    cout << "(1): "
         << "Cetak_Ladang\n";
    cout << "(2): "
         << "Tanam\n";
    cout << "(3): "
         << "Makan\n";
    cout << "(4): "
         << "Beli\n";
    cout << "(5): "
         << "Jual\n";
    cout << "(6): "
         << "Panen\n";
    cout << "(7): "
         << "Simpan\n";
    cout << "(8): "
         << "Next_Turn\n";
    cout << endl;
}

void InputManager::FarmerMenuInputValidation()
{
    ShowFarmerMenu();
    receiveInput();

    _inputData<string> = DataConverter::LowerCase(_inputData<string>);
    string data = _inputData<string>;
    if (data == "cetak_ladang")
    {
        _inputData<int> = 1;
    }
    else if (_inputData<string> == "tanam")
    {
        _inputData<int> = 2;
    }
    else if (data == "makan")
    {
        _inputData<int> = 3;
    }
    else if (data == "beli")
    {
        _inputData<int> = 4;
    }
    else if (data == "jual")
    {
        _inputData<int> = 5;
    }
    else if (data == "panen")
    {
        _inputData<int> = 6;
    }
    else if (data == "simpan")
    {
        _inputData<int> = 7;
    }
    else if (data == "next_turn")
    {
        _inputData<int> = 8;
    }
    else
    {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::receiveIntInput()
{
    cin >> _inputData<string>;
    cout << endl;

    if (!DataConverter::isNumber(_inputData<string>))
    {
        throw InputException("Invalid Input: Please input a number");
    }

    _inputData<int> = stoi(_inputData<string>);
}

void InputManager::receiveFloatInput()
{
    cin >> _inputData<string>;

    if (!DataConverter::isNumber(_inputData<string>))
    {
        throw InputException("Invalid Input: Please input a number");
    }

    cout << "\n";

    _inputData<float> = stof(_inputData<string>);
}

void InputManager::receiveStringInput()
{
    cin >> _inputData<string>;
    cout << "\n";
}

bool InputManager::receiveBooleanInput()
{

    _inputData<string> = DataConverter::LowerCase(_inputData<string>);

    vector<string> yes, no;
    yes = {
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
    };

    no = {
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

void InputManager::StateManagerLoadStateInputValidation()
{
    try
    {
        try
        {
            receiveStringInput();
            _inputData<bool> = receiveBooleanInput();
        }
        catch (InputException e)
        {
            throw InputException("Masukkan tidak valid. Silakan masukkan 'y' atau 'n' atau yes or no apapun yang dapat kamu pikirkan .");
        }
    }
    catch (InputException e)
    {
        cout << e.what() << endl;
    }
}

void InputManager::StateManagerLoadStateFromFileInputValidation()
{
    receiveStringInput();
    _file_data.open(_inputData<string>);

    string data_check = DataConverter::LowerCase(_inputData<string>);
    if (!_file_data.is_open())
    {
        throw InputException("File tidak bisa dibuka, Berkas tidak ditemukan !!! ");
    }
}

void InputManager::MembeliInputValidationPickingItems(int ItemsMaxSize)
{
    cout << "Barang yang ingin dibeli: ";
    receiveIntInput();
    cout << endl;
    if (_inputData<int> <= 0 || _inputData<int> > ItemsMaxSize)
    {
        throw InputException("Barang yang ingin dibeli tidak valid");
    }
}

void InputManager::QuantityValidation(int ItemsQuantity)
{
    cout << "Kuantitas : ";
    receiveIntInput();
    cout << endl;
    if (_inputData<int> <= 0 || _inputData<int> > ItemsQuantity)
    {
        string errorMessage = "Kuantitas " + to_string(_inputData<int>) + " tidak valid";
        throw InputException(errorMessage);
    }
}