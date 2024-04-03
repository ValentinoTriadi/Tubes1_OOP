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
        // Check adakah hewan di penyimpanam
        bool found = storage.isAnyAnimal();
        if (!found) {
            throw NotInException("tumbuhan", "penyimpanan");
        }

        cout << "Pilih hewan dari penyimpanan" << endl;
        cetakPenyimpanan();

        // Ambil input dari user simpan dalam variable slot
        // Input berformat char int (B10)
        cout << "Slot: ";
        pair<int, int> slotIndex = DataConverter::GetSingleRowCol();

        // Valisasikan slot index
        if (slotIndex.second < 0 || slotIndex.second >= storage.getCol() || slotIndex.first < 0 || slotIndex.first >= storage.getRow()) {
            throw NotValidException("Slot");
        }

        // Validate slot
        if (storage(slotIndex.second, slotIndex.first) == nullptr) {
            throw KosongException("Slot " + DataConverter::itos(slotIndex.second, slotIndex.first));
        } else if (!CheckHewan(storage(slotIndex.second, slotIndex.first)->getCode())) {
            throw NotException("hewan");
        }

        cout << "Pilih petak tanah yang akan ditinggali\n";

        cetakPeternakan();

        cout << "Petak tanah: ";
        pair <int, int> petakIndex = DataConverter::GetSingleRowCol();

        if (petakIndex.second < 0 || petakIndex.second >= peternakan.getCol() || petakIndex.first < 0 || petakIndex.first >= peternakan.getRow()) {
            throw NotValidException("Slot");
        }

        Item * hewan;
        if (this->peternakan(petakIndex.second, petakIndex.first) != nullptr) {
            throw PetakSudahTerisiException(DataConverter::itos(petakIndex.second, petakIndex.first));
        } else {
            // SUCCESS
            hewan = storage(slotIndex.second, slotIndex.first);
            this->peternakan.setItem(petakIndex.second, petakIndex.first, hewan);
            this->storage.deleteItem(slotIndex.second, slotIndex.first);
        }

        cout << "Dengan hati-hati, kamu meletakkan seekor "<< hewan->getNama() << " di kandang.\n";
        cout <<  hewan->getNama() <<" telah menjadi peliharaanmu sekarang!" << endl;
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void Stockman::memberiPangan(){
    try{
        // Check di peternakan ada hewan ga
        bool found = peternakan.isAnyHarvestable();

        if (!found) {
            throw NotInException("hewan", "peternakan");
        }

        cetakPeternakan();
        cout << "Petak kandang: ";
        pair <int, int> petakIndex = DataConverter::GetSingleRowCol();

        if (this->peternakan(petakIndex.second, petakIndex.first) == nullptr) {
            throw KosongException("Petak " + DataConverter::itos(petakIndex.second, petakIndex.first));
        }

        Animal animal = dynamic_cast<Animal&>(*this->peternakan(petakIndex.second, petakIndex.first));
        cout << "Kamu memilih " << animal.getNama() << " untuk diberi makan." << endl;

        // check inventory ada makanan ga + throw eror kalo gaada
        found = storage.getFoodTotal() > 0;

        if (!found){
            throw NotInException("makanan", "penyimpanan");
        }

        // throw error kalo pilih yg kosong atau pilih yg bukan tipenya
        cout << "Pilih pangan yang akan diberikan" << endl;
        cetakPenyimpanan();
        pair<int, int> slotIndex = DataConverter::GetSingleRowCol();

        // Validasi slot kosong
        if (storage(slotIndex.second, slotIndex.first) == nullptr) {
            throw KosongException("Slot " + DataConverter::itos(slotIndex.second, slotIndex.first));
        }

        // Validasi slot bukan product
        if (storage(slotIndex.second, slotIndex.first)->getItemType() != 0){
            throw NotException("product");
        }

        try {
            // Validasi alokasi produk
            Product temp = dynamic_cast<Product&>(*storage(slotIndex.second, slotIndex.first));

            // Validasi tipe makanan
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
        } catch (const exception& e) {
            throw NotException("product");
        }

        peternakan.setItem(petakIndex.second, petakIndex.first, &animal);
        // hapus dari penyimpanan
        storage.deleteItem(slotIndex.second, slotIndex.first);
        cout << animal.getNama() <<" sudah diberi makan dan beratnya menjadi " << animal.getWeight() << endl;
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void Stockman::panen(){
    try {
        // Check ada hewan yang bisa dipanen
        map<string, int> animals = peternakan.getHarvestable();

        // Jika tidak ada hewan yang bisa dipanen throw error
        if (animals.empty()) {
            throw FarmEntityNotFoundException("hewan");
        }

        // Cetak peternakan
        cetakPeternakan();
        peternakan.showAnimal();

        // Cetak hewan yang bisa dipanen
        int i = 0;
        for (const auto& animal : animals){
            cout << "  " << ++i << ". " << animal.first << " (" << animal.second << " petak siap panen)" << endl;
        }

        // Input nomor hewan yang ingin dipanen
        cout << "Nomor hewan yang ingin dipanen: ";
        InputManager::receiveIntInput();
        int nomor = InputManager::_inputData<int>;
        if (nomor <= 0 || nomor > animals.size()){
            throw NotValidException("Nomor hewan");
        }

        // Ambil hewan yang dipilih
        auto it = animals.begin();
        advance(it, nomor - 1);
        string codeAnimal = it->first;
        string namaAnimal = getNameByCode(codeAnimal);
        int countPetak = it->second;

        // Input jumlah petak yang ingin dipanen
        cout << "Berapa petak yang ingin dipanen: ";
        InputManager::receiveIntInput();
        int jumlah = InputManager::_inputData<int>;
        if (jumlah <= 0 || jumlah > countPetak){
            throw PetakMelebihiException();
        }

        // Exception jika storage penuh
        if (storage.getCellKosong() < jumlah){
            throw StorageFullException();
        }

        // Input petak yang ingin dipanen
        vector<string> tempSlot;
        for (int i = 0; i < jumlah; i++) {
            cout << "Petak ke-" << i+1 << ": ";
            pair<int, int> petakIndex = DataConverter::GetSingleRowCol();
            // Validasi petak kosong
            if (peternakan(petakIndex.second, petakIndex.first) == nullptr){
                throw KosongException("Petak" + DataConverter::itos(petakIndex.second, petakIndex.first));
            } else {
                // Validasi petak bukan hewan yang dipilih
                try {
                    Animal animal = dynamic_cast<Animal&>(*peternakan(petakIndex.second, petakIndex.first));
                    if (animal.getCode() != codeAnimal || animal.getWeight() < animal.getHarvestLimit()){
                        throw NotReadyHarvestedException("Hewan");
                    }
                } catch (const exception& e) {
                    throw NotChoosenException("Hewan");
                }
                tempSlot.push_back(DataConverter::itos(petakIndex.second, petakIndex.first));
            }
        }

        // SUCCESS
        // Panen hewan
        int tempProductIndex = -1;
        for (int i = 0; i < GameData::_productConfig.size(); i++) {
            if (GameData::_productConfig[i].getType() == "PRODUCT_ANIMAL" && GameData::_productConfig[i].getOrigin() == namaAnimal){
                tempProductIndex = i;
                break;
            }
        }

        // Exception jika product tidak ditemukan
        if (tempProductIndex == -1){
            throw NotFoundException("Product");
        }
        Product tempProduct = GameData::_productConfig[tempProductIndex];

        // Masukkan hewan ke storage
        for (int i = 0; i < jumlah; i++) {
            auto* newProduct = new Product(tempProduct);
            peternakan.deleteItem(tempSlot[i]);
            storage.setItem(newProduct);
        }
        cout << jumlah << " petak hewan " << codeAnimal << " pada petak " << join(tempSlot, ", ") << " telah dipanen!" << endl;
    } catch (GameException& e) {
        cout << e.what() << endl;
    }
}

void Stockman::setPeternakan(const Peternakan& peternakan){
    this->peternakan = peternakan;
}

Peternakan Stockman::getPeternakan() const {
    return peternakan;
}

long Stockman::join(const vector<string>& vector1, const char *string) {
    long result = 0;
    for (const auto & i : vector1) {
        result += i.length();
    }
    return result;
}
