#include <iostream>
#include <string>
#include "InputManager.hpp"
#include "../../Exception/InputException/InputException.hpp"
InputManager::InputManager() = default;

std::string InputManager::_inputData;

template <>
int InputManager::StringToNumber(string data)
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
    catch (InputException i)
    {
        std::cout << i.what() << std::endl;
        return -999; // ERROR Code
    }
}

template <>
float InputManager::StringToNumber(string data)
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
    catch (InputException i)
    {
        std::cout << i.what() << std::endl;
        return -999; // ERROR Code
    }
}

bool InputManager::isNumber(string data)
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
    _inputData.clear();
    cin >> _inputData;
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

    int data = StringToNumber<int>(_inputData);

    if (data < 1 || data > 9)
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
    int data = StringToNumber<int>(_inputData);

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

    int data = StringToNumber<int>(_inputData);
    if (data < 1 || data > 8)
    {
        throw MenuException("Invalid Input: Please input between 1 and 9");
    }
}

std::pair<int, int> InputManager::GetSingleRowCol(string input)
{
    try
    {
        try{
            if(isAlphabet(input[0])){

            }
        }
        return std::make_pair(row, col);
    }
};

bool InputManager::isAlphabet(string data)
{
    return data >= "A" && data <= "Z";
}
