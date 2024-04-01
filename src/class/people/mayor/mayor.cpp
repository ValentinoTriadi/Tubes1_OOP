#include "mayor.hpp"
#include "../../gameData/gameData.hpp"

void Mayor::bangun() {
    cout << "Resep bangunan yang ada: " << endl;

    // Print building recipe
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

    cout << "Pilih bangunan yang ingin dibangun: ";
    string choice;
    cin >> choice;
    cout << endl;

    // Local Variable
    int kekuranganUang = 0;
    map<string, int> kekuranganBarang;

    // Check if the choice is valid
    for (auto & i : GameData::_buildingConfig){
        if (choice == i.getNama()){
            // Check if the player has enough money and items
            if (Keuangan.GetMoney() < i.getHarga()){
                kekuranganUang = i.getHarga() - Keuangan.GetMoney();
            }
            for (auto& item : i.getRecipe()){
                // TODO : Get list of items in storage and check if the player has enough items
            }

            // TODO : Exception handling

            Keuangan.kurangUang(i.getHarga());
            for (auto& item : i.getRecipe()){
                // TODO : Remove items from storage
            }

            cout << "Bangunan berhasil dibangun!" << endl;
            return;
        }
    }

    cout << "Anda tidak memiliki resep untuk bangunan tersebut." << endl;
    return;
}

Mayor::Mayor(const string& nama, int weight, int keuangan, int n_storage, int m_storage) : People(nama,weight,keuangan,1,n_storage,m_storage){}

void Mayor::tambahPemain() {

}
