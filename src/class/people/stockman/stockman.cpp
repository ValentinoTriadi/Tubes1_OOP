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
    // Check di peternakan ada hewan ga
    bool found = false;
    for (int i = 0; i < peternakan.getRow(); i++) {
        for (int j = 0; j < peternakan.getCol(); j++) {
            if (peternakan(i,j) != nullptr){
                found = true;
                break;
            }
        }
    }
    if (!found) {
        // TODO : EXCEPTION
        throw "Tidak ada hewan di peternakan";
    }

    // TODO: pilih slot + throw eror kalo gada atau salah pilih slot
    string petak;
    cout << "Petak kandang: ";
    cin >> petak;
    int petakIndexi = (int)(petak[0] - 'A');
    int petakIndexj = stoi(petak.substr(1, 2)) - 1;

    if (this->peternakan(petakIndexi, petakIndexj) == nullptr) {
        // TODO : EXCEPTION
        throw "Petak kosong";
    }

    Animal animal = dynamic_cast<Animal&>(*this->peternakan(petakIndexi, petakIndexj));
    cout << "Kamu memilih " << animal.getNama() << " untuk diberi makan." << endl;

    // check inventory ada makanan ga + throw eror kalo gaada
    found = false;
    for (int i = 0; i < storage.getRow(); i++) {
        for (int j = 0; j < storage.getCol(); j++) {
            if (storage(i,j) != nullptr && storage(i,j)->getItemType() == 0){
                Product temp = dynamic_cast<Product&>(*storage(i,j));
                if (temp.getType() == "PRODUCT_ANIMAL" || temp.getType() == "PRODUCT_FRUIT_PLANT") {
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found){
        // TODO : EXCEPTION
        throw "Tidak ada makanan di penyimpanan";
    }

    // throw error kalo pilih yg kosong atau pilih yg bukan tipenya
    cout << "Pilih pangan yang akan diberikan" << endl;
    cout << peternakan;
    string slot;
    int slotIndexi = (int)(slot[0] - 'A');
    int slotIndexj = stoi(slot.substr(1, 2)) - 1;

    // Validasi slot kosong
    if (storage(slotIndexi, slotIndexj) == nullptr) {
        // TODO : EXCEPTION
        throw "Slot kosong";
    }
    // Validasi slot bukan product
    if (storage(slotIndexi, slotIndexj)->getItemType() != 0){
        // TODO : EXCEPTION
        throw "Bukan product";
    }
    // Validasi tipe makanan
    Product temp = dynamic_cast<Product&>(*storage(slotIndexi, slotIndexj));
    if (temp.getType() == "PRODUCT_MATERIAL_PLANT"){
        // TODO : EXCEPTION
        throw "Bukan makanan hewan";
    } else if (animal.getType() == "HERBIVORE" && temp.getType() != "PRODUCT_FRUIT_PLANT") {
        // TODO : EXCEPTION
        throw "Hewan ini hanya bisa makan buah";
    } else if (animal.getType() == "CARNIVORE" && temp.getType() != "PRODUCT_ANIMAL") {
        // TODO : EXCEPTION
        throw "Hewan ini hanya bisa makan daging";
    }

    // SUCCESS
    // tambahin berat
    animal.setWeight(animal.getWeight() + temp.getAddedWeight());
    peternakan.setItem(petakIndexi, petakIndexj, &animal);
    // hapus dari penyimpanan
    storage.deleteItem(slot);
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

void Stockman::setPeternakan(const Peternakan& peternakan){
    this->peternakan = peternakan;
}

Peternakan Stockman::getPeternakan() const {
    return peternakan;
}
