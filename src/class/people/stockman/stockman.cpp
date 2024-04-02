#include "stockman.hpp"

Stockman::Stockman(const string& name, int weight, int Keuangan,int n_penyimpanan,int m_penyimpanan,int n_peternakan,int m_peternakan) : People(name,weight, Keuangan, 3, n_penyimpanan, m_penyimpanan){
    this->peternakan = Peternakan(n_peternakan, m_peternakan);
};

Stockman::~Stockman() = default;

bool Stockman::CheckHewan(const string& kode){
    bool found = false;
    for (auto & i : GameData::_animalConfig) {
        if (i.getCode() == kode) {
            found = true;
            break;
        }
    }
    return found;
}

string Stockman::itos(int i, int j){
    string slot = "";
    slot += (char)(i + 'A');
    string temp = to_string(j+1);
    if (temp.length() == 1) slot += "0";
    slot += temp;
    return slot;
}

void Stockman::cetakPeternakan(){
    cout << peternakan << endl;
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

    cetakPenyimpanan();

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

    cetakPeternakan();

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
    
    // TODO: pilih petak + throw eror kalo gada atau salah pilih petak
    cetakPeternakan();
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
    cetakPenyimpanan();
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
    map<string, int> animals;
    // Check di peternakan ada hewan yang bisa dipanen ga + count yang bisa dipanen
    bool found = false;
    for (int i = 0; i < peternakan.getRow(); i++) {
        for (int j = 0; j < peternakan.getCol(); j++) {
            if (peternakan(i,j) != nullptr){
                Animal animal = dynamic_cast<Animal&>(*peternakan(i,j));
                if (animal.getWeight() >= animal.getHarvestLimit()){
                    found = true;
                    if (animals.find(animal.getCode()) == animals.end()){
                        animals[animal.getCode()] = 1;
                    } else {
                        animals[animal.getCode()]++;
                    }
                }
            }
        }
    }
    if (!found) {
        // TODO : EXCEPTION
        throw "Tidak ada hewan yang bisa dipanen";
    }

    cetakPeternakan();
    peternakan.showAnimal();

    // Check yang siap di panen + tampilin
    map<string, int>::iterator it;
    int i = 0;
    cout << endl << "Pilih hewan siap panen yang kamu miliki" << endl;
    for (it = animals.begin(); it != animals.end(); it++){
        i++;
        cout << "  " << i << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
    }
    
    // validasi input ( nomor hewan + jumlah + petak yg mana)
    int n;
    cout << "Nomor hewan yang ingin dipanen: ";
    cin >> n;
    cout << endl;
    if (n <= 0 || n > animals.size()){
        // TODO : EXCEPTION
        throw "Nomor hewan tidak valid";
    }

    // get count petak yang siap dipanen
    it = animals.begin();
    for (int i = 1; i < n; i++){
        it++;
    }
    string codeAnimal = it->first;
    // TODO:get name by code
    string namaAnimal = "";
    int countPetak = it->second;

    int c;
    cout << "Berapa petak yang ingin dipanen: ";
    cin >> c;
    cout << endl;
    if (c <= 0){
        // TODO : EXCEPTION
        throw "Jumlah petak tidak valid";
    } else if (c > countPetak){
        // TODO : EXCEPTION
        throw "Jumlah petak melebihi yang siap dipanen";
    }


    // validasi inventory
    if (storage.getCellKosong() < c){
        // TODO : EXCEPTION
        throw "Jumlah penyimpanan tidak cukup!";
    }


    // validasi petak yang dipilih
    vector<string> tempSlot;
    cout << "Pilih petak yang ingin dipanen: " << endl;
    for (int i = 0; i < c; i++) {
        cout << "Petak ke-" << i+1 << ": ";
        string slot;
        cin >> slot;
        cout << endl;
        int slotIndexi = (int)(slot[0] - 'A');
        int slotIndexj = stoi(slot.substr(1, 2)) - 1;
        if (peternakan(slotIndexi, slotIndexj) == nullptr){
            // TODO : EXCEPTION
            throw "Petak kosong";
        } else {
            Animal animal = dynamic_cast<Animal&>(*peternakan(slotIndexi, slotIndexj));
            if (animal.getCode() != codeAnimal){
                // TODO : EXCEPTION
                throw "Hewan di slot bukanlah hewan yang dipilih";
            } else if (animal.getWeight() < animal.getHarvestLimit()){
                // TODO : EXCEPTION
                throw "Hewan belum siap dipanen";
            }
            tempSlot.push_back(slot);
        }
    }

    // SUCCESS
    // ilangin field + masukin inventory
    int tempProductIndex;
    for (int i = 0; i < GameData::_productConfig.size(); i++) {
        if (GameData::_productConfig[i].getType() == "PRODUCT_ANIMAL" && GameData::_productConfig[i].getOrigin() == namaAnimal){
            tempProductIndex = i;
            break;
        }
    }
    Product tempProduct = GameData::_productConfig[tempProductIndex];

    cout << c << " petak hewan " << codeAnimal << " pada petak ";
    for (int i = 0; i < c; i++) {
        cout << tempSlot[i];
        if (i != c-1) {
            cout << ", ";
        }
        // TODO : Insert to inventory
        storage.setItem(&tempProduct);
        peternakan.deleteItem(tempSlot[i]);
    }                                                       
    cout << " telah dipanen!" << endl;

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
