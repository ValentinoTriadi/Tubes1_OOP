#include "class/Manager/GameManager/GameManager.hpp"
#include "class/UI/MainWindow.h"
#include <iostream>

int main() {
    //Init srand
    srand(static_cast<unsigned>(time(nullptr)));

    //Init Game engine
    MainWindow gameWindow;

    //Game loop
    while (gameWindow.running() && !gameWindow.getEndGame())
    {
        //Update
        gameWindow.update();

        //Render
        gameWindow.render();
    }

    return 0;
}
