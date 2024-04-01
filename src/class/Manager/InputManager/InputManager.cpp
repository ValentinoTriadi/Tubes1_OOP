#include <iostream>
#include <string>
#include "InputManager.hpp"

InputManager::InputManager() = default;

std::string InputManager::_inputData;

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

    int data = std::stoi(_inputData);
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
    std::cout << std::endl;
    int data = std::stoi(_inputData);

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
    std::cout << std::endl;
    int data = std::stoi(_inputData);

    if (data < 1 || data > 9)
    {
        throw MenuException("Invalid Input: Please input between 1 and 9");
    }
}