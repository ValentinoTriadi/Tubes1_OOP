#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <vector>
#include "../../people/people.hpp"
#include "../../people/farmer/farmer.hpp"
#include "../../people/mayor/mayor.hpp"
#include "../../people/stockman/stockman.hpp"
#include "../../gameData/gameData.hpp"
#include "../InputManager/InputManager.hpp"
#include "../../exception/GameException.hpp"
#include "../../utils/roundRobin/roundRobin.hpp"
#include "../StateManager/StateManager.hpp"
using namespace std;

class GameManager
{
private:
    /*Attribute*/

    // List of player
    static roundRobin<People *> _listPlayer;
    People *_currentPlayer{};

    // Game Data
    GameData _gameData;
    Toko _toko;

    int _moneyToWin{};
    float _weightToWin{};
    vector<int> gameConfig;

    // Local Variable
    static bool _isGameOver;
    static Mayor _mayor;
    string _inputChecker;

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
     * end the game
     * Usage: ```EndGame();```|
     */
    static void EndGame();

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
     * Run the mayor selection
     * Usage: ```RunMayorSelection();```
     */
    void RunMayorSelection(int);

    /**
     * Run the farmer selection
     * Usage: ```RunFarmerSelection();```
     */
    void RunFarmerSelection(int);

    /**
     * Run the stockman selection
     * Usage: ```RunStockmanSelection();```
     */
    void RunStockmanSelection(int);

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

    /**
     * Load the game
     * Implement the load game feature
     */
    void muat();

    /**
     * Save the game
     * Implement the save game feature
     */
    static void simpan();

    void ShowCurrentPlayerInfo();

    static void addAge();

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
};

#endif