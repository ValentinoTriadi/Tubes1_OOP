#include <iostream>
#include "class/Manager/GameManager/GameManager.hpp"


int main() {
    GameManager game;

    cout << "Mau new game apa baca config bang ? " << endl;
    cout << "1. input (1) jika ingin buat game baru" << endl;
    cout << "2. input (2) jika ingin membaca berkas" << endl << endl;
    string data;
    cin >> data;
    
    game.ReadInput(data);
    game.StartGameValidation();
    return 0;
}
