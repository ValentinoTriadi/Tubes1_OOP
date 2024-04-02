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
        /**
         * @brief Constructs a new StateManager object.
         */
        StateManager();

        /**
         * @brief Destructor for the StateManager class.
         */
        ~StateManager();

        /**
         * Saves the current state of the manager to a file.
         */
        void saveState();

        /**
         * Loads the state of the manager from a file or creates a new state if the file does not exist.
         */
        void loadState();
    private:
        vector<People*> _listPlayer;
        map<Item*, int> _listItemToko;
    
        /**
         * Converts the given indices (i, j) to a slot string.
         *
         * @param i The row index.
         * @param j The column index.
         * @return The slot string representation of the indices.
         */
        string idxToSlot(int i, int j);

        /**
         * Sets the state of the manager to its default state.
         */
        void defaultState();

        /**
         * Loads data from a file.
         * This function is responsible for loading data from a file and updating the state accordingly.
         * It should be called when the application starts or when the user requests to load data from a file.
         */
        void loadFromFile();

        /**
         * Reads shop data from the specified file.
         * 
         * @param file The input file stream to read from.
         */
        void readShop(ifstream& file);

        /**
         * Reads a Farmer object from the given file and initializes its attributes.
         *
         * @param file The input file stream to read from.
         * @param name The name of the farmer.
         * @param money The amount of money the farmer has.
         * @param weight The weight of the farmer.
         * @param gameConfig The game configuration vector.
         * @return A pointer to the created Farmer object.
         */
        Farmer* readFarmer(ifstream& file, string name, int money, int weight, vector<int> gameConfig);


        /**
         * Reads the data of a Mayor from the given file and initializes a Mayor object with the read data.
         * 
         * @param file The input file stream to read the data from.
         * @param name The name of the Mayor.
         * @param money The amount of money the Mayor has.
         * @param weight The weight of the Mayor.
         * @param gameConfig A vector containing the game configuration data.
         * @return A pointer to the created Mayor object.
         */
        Mayor* readMayor(ifstream& file, string name, int money, int weight, vector<int> gameConfig);


        /**
         * @class Stockman
         * @brief Represents a stockman in the game.
         * 
         * The Stockman class is responsible for managing the stock of items in the game.
         * It keeps track of the available items, their quantities, and their prices.
         * 
         * The class provides methods for reading the stockman's information from a file,
         * as well as methods for accessing and modifying the stock.
         */
        Stockman* readStockman(ifstream& file, string name, int money, int weight, vector<int> gameConfig);

        /**
         * Retrieves an item by its name.
         *
         * @param name The name of the item to retrieve.
         * @return A pointer to the item with the specified name, or nullptr if no such item exists.
         */
        Item* getItemByName(string name);
};

#endif