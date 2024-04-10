#include "mayor.hpp"
#include <queue>
#include <algorithm>
#include "../../gameData/gameData.hpp"
void Mayor::PrintBuildingRecipe()
{
    cout << "Resep bangunan yang ada: \n";
    int i = 1;
    for (auto &building : GameData::_buildingConfig)
    {
        cout << "    ";
        cout << i << ". " << building.getNama() << " (";
        cout << building.getHarga() << " gulden, ";
        for (auto &item : building.getRecipe())
        {
            cout << item.first << " " << item.second;
            if (item != *building.getRecipe().rbegin())
            {
                cout << ", ";
            }
        }
        cout << ")" << endl;
        i++;
    }
}

void Mayor::bangun()
{
    // Check if the player has any slot left
    if (storage.getCellKosong()){
        cout << "Anda tidak memiliki slot kosong untuk bangunan!" << endl;
        return;
    }

    PrintBuildingRecipe();
    InputManager::receiveInput("Pilih bangunan yang ingin dibangun: ");

    // Local Variable
    int kekuranganUang = 0;
    map<string, int> kekuranganBarang;
    map<string, vector<Item *>> itemsPointer = storage.getItemsPointer();

    // Check if the choice is valid
    for (auto &i : GameData::_buildingConfig)
    {
        if (InputManager::_inputData<string> == i.getNama())
        {
            try
            {
                // Check if the player has enough money
                if (Keuangan.GetMoney() < i.getHarga())
                {
                    kekuranganUang = i.getHarga() - Keuangan.GetMoney();
                }

                // Check if the player has enough items
                for (auto &item : i.getRecipe())
                {
                    // If the item is not in the storage
                    if (itemsPointer.find(item.first) == itemsPointer.end())
                    {
                        kekuranganBarang[item.first] = item.second;
                    }
                    // If the item is in the storage but not enough
                    else if ((int) itemsPointer[item.first].size() < item.second)
                    {
                        kekuranganBarang[item.first] = item.second - (int) itemsPointer[item.first].size();
                    }
                }

                // If there is any lack of money or items
                if (kekuranganUang != 0 || !kekuranganBarang.empty())
                {
                    throw NotEnoughGuldenOrItemException(kekuranganUang, kekuranganBarang);
                }

                // Deduct money and items
                Keuangan.kurangUang(i.getHarga());
                for (auto &item : i.getRecipe())
                {
                    for (int j = 0; j < item.second; j++)
                    {
                        try {
                            storage.deleteItemByName(item.first);
                        } catch (GameException &e) {
                            cout << e.what() << endl;
                            return;
                        }
                    }
                }

                // Add the building to the storage
                storage.setItem(new Building(i.getId(), i.getCode(), i.getNama(), i.getHarga(), i.getRecipe() ));
                cout << "Bangunan berhasil dibangun!" << endl;
                return;
            }
            catch (GameException &e)
            {
                cout << e.what() << endl;
                return;
            }
        }
    }
    cout << "Anda tidak memiliki resep untuk bangunan tersebut." << endl;
}

Mayor::Mayor(const string &nama, int weight, int keuangan, int n_storage, int m_storage) : People(nama, weight, keuangan, 1, n_storage, m_storage) {}

string Mayor::getNameByCode(const std::string &) const {
    return "";
}

void Mayor::tambahPemain(roundRobin<People *> *listPlayer) {

    if (GetKeuangan() < 50)
    {
        cout << "Uang Anda tidak cukup untuk menambahkan pemain!" << endl;
        return;
    }

    vector<int> gameConfig = GameData::_gameConfig;

    string pekerjaan;
    InputManager::receiveInput("Masukkan jenis pemain: ");
    pekerjaan = DataConverter::LowerCase(InputManager::_inputData<string>);

    string nama;
    InputManager::receiveInput("Masukkan nama pemain: ");
    nama = InputManager::_inputData<string>;

    if (pekerjaan == "farmer" || pekerjaan == "petani")
    {
        listPlayer->add(new Farmer(nama, 40, 50, gameConfig[2], gameConfig[3], gameConfig[4], gameConfig[5]));

    }
    else if (pekerjaan == "stockman" || pekerjaan == "peternak")
    {
        listPlayer->add(new Stockman(nama, 40, 50, gameConfig[2], gameConfig[3], gameConfig[6], gameConfig[7]));
    } else
    {
        cout << "Pekerjaan tidak valid." << endl;
        return;
    }

    getStatusKeuangan().kurangUang(50);
    cout << "Pemain berhasil ditambahkan!" << endl;
}

void Mayor::TagihPajak(roundRobin<People *> *listPlayer)
{
    int totalPajak = 0;
    vector<pair<People *, int>> playerPajak;

    cout << "Cring cring cring...\n";
    cout << "Pajak sudah dipungut!\n\n";

    for (auto &player : *listPlayer)
    {
        if (player->GetType() != 1)
        {
            player->HitungNonUang();
            int JumlahPajak = min(player->getStatusKeuangan().hitungPajak(), player->GetKeuangan());
            player->getStatusKeuangan().kurangUang(JumlahPajak);
            totalPajak += JumlahPajak;
            playerPajak.emplace_back(player, JumlahPajak);
        }
    }

    cout << "Berikut adalah detil dari pemungutan pajak:\n";

    sort(playerPajak.rbegin(), playerPajak.rend(),
         [](const auto &a, const auto &b)
         {
             return a.second == b.second ? a.first->GetName() > b.first->GetName() : a.second > b.second;
         });

    for (int i = 0; i < (int) playerPajak.size(); i++)
    {
        string job = playerPajak[i].first->GetType() == 2 ? "Petani" : "Peternak";
        cout << "\t" << i+1 << ". " << playerPajak[i].first->GetName() << " - " << job << ": " << playerPajak[i].second << " gulden\n";
    }

    cout << "Negara mendapatkan pemasukan sebesar " << totalPajak << " gulden." << endl;
}