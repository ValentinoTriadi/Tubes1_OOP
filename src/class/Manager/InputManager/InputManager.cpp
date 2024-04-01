#include <iostream>
#include "InputManager.hpp"


InputManager::InputManager() = default;

std::string InputManager::_inputData;

void InputManager::receiveInput(){
    std::getline(std::cin, _inputData);
}

void InputManager::NewGameInputValidation(const std::string& data){
    if(data == "0"){
        
    }
}