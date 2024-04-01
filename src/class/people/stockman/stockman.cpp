#include "stockman.hpp"

Stockman::Stockman(const int weight, const int Keuangan, const int Type , const int n_penyimpanan, const int m_penyimpanan, const int n_peternakan, const int m_peternakan) : People(weight, Keuangan, Type, n_penyimpanan, m_penyimpanan){
    this->peternakan = Peternakan(n_peternakan, m_peternakan);
};

Stockman::~Stockman() = default;

bool Stockman::CheckHewan(const string& kode){
    bool found = false;
    for (int i = 0; i < GameData::_animalConfig.size(); i++) {
        if (GameData::_animalConfig[i].getCode() == kode) {
            found = true;
            break;
        }
    }
    return found;
}

void Stockman::cetakPeternakan(){
    cout << peternakan;
}

void Stockman::ternak(){
    // List semua hewan yang ada di inventory
    vector<pair<int,int>> hewanInventory;

    bool found = false;
    for (int i = 0; i < storage.getRow(); i++) {
        for (int j = 0; j < storage.getCol(); j++) {
            if (storage(i,j) != nullptr && CheckHewan(storage(i,j)->getCode())){
                found = true;
                hewanInventory.push_back(pair<int,int>(i,j));
            }
        }
    }
    if (!found) {
        // TODO : EXCEPTION
        throw "Tidak ada hewan di penyimpanan";
    }

    this->cetakPenyimpanan();

    // TODO: tambah hewan di peternakan + pilih tempatnya
    cout << "Slot: ";
    string slot;
    cin >> slot;
    int slotIndexi = slot[0] - 'A';
    int slotIndexj = (slot[1] - '0')*10 + slot[2] - '0' - 1;

    // TODO: throw eror kalo udh diisi
    // SUCCESS
    // TODO: isi peternakan, ilangin storage
}

void Stockman::memberiPangan(){
    // TODO: Check di peternakan ada hewan ga
    // TODO: throw eror kalo gada atau salah pilih slot
    // TODO: check inventory ada makanan ga
    // TODO: throw eror kalo gaada, atau kalo pilih yg kosong atau pilih yg bukan tipenya
    // SUCCESS
    // TODO: tambahin berat
}

void Stockman::panen(){
    // TODO: Check yang siap di panen + tampilin
    // TODO: validasi input ( nomor hewan + jumlah + petak yg mana)
    // TODO: validasi inventory
    // SUCCESS
    // TODO: ilangin field + masukin inventory
}

void Stockman::pungutPajak(){
    // 
}
