#include "StatusKeuangan.hpp"
#include "../../exception/GameException.hpp"

StatusKeuangan::StatusKeuangan(int uang, int type)
        : money(uang),
          ktkp(type == 2 ? 11 : (type == 3 ? 12 : 999)) {
    NonUang = 0;
}

int StatusKeuangan::hitungPajak() const{
    int kkp = money + NonUang;
    kkp -= ktkp;
    if(kkp < ktkp){
        return 0;
    }

    int tarif = 0;

    if (kkp <= 6) {
        tarif = 5;
    } else if (kkp <= 25) {
        tarif = 15;
    } else if (kkp <= 50) {
        tarif = 25;
    } else if (kkp <= 500) {
        tarif = 30;
    } else {
        tarif = 50;
    }

    int kenaPajak = (kkp * tarif) / 100;

    return kenaPajak;
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

void StatusKeuangan::SetNonUang(int s) {
    NonUang = s;
}
