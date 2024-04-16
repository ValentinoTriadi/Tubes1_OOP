#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <vector>
#include <string>
#include "../../utils/DataConverter/DataConverter.hpp"
#include "../../exception/GameException.hpp"

class InputManager
{
private:
    static std::vector<std::string> yes, no;

public:
    /**
     * @brief Input Manager Constructor
     */
    template <typename T>
    static T _inputData;
    static ifstream _file_data;
    InputManager();

    /**
     * Receive input from user
     * Usage: ```receiveInput(message);```
     */
    static void receiveInput(const string &message);

    /**
     * Receive input from user
     * Usage: ```receiveIntInput(message);```
     */
    static void receiveIntInput(const string &message);

    /**
     * Receive input from user
     * Usage: ```receiveFloatInput(message);```
     */
    static void receiveFloatInput(const string &message);

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
    static bool receiveBooleanInput(const string &message);

    /**
     * @brief Validate User Input for StateManager Load State
     */
    static void StateManagerLoadStateInputValidation();
    /**
     * @brief Validate User Input for StateManager Load State From File
     */
    static void StateManagerLoadStateFromFileInputValidation();

    /**
     * @brief Validate User Input for only accepting Valid Item to buy
     * @param ItemsMaxSize The maximum size of the list items toko
     */

    static void QuantityValidation(int maxQuantity, const string& messages);
    /**
     * @brief Validate User Input for only accepting Valid Item Quantity to sell. e.g quantity > 0 and quantity < max slot
     */
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