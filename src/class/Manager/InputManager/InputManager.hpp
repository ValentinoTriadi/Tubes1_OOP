#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <vector>
#include <string>
#include "../../Exception/GameException.hpp"

class InputManager
{
public:
/**
     * @brief Input Manager Constructor
     */
    template <typename T>
    static T _inputData;
    InputManager();

    /**
     * Receive input from user
     * Usage: ```receiveInput();```
     */
    static void receiveInput();

    /**
     * Receive input from user
     * Usage: ```receiveIntInput();```
     */
    static void receiveIntInput();

    /**
     * Receive input from user
     * Usage: ```receiveFloatInput();```
     */
    static void receiveFloatInput();

    /**
     * Receive input from user
     * Usage: ```receiveStringInput();```
     */
    static void receiveStringInput();

    /**
     * Convert data input to int or float
     * Usage:```return T;```
     * Param string : used to convert the string into T either float or integer
     */
    template <typename T>
    static T StringToNumber(const string&);

    /**
     * validate the first input user to define whether the
     * the user will create new games or continue the games
     */
    static void NewGameInput();

    /**
     * @brief Validate User Input for Mayor Menu Selection
     */
    static void MayorMenuInputValidation();

    /**
     * @brief Validate User Input for Stockman Menu Selection
     */
    static void StockmanMenuInputValidation();

    /**
     * @brief Validate User Input for Player Menu Selection
     */
    static void FarmerMenuInputValidation();

    /**
     * @brief Validate User Input for Player Row and Column input
     * Input will be taken from the function
     */
    static std::pair<int, int> GetSingleRowCol();

    /**
     * @brief Validate User Input for multiple Row and Column input
     * Input will be taken from the function
     */
    static vector<std::pair<int, int>> GetMultipleRowCol();

    /**
     * @brief Check if the string is a boolean
     * @return true and false if a boolean, exception if not
     */
    static bool receiveBooleanInput();

    /**
     * @brief Change the string to lowercase
     * @return string in lowercase
     */
    static string LowerCase(string data);

    
    static void BuyItemsValidation();

private:
    /**
     * @brief Check if the character is a number
     * @return true if a number
     */
    static bool isNumber(char);

    /**
     * @brief Check if the character is an alphabet
     * @return true if an alphabet
     */
    static bool isAlphabet(char);

    /**
     * @brief Check if the string is an alphabet
     * @return true if an alphabet
     */
    static bool isAlphabet(const string &data);

    /**
     * @brief Check if the string is a number
     * @return true if a number
     */
    static bool isNumber(const string& data);

    /**
     * @brief Show Mayor Menu
     */
    static void ShowMayorMenu();

    /**
     * @brief Show Farmer Menu
     */
    static void ShowFarmerMenu();

    /**
     * @brief Show Stockman Menu
     */
    static void ShowStockmanMenu();
};

#endif