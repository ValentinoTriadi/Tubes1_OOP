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
        StateManager();
        ~StateManager();
        void saveState();
        void loadState();
    private:
        vector<People*> _listPlayer;
        map<Item*, int> _listItemToko;

        string idxToSlot(int i, int j);

        void defaultState();
        void loadFromFile();
        void readShop(ifstream& file);

        Farmer* readFarmer(ifstream& file, string name, int money, int weight, vector<int> gameConfig);
        Mayor* readMayor(ifstream& file, string name, int money, int weight, vector<int> gameConfig);
        Stockman* readStockman(ifstream& file, string name, int money, int weight, vector<int> gameConfig);

        Item* getItemByName(string name);
};

#endif