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
    std::cin >> _inputData<string>;
    std::cout << std::endl;
}

void InputManager::NewGameInput()
{
    std::cout << "Please enter a valid input" << std::endl;
    std::cout << "1. input (1) jika ingin buat game baru" << std::endl;
    std::cout << "2. input (2) jika ingin membaca berkas" << std::endl
              << std::endl;
    receiveInput();
}

void InputManager::MayorMenuInputValidation()
{
    std::cout << "Menu Selection: " << std::endl;
    std::cout << "(1): "
              << "Cetak Simpanan" << std::endl;
    std::cout << "(2): "
              << "Pungut Pajak" << std::endl;
    std::cout << "(3): "
              << "Bangun Bangunan" << std::endl;
    std::cout << "(4): "
              << "Makan" << std::endl;
    std::cout << "(5): "
              << "Beli" << std::endl;
    std::cout << "(6): "
              << "Jual" << std::endl;
    std::cout << "(7): "
              << "Muat" << std::endl;
    std::cout << "(8): "
              << "Simpan" << std::endl;
    std::cout << "(9): "
              << "Tambah Pemain" << std::endl;
    std::cout << "(10): "
              << "Next turn" << std::endl;

    std::cout << "Pilihan: ";
    receiveInput();
    std::cout << std::endl;

    int data = StringToNumber<int>(_inputData<string>);

    if (data < 1 || data > 10)
    {
        throw MenuException("Invalid Input: Please input between 1 and 10");
    }
}

void InputManager::StockmanMenuInputValidation()
{
    std::cout << "Menu Selection: " << std::endl;
    std::cout << "(1): "
              << "Cetak Peternakan" << std::endl;
    std::cout << "(2): "
              << "Ternak" << std::endl;
    std::cout << "(3): "
              << "Makan" << std::endl;
    std::cout << "(4): "
              << "Memberi Pangan" << std::endl;
    std::cout << "(5): "
              << "Membeli" << std::endl;
    std::cout << "(6): "
              << "Menjual" << std::endl;
    std::cout << "(7): "
              << "Memanen" << std::endl;
    std::cout << "(8): "
              << "Muat" << std::endl;
    std::cout << "(9): "
              << "Simpan" << std::endl;
    std::cout << "(10): "
              << "Next turn" << std::endl;

    std::cout << "Pilihan: ";
    receiveInput();
    int data = StringToNumber<int>(_inputData<string>);

    if (data < 1 || data > 10)
    {
        throw MenuException("Invalid Input: Please input between 1 and 10");
    }
}

void InputManager::FarmerMenuInputValidation()
{
    std::cout << "Menu Selection: " << std::endl;
    std::cout << "(1): "
              << "Tanam" << std::endl;
    std::cout << "(2): "
              << "Cetak Ladang" << std::endl;
    std::cout << "(3): "
              << "Makan" << std::endl;
    std::cout << "(4): "
              << "Membeli" << std::endl;
    std::cout << "(5): "
              << "Menjual" << std::endl;
    std::cout << "(6): "
              << "Memanen" << std::endl;
    std::cout << "(7): "
              << "Muat" << std::endl;
    std::cout << "(8): "
              << "Simpan" << std::endl;
    std::cout << "(9): "
              << "Next turn" << std::endl;

    std::cout << "Pilihan: ";
    receiveInput();

    int data = StringToNumber<int>(_inputData<string>);
    if (data < 1 || data > 9)
    {
        throw MenuException("Invalid Input: Please input between 1 and 9");
    }
}

std::pair<int, int> InputManager::GetSingleRowCol(const string& input)
{
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

vector<std::pair<int,int>> InputManager::GetMultipleRowCol(std::string input) {
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

bool InputManager::receiveBooleanInput(){
    string lower;
    std::cin >> lower;

    // Change to lower case
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

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
