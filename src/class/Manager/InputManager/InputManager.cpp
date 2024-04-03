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
    std::cout << "Pilihan: ";
    std::getline(std::cin, _inputData<string>);
    std::cout << "\n";
}

void InputManager::NewGameInput()
{
    try
    {
        std::cout << "Please enter a valid input\n";
        std::cout << "1. input (New Game) or (1) jika ingin buat game baru\n";
        std::cout << "2. input (Continue) or (2) jika ingin membaca berkas\n\n";
        receiveInput();

        if (_inputData<string> == "New Game" || _inputData<string> == "Continue")
        {
            if (_inputData<string> == "New Game")
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
            _inputData<int> = DataConverter::StringToNumber<int>(_inputData<string>);
            int data = _inputData<int>;
            if (data < 1 || data > 2)
            {
                throw InputException("Input Invalid: Masukan belum benar");
            }
        }
    }
    catch (InputException e)
    {
        std::cout << e.what() << std::endl;
        NewGameInput();
    }
}

void InputManager::ShowMayorMenu()
{
    std::cout << "Menu Selection: \n";
    std::cout << "(1): "
              << "Cetak Simpanan \n";
    std::cout << "(2): "
              << "Pungut Pajak\n";
    std::cout << "(3): "
              << "Bangun Bangunan\n";
    std::cout << "(4): "
              << "Makan\n";
    std::cout << "(5): "
              << "Beli\n";
    std::cout << "(6): "
              << "Jual\n";
    std::cout << "(7): "
              << "Muat\n";
    std::cout << "(8): "
              << "Simpan\n";
    std::cout << "(9): "
              << "Tambah Pemain\n";
    std::cout << "(10): "
              << "Next Turn\n";
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
    else if (data == "bangun_bangunan")
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
    else if (data == "muat")
    {
        _inputData<int> = 7;
    }
    else if (data == "simpan")
    {
        _inputData<int> = 8;
    }
    else if (data == "tambah_pemain")
    {
        _inputData<int> = 9;
    }
    else if (data == "next_turn")
    {
        _inputData<int> = 10;
    }
    else
    {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::ShowStockmanMenu()
{
    std::cout << "Menu Selection: \n";
    std::cout << "(1): "
              << "Cetak Peternakan\n";
    std::cout << "(2): "
              << "Ternak\n";
    std::cout << "(3): "
              << "Makan\n";
    std::cout << "(4): "
              << "Memberi Pangan\n";
    std::cout << "(5): "
              << "Membeli\n";
    std::cout << "(6): "
              << "Menjual\n";
    std::cout << "(7): "
              << "Memanen\n";
    std::cout << "(8): "
              << "Muat\n";
    std::cout << "(9): "
              << "Simpan\n";
    std::cout << "(10): "
              << "Next Turn\n";
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
    else if (_inputData<string> == "memberi_pangan")
    {
        _inputData<int> = 4;
    }
    else if (_inputData<string> == "membeli")
    {
        _inputData<int> = 5;
    }
    else if (_inputData<string> == "menjual")
    {
        _inputData<int> = 6;
    }
    else if (_inputData<string> == "memanen")
    {
        _inputData<int> = 7;
    }
    else if (_inputData<string> == "muat")
    {
        _inputData<int> = 8;
    }
    else if (_inputData<string> == "simpan")
    {
        _inputData<int> = 9;
    }
    else if (_inputData<string> == "next turn")
    {
        _inputData<int> = 10;
    }
    else
    {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::ShowFarmerMenu()
{
    std::cout << "Menu Selection: \n";
    std::cout << "(1): "
              << "Tanam\n";
    std::cout << "(2): "
              << "Cetak Ladang\n";
    std::cout << "(3): "
              << "Makan\n";
    std::cout << "(4): "
              << "Membeli\n";
    std::cout << "(5): "
              << "Menjual\n";
    std::cout << "(6): "
              << "Memanen\n";
    std::cout << "(7): "
              << "Muat\n";
    std::cout << "(8): "
              << "Simpan\n";
    std::cout << "(9): "
              << "Next Turn\n";
}

void InputManager::FarmerMenuInputValidation()
{
    ShowFarmerMenu();
    receiveInput();

    _inputData<string> = DataConverter::LowerCase(_inputData<string>);
    string data = _inputData<string>;
    if (data == "tanam")
    {
        _inputData<int> = 1;
    }
    else if (_inputData<string> == "cetak_ladang")
    {
        _inputData<int> = 2;
    }
    else if (data == "makan")
    {
        _inputData<int> = 3;
    }
    else if (data == "membeli")
    {
        _inputData<int> = 4;
    }
    else if (data == "menjual")
    {
        _inputData<int> = 5;
    }
    else if (data == "memanen")
    {
        _inputData<int> = 6;
    }
    else if (data == "muat")
    {
        _inputData<int> = 7;
    }
    else if (data == "simpan")
    {
        _inputData<int> = 8;
    }
    else if (data == "next turn")
    {
        _inputData<int> = 9;
    }
    else
    {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::receiveIntInput()
{
    std::cin >> _inputData<string>;
    std::cout << std::endl;

    if (!DataConverter::isNumber(_inputData<string>))
    {
        throw InputException("Invalid Input: Please input a number");
    }

    _inputData<int> = stoi(_inputData<string>);
}

void InputManager::receiveFloatInput()
{
    std::cin >> _inputData<string>;

    if (!DataConverter::isNumber(_inputData<string>))
    {
        throw InputException("Invalid Input: Please input a number");
    }

    std::cout << "\n";

    _inputData<float> = stof(_inputData<string>);
}

void InputManager::receiveStringInput()
{
    std::cin >> _inputData<string>;
    std::cout << "\n";
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
        receiveInput();

        string data = DataConverter::LowerCase(_inputData<string>);
        cout << data << std::endl;
        if (data != "y" && data != "n")
        {
            throw InputException("Masukkan tidak valid. Silakan masukkan 'y' atau 'n'.");
        }
    }
    catch (InputException e)
    {
        std::cout << e.what() << std::endl;
        StateManagerLoadStateInputValidation();
    }
}

void InputManager::StateManagerLoadStateFromFileInputValidation()
{
    try
    {
        receiveStringInput();
        _file_data.open(_inputData<string>);

        string data_check = DataConverter::LowerCase(_inputData<string>);
        if (!_file_data.is_open())
        {
            if (data_check != "back_to_main_menu")
            {
                throw InputException("Berkas tidak valid. Silakan masukkan lokasi berkas yang valid: (Input Back_to_main_menu untuk kembali ke halaman awal!!)");
            }
        }
    }
    catch (InputException e)
    {
        std::cout << e.what() << std::endl;
        StateManagerLoadStateFromFileInputValidation();
    }
}
