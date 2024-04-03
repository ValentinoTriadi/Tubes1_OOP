#include "mayor.hpp"
#include <queue>
#include <algorithm>
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

    PrintBuildingRecipe();

    cout << "Pilih bangunan yang ingin dibangun: ";
    InputManager::receiveStringInput();

    // Local Variable
    int kekuranganUang = 0;
    map<string, int> kekuranganBarang;

    // Check if the choice is valid
    for (auto &i : GameData::_buildingConfig)
    {
        if (InputManager::_inputData<string> == i.getNama())
        {
            try
            {
                // Check if the player has enough money and items
                if (Keuangan.GetMoney() < i.getHarga())
                {
                    kekuranganUang = i.getHarga() - Keuangan.GetMoney();
                }

                storage.getItemsPointer();
                for (auto &item : i.getRecipe())
                {
                    if (storage.getItemsPointer().find(item.first) == storage.getItemsPointer().end())
                    {
                        kekuranganBarang[item.first] = item.second;
                    }
                    else if (storage.getItemsPointer()[item.first].size() < item.second)
                    {
                        kekuranganBarang[item.first] = item.second - storage.getItemsPointer()[item.first].size();
                    }
                }

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
                        storage.deleteItem(item.first);
                    }
                }

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

void Mayor::tambahPemain(roundRobin<People *> *listPlayer)
{
    cout << "Masukkan jenis pemain: ";
    string pekerjaan;
    InputManager::receiveStringInput();
    pekerjaan = DataConverter::LowerCase(InputManager::_inputData<string>);
    cout << endl;

    cout << "Masukkan nama pemain: ";
    string nama;
    InputManager::receiveStringInput();
    nama = DataConverter::LowerCase(InputManager::_inputData<string>);
    cout << endl;

    // TODO : MAKE static const constructor with default value from game data.
    if (pekerjaan == "farmer")
    {
        listPlayer->add(new Farmer(nama, 50, 100, 3, 3, 3, 3));
    }
    else if (pekerjaan == "stockman")
    {
        listPlayer->add(new Stockman(nama, 50, 100, 3, 3, 3, 3));
    }
    else if (pekerjaan == "mayor")
    {
        listPlayer->add(new Mayor(nama, 50, 100, 3, 3));
    }
    else
    {
        cout << "Pekerjaan tidak valid." << endl;
    }
}

void Mayor::TagihPajak(roundRobin<People *> *listPlayer)
{
    int totalPajak = 0;

    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;

    vector<pair<People *, int>> playerPajak;

    for (auto &player : *listPlayer)
    {
        if (player->GetType() != 1)
        {
            int JumlahPajak = player->getStatusKeuangan().hitungPajak();
            if (JumlahPajak > player->GetKeuangan())
            {
                JumlahPajak = player->GetKeuangan();
            }
            player->pungutPajak(JumlahPajak);
            totalPajak += JumlahPajak;
            playerPajak.push_back(std::make_pair(player, JumlahPajak));
        }
    }

    std::cout << "Berikut adalah detil dari pemungutan pajak: " << std::endl;

    // Sort Player berdasarkan jumlah pajak, jika sama bandingkan dengan leksikografiknya
    std::sort(playerPajak.begin(), playerPajak.end(),
              [](const auto &a, const auto &b)
              {
                  if (a.second == b.second)
                  {
                      return a.first->GetName() < b.first->GetName();
                  }
                  return a.second < b.second;
              });

    for (int i = 1; i <= playerPajak.size(); i++)
    {
        // Farmer
        string job;
        if (playerPajak[i].first->GetType() == 2)
        {
            job = "Petani";
        }
        else
        {
            job = "Peternak";
        }
        cout << "\t" << i << ". " << playerPajak[i].first->GetName() << " - " << job << ": " << playerPajak[i].second << " gulden";
    }

    cout << "Negara mendapatkan pemasukan sebesar " << totalPajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}