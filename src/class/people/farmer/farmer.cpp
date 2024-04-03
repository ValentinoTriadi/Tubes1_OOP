#include "farmer.hpp"

#include "../../item/farmEntity/plant/plant.hpp"

Farmer::Farmer() = default;

/**
 *  Mencetak Ladang dari petani
 */
void Farmer::cetakLadang() const
{
    std::cout << ladang;
}

bool Farmer::CheckTumbuhan(const string &kode)
{
    // bool found = false;
    // for (auto & i : GameData::_plantConfig) {
    //     if (i.getCode() == kode) {
    //         found = true;
    //         break;
    //     }
    // }
    // return found;

    // Optimized version
    // find_if -> find from start to end of vector which meets the lambda function condition
    if (find_if(GameData::_plantConfig.begin(), GameData::_plantConfig.end(), [&kode](const Plant &plant)
                { return plant.getCode() == kode; }) != GameData::_plantConfig.end())
        return true;
    return false;
}

string Farmer::getNameByCode(const string &code) const
{
    try
    {
        for (auto &i : GameData::_plantConfig)
        {
            if (i.getCode() == code)
            {
                return i.getNama();
            }
        }
        throw NotFoundException("Kode Tumbuhan");
    }
    catch (GameException &e)
    {
        std::cout << e.what() << endl;
        return "";
    }
}

/**
 *  Menanam tanaman
 */
void Farmer::tanam()
{
    try
    {
        // Check adakah tumbuhan di penyimpanan
        bool found = false;
        for (int i = 0; i < storage.getRow(); i++)
        {
            for (int j = 0; j < storage.getCol(); j++)
            {
                if (storage(i, j) != nullptr && CheckTumbuhan(storage(i, j)->getCode()))
                {
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            throw NotInException("tumbuhan", "penyimpanan");
        }

        // Pilih tanaman dari penyimpanan
        std::cout << "Pilih tanaman dari penyimpanan" << endl;
        cetakPenyimpanan();

        // Ambil input dari user simpan dalam variable slot
        // Input berformat char int (B10)
        std::cout << "Slot: ";
        pair<int, int> slotIndex = DataConverter::GetSingleRowCol();

        // Validasi
        if (storage(slotIndex.first, slotIndex.second) == nullptr)
        {
            throw KosongException("Slot" + DataConverter::itos(slotIndex.first, slotIndex.second));
        }
        else if (!CheckTumbuhan(storage(slotIndex.first, slotIndex.second)->getCode()))
        {
            throw NotException("tumbuhan");
        }

        // Akses item
        Item *tanaman = storage(slotIndex.first, slotIndex.second);

        std::cout << "Kamu memilih " << tanaman->getNama() << endl;

        // Ambil input petak yang akan ditanami
        std::cout << "Pilih petak tanah yang akan ditanami" << endl;
        cetakLadang();

        // Ambil input dari user simpan dalam variable slot
        // Input berformat char int (B10)
        std::cout << "Petak tanah: ";
        pair<int, int> petakIndex = DataConverter::GetSingleRowCol();

        // Validasi
        if (this->ladang(petakIndex.first, petakIndex.second) != nullptr)
        {
            throw PetakSudahTerisiException(DataConverter::itos(petakIndex.first, petakIndex.second));
        }
        else
        {
            // SUCCESS
            this->ladang.setItem(petakIndex.first, petakIndex.second, storage(slotIndex.first, slotIndex.second));
            this->storage.deleteItem(slotIndex.first, slotIndex.second);
        }
    }
    catch (GameException &e)
    {
        std::cout << e.what() << endl;
    }
}

void Farmer::panen()
{
    try
    {
        map<string, int> plants;
        // Check di ladang ada tumbuhan yang bisa dipanen ga + count yang bisa dipanen
        bool found = false;
        for (int i = 0; i < ladang.getRow(); i++)
        {
            for (int j = 0; j < ladang.getCol(); j++)
            {
                if (ladang(i, j) != nullptr)
                {
                    Plant plant = dynamic_cast<Plant &>(*ladang(i, j));
                    if (plant.getAge() >= plant.getHarvestLimit())
                    {
                        found = true;
                        if (plants.find(plant.getCode()) == plants.end())
                        {
                            plants[plant.getCode()] = 1;
                        }
                        else
                        {
                            plants[plant.getCode()]++;
                        }
                    }
                }
            }
        }
        if (!found)
        {
            throw FarmEntityNotFoundException("tumbuhan");
        }

        // Cetak ladang + barang yang bisa diambil
        cetakLadang();
        ladang.showPlant();

        std::cout << "Pilih tanaman tanah yang akan dipanen" << endl;

        // Check yang siap di panen + tampilin
        map<string, int>::iterator it;
        int i = 0;
        std::cout << endl
                  << "Pilih hewan siap panen yang kamu miliki" << endl;
        for (it = plants.begin(); it != plants.end(); it++)
        {
            i++;
            std::cout << "  " << i << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
        }

        std::cout << "Nomor tanaman yang ingin dipanen: ";
        InputManager::receiveIntInput();
        int nomor = InputManager::_inputData<int>;

        // Validasi input
        if (nomor <= 0 || nomor > plants.size())
        {
            throw NotValidException("Nomor tumbuhan");
        }

        // get count petak yang siap dipanen
        it = plants.begin();
        for (int i = 1; i < nomor; i++)
        {
            it++;
        }
        string codePlant = it->first;
        int countPetak = it->second;
        string namePlant = getNameByCode(codePlant);

        std::cout << "Berapa petak yang ingin dipanen: ";
        InputManager::receiveIntInput();
        int jumlah = InputManager::_inputData<int>;

        // Validasi input
        if (jumlah <= 0)
        {
            throw NotValidException("Jumlah petak");
        }
        else if (jumlah > countPetak)
        {
            throw PetakMelebihiException();
        }

        // validasi inventory
        if (storage.getCellKosong() < jumlah)
        {
            throw StorageFullException();
        }

        vector<string> tempSlot;
        std::cout << "Pilih petak yang ingin dipanen: " << endl;
        // Cetak petak yang bisa dipanen
        for (int i = 0; i < jumlah; i++)
        {
            std::cout << "Petak ke-" << i + 1 << ": ";
            pair<int, int> petakIndex = DataConverter::GetSingleRowCol();
            if (ladang(petakIndex.first, petakIndex.second) == nullptr)
            {
                throw KosongException("Petak" + DataConverter::itos(petakIndex.first, petakIndex.second));
            }
            else
            {
                Plant plant = dynamic_cast<Plant &>(*ladang(petakIndex.first, petakIndex.second));
                if (plant.getCode() != codePlant)
                {
                    throw NotChoosenException("Tumbuhan");
                }
                else if (plant.getAge() < plant.getHarvestLimit())
                {
                    throw NotReadyHarvestedException("Tumbuhan");
                }
                tempSlot.push_back(DataConverter::itos(petakIndex.first, petakIndex.second));
            }
        }

        // SUCCESS
        // ilangin field + masukin inventory
        int tempProductIndex = -1;
        for (int i = 0; i < GameData::_productConfig.size(); i++)
        {
            if (GameData::_productConfig[i].getType() == "PRODUCT_FRUIT_PLANT" && GameData::_productConfig[i].getOrigin() == namePlant)
            {
                tempProductIndex = i;
                break;
            }
        }
        if (tempProductIndex == -1)
        {
            throw NotFoundException("Product");
        }
        Product tempProduct = GameData::_productConfig[tempProductIndex];

        std::cout << jumlah << " petak hewan " << codePlant << " pada petak ";
        for (int i = 0; i < jumlah; i++)
        {
            Product *newProduct = new Product(tempProduct);
            std::cout << tempSlot[i];
            if (i != jumlah - 1)
            {
                std::cout << ", ";
            }
            // Delete from ladang
            ladang.deleteItem(tempSlot[i]);

            // Insert to inventory
            storage.setItem(newProduct);
        }
        std::cout << " telah dipanen!" << endl;
    }
    catch (GameException &e)
    {
        std::cout << e.what() << endl;
    }
}

void Farmer::pungutPajak(int jumlah)
{
    People::pungutPajak(jumlah);
}

Farmer::Farmer(const string &name, int weight, int Keuangan, int n_penyimpanan, int m_penyimpanan, int n_ladang, int m_ladang) : People(name, weight, Keuangan, 2, n_penyimpanan, m_penyimpanan)
{
    this->ladang = Ladang(n_ladang, m_ladang);
}

void Farmer::setLadang(const Ladang &Setladang)
{
    this->ladang = Setladang;
}

Ladang Farmer::getLadang() const
{
    return ladang;
}

Farmer::~Farmer() = default;