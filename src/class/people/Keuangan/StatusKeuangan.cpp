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
        // 0 - 6
        case 0 ... 6:
            tarif = 5;
            break;
        // 6 - 25
        case 7 ... 25:
            tarif = 15;
            break;
        // 25 - 50
        case 26 ... 50:
            tarif = 25;
            break;
        // 50 - 500
        case 51 ... 500:
            tarif = 30;
            break;
        // > 500
        default:
            tarif = 35;
            break;
    }

    int kenaPajak = (kkp * tarif) / 100;

    if (kenaPajak < ktkp) {
        return 0;
    }

    return kenaPajak - ktkp ;
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

void StatusKeuangan::HitungNonUang() {

}

void StatusKeuangan::SetNonUang(int s) {
    NonUang = s;
}
