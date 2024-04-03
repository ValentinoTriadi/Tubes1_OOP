#include "StatusKeuangan.hpp"
#include "../../exception/GameException.hpp"

StatusKeuangan::StatusKeuangan(int uang, int type)
        : money(uang),
          ktkp(type == 2 ? 11 : (type == 3 ? 12 : 999)) {
    NonUang = 0;
}

int StatusKeuangan::hitungPajak() const{
    int kkp = money + NonUang;
    if(kkp < ktkp){
        return 0;
    }

    int tarif = 0;

    switch (kkp) {
        case 0 ... 6:
            tarif = 5;
        case 7 ... 15:
            tarif = 15;
        case 16 ... 50:
            tarif = 25;
        case 51 ... 500:
            tarif = 30;
        default:
            tarif = 35;
    }

    return ((kkp * tarif) / 100) - ktkp ;
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