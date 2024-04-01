#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#include <string>
class InputManager {
    public:
        static std::string _inputData;

        InputManager();

        /*
         * Receive input from user
         * Usage: ```receiveInput();```
         */
        static void receiveInput();


        /*
        * validate the first input user to define whether the
        * the user will create new games or continue the games
        */
        static void NewGameInputValidation(const std::string& data);
};

#endif