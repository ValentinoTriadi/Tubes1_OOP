#include "stockman.hpp"
#include "../../exception/GameException.hpp"

Stockman::Stockman(const string& name, int weight, int Keuangan,int n_penyimpanan,int m_penyimpanan,int n_peternakan,int m_peternakan) : People(name,weight, Keuangan, 3, n_penyimpanan, m_penyimpanan){
    this->peternakan = Peternakan(n_peternakan, m_peternakan);
};

Stockman::~Stockman() = default;

bool Stockman::CheckHewan(const string& kode){
    // bool found = false;
    // for (auto & i : GameData::_animalConfig) {
    //     if (i.getCode() == kode) {
    //         found = true;
    //         break;
    //     }
    // }
    // return found;

    // Optimized version
    // find_if -> find from start to end of vector which meets the lambda function condition
    if (find_if(GameData::_animalConfig.begin(), GameData::_animalConfig.end(), [&kode](const Animal& animal) { return animal.getCode() == kode; }) != GameData::_animalConfig.end())
       return true;
    return false;
}

string Stockman::getNameByCode(const string& code) const {
    try {
        for (auto & i : GameData::_animalConfig) {
            if (i.getCode() == code) {
                return i.getNama();
            }
        }
        throw NotFoundException("Kode Hewan");
    } catch (GameException& e) {
        cout << e.what() << endl;
        return "";
    }
}

void Stockman::cetakPeternakan(){
    cout << peternakan << endl;
}

void Stockman::ternak(){
    try {
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
            throw NotInException("tumbuhan", "penyimpanan");
        }

        cout << "Pilih hewan dari penyimpanan" << endl;
        cetakPenyimpanan();

        // Ambil input dari user simpan dalam variable slot
        // Input berformat char int (B10)
        cout << "Slot: ";
        pair<int, int> slotIndex = DataConverter::GetSingleRowCol();

        // Validate slot
        if (storage(slotIndex.first, slotIndex.second) == nullptr) {
            throw KosongException("Slot" + DataConverter::itos(slotIndex.first, slotIndex.second));
        } else if (!CheckHewan(storage(slotIndex.first, slotIndex.second)->getCode())) {
            throw NotException("hewan");
        }

        cout << "Pilih petak tanah yang akan ditinggali" << endl;

        cetakPeternakan();

        cout << "Petak tanah: ";
        pair <int, int> petakIndex = DataConverter::GetSingleRowCol();

        if (this->peternakan(petakIndex.first, petakIndex.second) != nullptr) {
            throw PetakSudahTerisiException(DataConverter::itos(petakIndex.first, petakIndex.second));
        } else {
            // SUCCESS
            this->peternakan.setItem(petakIndex.first, petakIndex.second, storage(slotIndex.first, slotIndex.second));
            this->storage.deleteItem(slotIndex.first, slotIndex.second);
        }
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void Stockman::memberiPangan(){
    try{
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
            throw NotInException("hewan", "peternakan");
        }
        
        // TODO: pilih petak + throw eror kalo gada atau salah pilih petak
        cetakPeternakan();
        cout << "Petak kandang: ";
        pair <int, int> petakIndex = DataConverter::GetSingleRowCol();

        if (this->peternakan(petakIndex.first, petakIndex.second) == nullptr) {
            throw KosongException("Petak " + DataConverter::itos(petakIndex.first, petakIndex.second));
        }

        Animal animal = dynamic_cast<Animal&>(*this->peternakan(petakIndex.first, petakIndex.second));
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
            throw NotInException("makanan", "penyimpanan");
        }

        // throw error kalo pilih yg kosong atau pilih yg bukan tipenya
        cout << "Pilih pangan yang akan diberikan" << endl;
        cetakPenyimpanan();
        pair<int, int> slotIndex = DataConverter::GetSingleRowCol();

        // Validasi slot kosong
        if (storage(slotIndex.first, slotIndex.second) == nullptr) {
            throw KosongException("Slot " + DataConverter::itos(slotIndex.first, slotIndex.second));
        }
        // Validasi slot bukan product
        if (storage(slotIndex.first, slotIndex.second)->getItemType() != 0){
            throw NotException("product");
        }
        // Validasi tipe makanan
        Product temp = dynamic_cast<Product&>(*storage(slotIndex.first, slotIndex.second));
        if (temp.getType() == "PRODUCT_MATERIAL_PLANT"){
            throw NotException("makanan hewan");
        } else if (animal.getType() == "HERBIVORE" && temp.getType() != "PRODUCT_FRUIT_PLANT") {
            throw HewanMakanException("buah");
        } else if (animal.getType() == "CARNIVORE" && temp.getType() != "PRODUCT_ANIMAL") {
            throw HewanMakanException("daging");
        }

        // SUCCESS
        // tambahin berat
        animal.setWeight(animal.getWeight() + temp.getAddedWeight());
        peternakan.setItem(petakIndex.first, petakIndex.second, &animal);
        // hapus dari penyimpanan
        storage.deleteItem(DataConverter::itos(slotIndex.first, slotIndex.second));
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void Stockman::panen(){
    try {
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
            throw FarmEntityNotFoundException("hewan");
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
        cout << "Nomor hewan yang ingin dipanen: ";
        InputManager::receiveIntInput();
        int nomor = InputManager::_inputData<int>;
        if (nomor <= 0 || nomor > animals.size()){
            throw NotValidException("Nomor hewan");
        }

        // get count petak yang siap dipanen
        it = animals.begin();
        for (int i = 1; i < nomor; i++){
            it++;
        }
        string codeAnimal = it->first;
        string namaAnimal = getNameByCode(codeAnimal);
        int countPetak = it->second;

        cout << "Berapa petak yang ingin dipanen: ";
        InputManager::receiveIntInput();
        int jumlah = InputManager::_inputData<int>;
        if (jumlah <= 0){
            throw NotValidException("Jumlah petak");
        } else if (jumlah > countPetak){
            throw PetakMelebihiException();
        }


        // validasi inventory
        if (storage.getCellKosong() < jumlah){
            throw StorageFullException();
        }


        // validasi petak yang dipilih
        vector<string> tempSlot;
        cout << "Pilih petak yang ingin dipanen: " << endl;
        for (int i = 0; i < jumlah; i++) {
            cout << "Petak ke-" << i+1 << ": ";
            pair<int, int> petakIndex = DataConverter::GetSingleRowCol();
            if (peternakan(petakIndex.first, petakIndex.second) == nullptr){
                throw KosongException("Petak" + DataConverter::itos(petakIndex.first, petakIndex.second));
            } else {
                Animal animal = dynamic_cast<Animal&>(*peternakan(petakIndex.first, petakIndex.second));
                if (animal.getCode() != codeAnimal){
                    throw NotChoosenException("Hewan");
                } else if (animal.getWeight() < animal.getHarvestLimit()){
                    throw NotReadyHarvestedException("Hewan");
                }
                tempSlot.push_back(DataConverter::itos(petakIndex.first, petakIndex.second));
            }
        }

        // SUCCESS
        // ilangin field + masukin inventory
        int tempProductIndex = -1;
        for (int i = 0; i < GameData::_productConfig.size(); i++) {
            if (GameData::_productConfig[i].getType() == "PRODUCT_ANIMAL" && GameData::_productConfig[i].getOrigin() == namaAnimal){
                tempProductIndex = i;
                break;
            }
        }
        if (tempProductIndex == -1){
            throw NotFoundException("Product");
        }
        Product tempProduct = GameData::_productConfig[tempProductIndex];

        cout << jumlah << " petak hewan " << codeAnimal << " pada petak ";
        for (int i = 0; i < jumlah; i++) {
            Product* newProduct = new Product(tempProduct);
            cout << tempSlot[i];
            if (i != jumlah-1) {
                cout << ", ";
            }
            // Delete from peternakan
            peternakan.deleteItem(tempSlot[i]);

            // Insert to inventory
            storage.setItem(newProduct);
        }                                                       
        cout << " telah dipanen!" << endl;
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void Stockman::pungutPajak(){
    int pajak = 0;
}

void Stockman::setPeternakan(const Peternakan& peternakan){
    this->peternakan = peternakan;
}

Peternakan Stockman::getPeternakan() const {
    return peternakan;
}
