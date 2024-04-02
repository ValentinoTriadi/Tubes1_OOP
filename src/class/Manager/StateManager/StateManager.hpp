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
        static void saveState();
        static void loadState();
    private:
        static vector<People*> _listPlayer;
        static map<Item*, int> _listItemToko;

        static string idxToSlot(int i, int j);

        static void defaultState();
        static void loadFromFile();
        static void readShop(ifstream& file);

        static Farmer* readFarmer(ifstream& file, string name, int money, int weight, vector<int> gameConfig);
        static Mayor* readMayor(ifstream& file, string name, int money, int weight, vector<int> gameConfig);
        static Stockman* readStockman(ifstream& file, string name, int money, int weight, vector<int> gameConfig);

        static Item* getItemByName(const string& name);
};

#endif