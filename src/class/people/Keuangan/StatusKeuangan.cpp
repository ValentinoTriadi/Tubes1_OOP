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