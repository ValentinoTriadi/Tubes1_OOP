#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <vector>
#include "../../people/people.hpp"
#include "../../people/farmer/farmer.hpp"
#include "../../people/mayor/mayor.hpp"
#include "../../people/stockman/stockman.hpp"
#include "../../gameData/gameData.hpp"
using namespace std;

class GameManager
{
private:
    // List of player
    vector<People *> _listPlayer;
    People *_currentPlayer{};

    // Game Data
    GameData _gameData;
    int _moneyToWin{};
    float _weightToWin{};
    vector<int> gameConfig;

    // Local Variable
    static bool _isGameOver;
    static int _currentTurn;
    static Mayor _mayor;

    /*Method*/

    /**
     * Check if the player is winner
     * If the player is a winner, print the winner and end the game
     * Usage: ```WinCheck();```
     */
    void WinCheck();
    /**
     * Read the configuration file
     * Usage: ```ReadConfig();```
     */
    void ReadConfig();
    /**
     * End the game
     * Usage: ```EndGame();```|
     */
    void EndGame();

    /**
     * Start a new game
     * Usage: ```StartNewGame();```
     */
    void StartNewGame();
    /**
     * Continue the game
     * Usage: ```ContinueGame();```
     */
    void ContinueGame();

    /** Add user to the list_player
     * @param weight used for construct of "berat badan"
     * @param Keuangan used for construct the keuangan of people
     * @param type used for construct tipe people
     */
    void AddUser(int);

    /**
     * Usage: ```StartTurn() and NextTurn()```
     * used for displaying menu selection for each type
     * @param type type of people
     * (1) mayor
     * (2) farmer
     * (3) stockman
     */
    void MenuSelection(int);

    /**
     * Display the menu selection for mayor
     * Usage: ```MayorMenuSelection();```
     */
    void MayorMenuSelection();

    /**
     * Run the mayor selection
     * @param input the input from the user
     * Usage: ```RunMayorSelection(input);```
     */
    void RunMayorSelection(int input);

    /**
     * Display the menu selection for farmer
     * Usage: ```FarmerMenuSelection();```
     */
    void FarmerMenuSelection();

    /**
     * Display the menu selection for stockman
     * Usage: ```StockmanMenuSelection();```
     */
    void StockmanMenuSelection();

    /**
     * Run the stockman selection
     * @param input the input from the user
     * Usage: ```RunStockmanSelection(input);```
     */
    void RunStockmanSelection(int input);

    /**
     * Run the farmer selection
     * @param input the input from the user
     * Usage: ```RunFarmerSelection(input);```
     */
    void RunFarmerSelection(int input);



public:
    /*CTOR, DTOR*/

    /**
     * Default Constructor
     * Usage: ```GameManager gameManager;```
     */
    GameManager();
    /**
     * Default Destructor
     * Usage: ```GameManager gameManager;```
     */
    ~GameManager();

    /**
     * Next Turn
     * Usage: ```nextTurn();```
     */
    void nextTurn();

    /**
     * Take tax from any player
     * Usage: ```pungutPajak();```
     */
    void pungutPajak();

    /**
     * Getter for _inputChecker
     * Usage: '''GetInputChecker();'''
     */
    void StartGameValidation();

    /**
     * Start the games turn
     * Implement the menu selection for the current user
     */
    void StartTurn();

    /**
     * Run the game
     * Implement the game loop
     */
    void Run();
};

#endif
