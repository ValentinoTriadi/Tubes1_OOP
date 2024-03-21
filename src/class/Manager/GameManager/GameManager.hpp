//
// Created by Ojan on 3/21/2024.
//

#ifndef Game_Manager_
#define Game_Manager_

#include "../../gameData/gameData.hpp"
#include "../../people/people.hpp"
#include "../StateManager/StateManager.hpp"
#include <vector>

class GameManager : public StateManager {
private :
    People _currentPlayer;
    int _moneyToWin = 0;
    int _weightToWin = 0;
    GameData _gameData;

    void WinCheck();
    void ReadConfig();
    void ShowMenu();
    void StartNewGame();
    void ContinueGame();
    void ReadInput();
    void EndGame();

public :
    void nextTurn();
    void cetakPenyimpanan();
    void pungutPajak();
    void cetakLadang();
    void cetakPertanian();
    void tanam();
    void ternak();
    void bangunBangunan();
    void makan();
    void memberiPangan();
    void membeli();
    void menjual();
    void memanen();
};

#endif
