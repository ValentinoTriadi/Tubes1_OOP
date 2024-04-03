#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../../people/people.hpp"
#include "../../people/farmer/farmer.hpp"
#include "../../people/mayor/mayor.hpp"
#include "../../people/stockman/stockman.hpp"
#include "../../container/container.hpp"
#include "../../container/ladang/ladang.hpp"
#include "../../container/peternakan/peternakan.hpp"
#include "../../gameData/gameData.hpp"


class StateManager {
    public:

        static vector<People*> _listPlayer;
        static map<Item*, int> _listItemToko;

        /**
         * @brief Constructs a new StateManager object.
         */
        StateManager();

        /**
         * @brief Destructor for the StateManager class.
         */
        ~StateManager();

        /**
         * @brief Save the current state of the game.
         */
        static void saveState();

        /**
         * @brief Load the previous state of the game.
         */
        static void loadState();
    private:

        /**
         * @brief Load the state of the game from a file.
         *
         * @param i The row index of the item.
         * @param j The column index of the item.
         * @return The slot of the item.
         */
        static string idxToSlot(int i, int j);

        /**
         * @brief Load the state of the game from a file.
         *
         */
        static void defaultState();

        /**
         * @brief Load the state of the game from a file.
         */
        static void loadFromFile();

        /**
         * @brief Read the shop from a file.
         *
         * @param file The file to read from.
         */
        static void readShop(ifstream& file);


        /**
         * @brief Read the player from a file.
         *
         * @param file The file to read from.
         * @param name The name of the player.
         * @param money The money of the player.
         * @param weight The weight of the player.
         * @param gameConfig The game configuration.
         * @return The player.
         */
        static Farmer* readFarmer(ifstream& file, string name, int money, int weight, vector<int> gameConfig);

        /**
         * @brief Read the player from a file.
         * @param file the file to read from
         * @param name the name of the player
         * @param money the money of the player
         * @param weight the weight of the player
         * @param gameConfig the game configuration
         * @return
         */
        static Mayor* readMayor(ifstream& file, string name, int money, int weight, vector<int> gameConfig);

        /**
         * @brief Read the player from a file.
         * @param file the file to read from
         * @param name the name of the player
         * @param money the money of the player
         * @param weight the weight of the player
         * @param gameConfig the game configuration
         * @return
         */
        static Stockman* readStockman(ifstream& file, string name, int money, int weight, vector<int> gameConfig);

        /**
         * @brief Get the item by name.
         *
         * @param name The name of the item.
         * @return The item.
         */
        static Item* getItemByName(const string& name);

    static void saveLadang(ofstream &file, Farmer *temp);

    static void savePeternakan(ofstream &file, Stockman *temp);
};

#endif