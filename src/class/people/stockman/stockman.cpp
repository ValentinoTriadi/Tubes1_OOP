#include "stockman.hpp"

Stockman::Stockman(const string& name, int weight, int Keuangan, int Type ,int n_penyimpanan,int m_penyimpanan,int n_peternakan,int m_peternakan) : People(name,weight, Keuangan, Type, n_penyimpanan, m_penyimpanan){
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
    // Check adakah hewan di penyimpanan
    bool found = false;
    for (int i = 0; i < storage.getRow(); i++) {
        for (int j = 0; j < storage.getCol(); j++) {
            if (storage(i,j) != nullptr && CheckHewan(storage(i,j)->getCode())){
                found = true;
                break;
            }
        }
    }
    if (!found) {
        // TODO : EXCEPTION
        throw "Tidak ada hewan di penyimpanan";
    }

    this->cetakPenyimpanan();

    // Input slot
    cout << "Slot: ";
    string slot;
    cin >> slot;
    int slotIndexi = (int)(slot[0] - 'A');
    int slotIndexj = stoi(slot.substr(1, 2)) - 1;

    // Validate slot
    if (storage(slotIndexi, slotIndexj) == nullptr) {
        // TODO : EXCEPTION
        throw "Slot kosong";
    } else if (!CheckHewan(storage(slotIndexi, slotIndexj)->getCode())) {
        // TODO : EXCEPTION
        throw "Bukan hewan";
    }

    cout << "Pilih petak tanah yang akan ditinggali" << endl;

    cout << this->peternakan;

    cout << "Petak tanah: ";
    string petak;
    cin >> petak;
    int petakIndexi = (int)(petak[0] - 'A');
    int petakIndexj = stoi(petak.substr(1, 2)) - 1;

    if (this->peternakan(petakIndexi, petakIndexj) != nullptr) {
        // TODO : EXCEPTION
        throw "Petak sudah terisi";
    } else {
        // SUCCESS
        this->peternakan.setItem(petakIndexi, petakIndexj, storage(slotIndexi, slotIndexj));
        this->storage.deleteItem(slot);
    }
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
