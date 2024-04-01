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
    vector<People *> _listPlayer;
    People *_currentPlayer;
    int _moneyToWin;
    int _weightToWin;
    GameData _gameData;
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
    void AddUser(int, int, int);

    /**
     * Usage: ```StartTurn() and NextTurn()```
     * used for displaying menu selection for each type
     * @param type type of people
     * (1) mayor
     * (2) farmer
     * (3) stockman
    */
    void MenuSelection(const int);
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
     * Show Inventory of current player
     * Usage: ```cetakPenyimpanan;```
     */
    void cetakPenyimpanan();
    /**
     * Take tax from any player
     * Usage: ```pungutPajak();```
     */
    void pungutPajak();
    /**
     * Show Animal Field
     * Usage: ```cetakLadang();```
     */
    void cetakLadang();
    /**
     * Show Plant Field
     * Usage: ```cetakPertanian();```
     */
    void cetakPertanian();
    /**
     * Plant the plant
     * Usage: ```tanam();```
     */
    void tanam();
    /**
     * Harvest the plant
     * Usage: ```memanen();```
     */
    void memanen();
    /**
     * Give food to animal
     * Usage: ```memberiPangan();```
     */
    void memberiPangan();
    /**
     * Harvest the animal
     * Usage: ```ternak();```
     */
    void ternak();
    /**
     * Build a building
     * Usage: ```ShowStatus();```
     */
    void bangunBangunan();
    /**
     * Eat a snack
     * Usage: ```makan();```
     */
    void makan();
    /**
     * Buy an item
     * Usage: ```membeli();```
     */
    void membeli();
    /**
     * Sell an item
     * Usage: ```menjual();```
     */
    void menjual();
    /**
     * Getter for _inputChecker
     * Usage: '''GetInputChecker();'''
     */
    string GetInputChecker();
    /**
     * Read input from CLI
     * Setter for _inputChecker
     * Usage: ```ReadInput();```
     */
    void ReadInput(string);

    /**
     * validate the input whether to create new game
     * or continue the game
     */
    void StartGameValidation();

    /**
     * Start the games turn
     * Implement the menu selection for the current user
     */
    void StartTurn();
};

#endif