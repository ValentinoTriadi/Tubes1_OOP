#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include <iostream>

class StateManager {
    public:
        StateManager();
        ~StateManager();
        void saveState();
        static void loadState();
    private:
        
};

#endif