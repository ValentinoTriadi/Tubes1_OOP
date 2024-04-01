#ifndef __STATEMANAGER_HPP__
#define __STATEMANAGER_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../people/people.hpp"
#include "../people/farmer/farmer.hpp"
#include "../people/mayor/mayor.hpp"
#include "../people/stockman/stockman.hpp"
#include "../container/container.hpp"


class StateManager {
    public:
        StateManager();
        ~StateManager();
        void saveState();
        void loadState(const vector<int>& gameConfig);
    private:
        vector<People*> _listPlayer;
        vector<Item*> _listItemToko;

        void defaultState(const vector<int>& gameConfig);
        void loadFromFile(const vector<int>& gameConfig);
};

#endif