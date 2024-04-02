#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <string>
#include "../../Exception/GameException.hpp"
class InputManager
{
public:
    static std::string _inputData;

    InputManager();

    /**
     * Receive input from user
     * Usage: ```receiveInput();```
     */
    static void receiveInput();

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

    static void BuyItemsValidation();
};

#endif