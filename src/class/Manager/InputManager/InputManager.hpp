#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <vector>
#include <string>
#include "../../utils/DataConverter/DataConverter.hpp"

class InputManager
{
private:
    static std::vector<std::string> yes,no;
public:
    /**
     * @brief Input Manager Constructor
     */
    template <typename T>
    static T _inputData;
    InputManager();

    /**
     * Receive input from user
     * Usage: ```receiveInput(message);```
     */
    static void receiveInput(const string& message);

    /**
     * Receive input from user
     * Usage: ```receiveIntInput(message);```
     */
    static void receiveIntInput(const string& message);

    /**
     * Receive input from user
     * Usage: ```receiveFloatInput(message);```
     */
    static void receiveFloatInput(const string& message);

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
     * @brief Check if the string is a boolean
     * @return true and false if a boolean, exception if not
     */
    static bool receiveBooleanInput(const string& message);

    static void BuyItemsValidation();

private:
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