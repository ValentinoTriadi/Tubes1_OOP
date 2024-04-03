#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <vector>
#include <string>
#include "../../utils/DataConverter/DataConverter.hpp"

class InputManager
{
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
    static bool receiveBooleanInput();

    static void BuyItemsValidation();

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
    static void MembeliInputValidationPickingItems(int ItemsMaxSize);
    /**
     * @brief Used in membeli and menjual to validate Quantity input
     */
    static void QuantityValidation(int maxQuantity);
    /**
     * @brief Validate User Input for only accepting Valid Item Quantity to sell. e.g quantity > 0 and quantity < max slot
     */
    static void MenjualInputValidationQuantity(int maxSlot);

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