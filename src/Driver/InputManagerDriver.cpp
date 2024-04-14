#include "InputManager.hpp"

using namespace std;
int main()
{
    cout << "Test ReceiveInput : " << endl;
    InputManager::receiveInput();
    cout << "Result: " << endl;
    cout << InputManager::_inputData<string> << endl;

    cout << "Test New Game Input: " << endl;
    InputManager::NewGameInput();

    cout << "Test Mayor Menu : " << endl;
    InputManager::MayorMenuInputValidation();

    cout << "Test Stockman Menu: " << endl;
    InputManager::StockmanMenuInputValidation();

    cout << "Test Farmer Menu: " << endl;
    InputManager::FarmerMenuInputValidation();

    return 0;
}