#include "StatusKeuangan.hpp"
#include "../../exception/GameException.hpp"

StatusKeuangan::StatusKeuangan(int uang) : money(uang){
}

int StatusKeuangan::hitungPajak() const{
    int kkp = money;
    for (int i = 0; i < 5; i++){
        kkp = kkp / 10;
    }
    return NonUang;
}

void StatusKeuangan::tambahUang(int val){
    money += val;
}

void StatusKeuangan::kurangUang(int val){
    if(money < val){
        throw NotEnoughMoneyException();
    }
    money -= val;
}