#include "mayor.hpp"


void Mayor::PrintBuildingRecipe(){
    cout << "Resep bangunan yang ada: \n";
    int i = 1;
    for (auto& building : GameData::_buildingConfig){
        cout << "    ";
        cout << i << ". " << building.getNama() << " (";
        cout << building.getHarga() << " gulden, ";
        for (auto& item : building.getRecipe()){
            cout << item.first << " " << item.second;
            if (item != *building.getRecipe().rbegin()) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
        i++;
    }
}

void Mayor::bangun() {

    PrintBuildingRecipe();

    cout << "Pilih bangunan yang ingin dibangun: ";
    InputManager::receiveStringInput();

    // Local Variable
    int kekuranganUang = 0;
    map<string, int> kekuranganBarang;

    // Check if the choice is valid
    for (auto & i : GameData::_buildingConfig){
        if (InputManager::_inputData<string> == i.getNama()){
            try{
                // Check if the player has enough money and items
                if (Keuangan.GetMoney() < i.getHarga()){
                    kekuranganUang = i.getHarga() - Keuangan.GetMoney();
                }

                storage.getItemsPointer();
                for (auto& item : i.getRecipe()){
                    if (storage.getItemsPointer().find(item.first) == storage.getItemsPointer().end()){
                        kekuranganBarang[item.first] = item.second;
                    } else if (storage.getItemsPointer()[item.first].size() < item.second){
                        kekuranganBarang[item.first] = item.second - storage.getItemsPointer()[item.first].size();
                    }
                }

                if (kekuranganUang != 0 || !kekuranganBarang.empty()){
                    throw NotEnoughGuldenOrItemException(kekuranganUang,kekuranganBarang);
                }

                // Deduct money and items
                Keuangan.kurangUang(i.getHarga());
                for (auto& item : i.getRecipe()){
                    for (int j = 0; j < item.second; j++){
                        storage.deleteItem(item.first);
                    }
                }

                cout << "Bangunan berhasil dibangun!" << endl;
                return;

            } catch (GameException& e){
                cout << e.what() << endl;
                return;
            }
        }
    }

    cout << "Anda tidak memiliki resep untuk bangunan tersebut." << endl;
}

Mayor::Mayor(const string& nama, int weight, int keuangan, int n_storage, int m_storage) : People(nama,weight,keuangan,1,n_storage,m_storage){}

string Mayor::getNameByCode(const std::string &) const {
    return "";
}

void Mayor::tambahPemain(roundRobin<People *> *listPlayer) {
    cout << "Masukkan jenis pemain: ";
    string pekerjaan;
    cin >> pekerjaan;
    cout << endl;

    cout << "Masukkan nama pemain: ";
    string nama;
    cin >> nama;
    cout << endl;

    // TODO : MAKE static const constructor with default value from game data.
    if (pekerjaan == "farmer"){
        listPlayer->add(new Farmer(nama, 50, 100, 3, 3, 3, 3));
    } else if (pekerjaan == "stockman"){
        listPlayer->add(new Stockman(nama, 50, 100, 3, 3, 3, 3));
    } else if (pekerjaan == "mayor"){
        listPlayer->add(new Mayor(nama, 50, 100, 3, 3));
    } else {
        cout << "Pekerjaan tidak valid." << endl;
    }
}

