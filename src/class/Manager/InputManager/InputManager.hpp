#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <vector>
#include <string>
#include "../../Exception/GameException.hpp"

class InputManager
{
public:
    static std::string _inputData;
    InputManager();

    /*
     * Receive input from user
     * Usage: ```receiveInput();```
     */
    static void receiveInput();

    /**
     * Convert data input to int or float
     * Usage:```return T;```
     * Param string : used to convert the string into T either float or integer
     */
    template <typename T>
    static T StringToNumber(string);
    /*
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

    static std::pair<int, int> GetSingleRowCol(string input);
    static vector<std::pair<int, int>> GetMultipleRowCol(string input);

private:
    static bool isNumber(string);

    static bool isAlphabet(string);
    static bool isAlphabet(char);
};

#endif