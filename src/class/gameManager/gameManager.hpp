#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <vector>
#include "../people/people.hpp"
#include "../gameData/gameData.hpp"
using namespace std;

class GameManager {
    private :
        vector<People> _listPlayer;
        People _currentPlayer;
        int _moneyToWin;
        int _weightToWin;
        GameData _gameData;

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
         * Show the main menu
         * Usage: ```ShowMenu();```
        */
        void ShowMenu();
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
        /**
         * Read input from CLI
         * Usage: ```ShowStatus();```
        */
        void ReadInput();
        /**
         * End the game
         * Usage: ```ShowStatus();```
        */
        void EndGame();
    public :
        /*CTOR, DTOR*/

        /**
         * Default Constructor
         * Usage: ```GameManager gameManager;```
        */
        GameManager();

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
};

#endif