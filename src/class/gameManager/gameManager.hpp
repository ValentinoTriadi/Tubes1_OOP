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