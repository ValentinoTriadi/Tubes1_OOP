#include <iostream>
#include <string>
#include <algorithm>
#include "InputManager.hpp"
#include "../../Exception/InputException/InputException.hpp"
#include <regex>
InputManager::InputManager() = default;

template <typename T>
T InputManager::_inputData;

template <>
int InputManager::StringToNumber(const string& data)
{
    try
    {
        if (isNumber(data))
        {
            return std::stoi(data);
        }
        else
        {
            throw InputException("Input Is Not a Number");
        }
    }
    catch (InputException& i)
    {
        std::cout << i.what() << std::endl;
        return -999;
    }
}

template <>
float InputManager::StringToNumber(const string& data)
{
    try
    {
        if (isNumber(data))
        {
            return std::stof(data);
        }
        else
        {
            throw InputException("Input Is Not a Number");
        }
    }
    catch (InputException& i)
    {
        std::cout << i.what() << std::endl;
        return -999; // ERROR Code
    }
}

bool InputManager::isNumber(char data) {
    return data >= '0' && data <= '9';
}

bool InputManager::isNumber(const string& data)
{
    if (data.empty() || (data.size() == 1 && data[0] == '-'))
        return false;

    bool hasDigit = false;
    bool hasDecimal = false;

    for (size_t i = 0; i < data.size(); ++i)
    {
        char c = data[i];

        if (i == 0 && c == '-')
        {
            continue;
        }

        if (c == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }

        else if (!std::isdigit(c))
        {
            return false;
        }
        else
        {
            hasDigit = true;
        }
    }

    return hasDigit;
}

void InputManager::receiveInput()
{
    std::cout << "Pilihan: ";
    std::cin >> _inputData<string>;
    std::cout << "\n";
}

void InputManager::NewGameInput()
{
    std::cout << "Please enter a valid input\n";
    std::cout << "1. input (1) jika ingin buat game baru\n";
    std::cout << "2. input (2) jika ingin membaca berkas\n\n";
    receiveInput();
}

void InputManager::ShowMayorMenu(){
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
              << "Next\n";
}


void InputManager::MayorMenuInputValidation()
{
    ShowMayorMenu();
    receiveInput();

    _inputData<string> = LowerCase(_inputData<string>);
    if (_inputData<string> == "cetak simpanan") {
        _inputData<int> = 1;
    } else if (_inputData<string> == "pungut pajak") {
        _inputData<int> = 2;
    } else if (_inputData<string> == "bangun bangunan") {
        _inputData<int> = 3;
    } else if (_inputData<string> == "makan") {
        _inputData<int> = 4;
    } else if (_inputData<string> == "beli") {
        _inputData<int> = 5;
    } else if (_inputData<string> == "jual") {
        _inputData<int> = 6;
    } else if (_inputData<string> == "muat") {
        _inputData<int> = 7;
    } else if (_inputData<string> == "simpan") {
        _inputData<int> = 8;
    } else if (_inputData<string> == "tambah pemain") {
        _inputData<int> = 9;
    } else if (_inputData<string> == "next") {
        _inputData<int> = 10;
    } else {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

void InputManager::ShowStockmanMenu(){
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
              << "Next\n";
}

void InputManager::StockmanMenuInputValidation()
{
    ShowStockmanMenu();
    receiveInput();

    _inputData<string> = LowerCase(_inputData<string>);
    if (_inputData<string> == "cetak peternakan") {
        _inputData<int> = 1;
    } else if (_inputData<string> == "ternak") {
        _inputData<int> = 2;
    } else if (_inputData<string> == "makan") {
        _inputData<int> = 3;
    } else if (_inputData<string> == "memberi pangan") {
        _inputData<int> = 4;
    } else if (_inputData<string> == "membeli") {
        _inputData<int> = 5;
    } else if (_inputData<string> == "menjual") {
        _inputData<int> = 6;
    } else if (_inputData<string> == "memanen") {
        _inputData<int> = 7;
    } else if (_inputData<string> == "muat") {
        _inputData<int> = 8;
    } else if (_inputData<string> == "simpan") {
        _inputData<int> = 9;
    } else if (_inputData<string> == "next") {
        _inputData<int> = 10;
    } else {
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
              << "Next\n";
}

void InputManager::FarmerMenuInputValidation()
{
    ShowFarmerMenu();
    receiveInput();

    _inputData<string> = LowerCase(_inputData<string>);
    if (_inputData<string> == "tanam") {
        _inputData<int> = 1;
    } else if (_inputData<string> == "cetak ladang") {
        _inputData<int> = 2;
    } else if (_inputData<string> == "makan") {
        _inputData<int> = 3;
    } else if (_inputData<string> == "membeli") {
        _inputData<int> = 4;
    } else if (_inputData<string> == "menjual") {
        _inputData<int> = 5;
    } else if (_inputData<string> == "memanen") {
        _inputData<int> = 6;
    } else if (_inputData<string> == "muat") {
        _inputData<int> = 7;
    } else if (_inputData<string> == "simpan") {
        _inputData<int> = 8;
    } else if (_inputData<string> == "next") {
        _inputData<int> = 9;
    } else {
        throw MenuException("Invalid Input: Masukan belum benar");
    }
}

std::pair<int, int> InputManager::GetSingleRowCol()
{
    cout << "Slot: ";
    string input;
    cin >> input;
    cout << "\n";

    if (input.size() != 3)
    {
        throw InputException("Invalid Input: Please input 3 characters (B01)");
    }

    if (!isAlphabet(input[0]) || !isNumber(input[2]))
    {
        throw InputException("Invalid Input: Please input A-Z and 0-9");
    }

    return std::make_pair((int)(input[0] - 'A'), (int)(input[2] - '0'));
};

vector<std::pair<int,int>> InputManager::GetMultipleRowCol() {

    cout << "Slot: ";
    string input;
    cin >> input;

    if (input.length() < 3) throw InputException("Invalid Input: Please input minimum 3 characters.");

    // Regex for input with format A01, A02, A03,..., A0N
    std::regex pattern("([A-Z][0-9]{2},?)+");
    if (!std::regex_match(input, pattern))
        throw InputException("Invalid Input: Please input A-Z and 0-9 with pattern A09, B01,..., C04");

    vector<std::pair<int, int>> result;
    for (size_t i = 0; i < input.length(); i += 3) {
        result.emplace_back((int) (input[i] - 'A'), (int) (input[i + 2] - '0'));
    }

    return result;
}

bool InputManager::isAlphabet(const string& data)
{
    if (data.empty())
        return false;

    for (char i : data)
    {
        if (!isAlphabet(i))
            return false;
    }

    return true;
}

bool InputManager::isAlphabet(char data) {
    return data >= 'A' && data <= 'Z';
}

void InputManager::receiveIntInput() {
    std::cin >> _inputData<string>;
    std::cout << std::endl;

    if (!isNumber(_inputData<string>)) {
        throw InputException("Invalid Input: Please input a number");
    }

    _inputData<int> = stoi(_inputData<string>);
}

void InputManager::receiveFloatInput() {
    std::cin >> _inputData<string>;

    if (!isNumber(_inputData<string>)) {
        throw InputException("Invalid Input: Please input a number");
    }

    std::cout << std::endl;

    _inputData<float> = stof(_inputData<string>);
}

void InputManager::receiveStringInput() {
    std::cin >> _inputData<string>;
    std::cout << std::endl;
}

string InputManager::LowerCase(string data) {
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

bool InputManager::receiveBooleanInput(){

    _inputData<string> = LowerCase(_inputData<string>);

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


    if (find(yes.begin(), yes.end(), _inputData<string>) != yes.end()){
        return true;
    } else if (find(no.begin(), no.end(), _inputData<string>) != no.end()){
        return false;
    }
    throw InputException("Invalid Input: Please input true or false");

}
