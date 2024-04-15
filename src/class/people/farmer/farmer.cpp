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
    if (find_if(
            GameData::_plantConfig.begin(),
            GameData::_plantConfig.end(),
            [&kode](const Plant &plant) { return plant.getCode() == kode; }
        ) != GameData::_plantConfig.end())
        return true;
    return false;
}

string Farmer::getNameByCode(const string &code) const
{
    try
    {
        for (Plant &i : GameData::_plantConfig)
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

void Farmer::addPlantAge()
{
    ladang.addAge();
}

/**
 *  Menanam tanaman
 */
void Farmer::tanam()
{
    try
    {
        // Check apakah ada slot kosong di sawah
        if (ladang.getCellKosong() == 0)
        {
            throw FullException("ladang");
        }

        // Check adakah tumbuhan di penyimpanan
        bool found = storage.isAnyPlant();
        if (!found)
        {
            throw NotInException("tumbuhan", "penyimpanan");
        }

        // Pilih tanaman dari penyimpanan
        std::cout << "Pilih tanaman dari penyimpanan" << endl;
        cetakPenyimpanan();

        // Ambil input dari user simpan dalam variable slot
        // Input berformat char int (B10)
        pair<int, int> slotIndex = DataConverter::GetSingleRowCol("Slot: ");

        // Validasi slot index
        if (slotIndex.second < 0 || slotIndex.second >= storage.getRow() || slotIndex.first < 0 || slotIndex.first >= storage.getCol())
        {
            throw NotValidException("Slot");
        }
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

        pair<int, int> petakIndex = DataConverter::GetSingleRowCol("Petak tanah: ");

        // Validasi petak index
        if (petakIndex.second < 0 || petakIndex.second >= ladang.getRow() || petakIndex.first < 0 || petakIndex.first >= ladang.getCol())
        {
            throw NotValidException("Petak");
        }

        // Validasi
        if (this->ladang(petakIndex.first, petakIndex.second) != nullptr)
        {
            throw PetakSudahTerisiException(DataConverter::itos(petakIndex.first, petakIndex.second));
        }
        else
        {
            // SUCCESS
            this->ladang.setItem(petakIndex.first, petakIndex.second, tanaman);
            this->storage.deleteItem(slotIndex.first, slotIndex.second);
        }

        cout << "Cangkul, cangkul, cangkul yang dalam~!\n";
        cout << tanaman->getNama() << " berhasil ditanam!" << endl;
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
        map<string, int> plants = ladang.getHarvest();

        if (plants.empty())
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
                  << "Pilih tanaman siap panen yang kamu miliki" << endl;
        for (it = plants.begin(); it != plants.end(); it++)
        {
            i++;
            std::cout << "  " << i << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
        }

        InputManager::receiveIntInput("Nomor tanaman yang ingin dipanen: ");
        int nomor = InputManager::_inputData<int>;

        // Validasi input
        if (nomor <= 0 || nomor > (int)plants.size())
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

        InputManager::receiveIntInput("Berapa petak yang ingin dipanen: ");
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
            throw FullException("penyimpanan");
        }

        vector<string> tempSlot;
        std::cout << "Pilih petak yang ingin dipanen: " << endl;
        // Cetak petak yang bisa dipanen
        for (int i = 0; i < jumlah; i++)
        {
            try
            {
                pair<int, int> petakIndex = DataConverter::GetSingleRowCol("Petak ke-" + to_string(i + 1) + ": ");
                if (petakIndex.second < 0 || petakIndex.second >= ladang.getRow() || petakIndex.first < 0 || petakIndex.first >= ladang.getCol())
                {
                    throw NotValidException("Petak");
                }
                if (ladang(petakIndex.second, petakIndex.first) == nullptr)
                {
                    throw KosongException("Petak" + DataConverter::itos(petakIndex.second, petakIndex.first));
                }
                if (!Ladang::isReadyToHarvest(ladang(petakIndex.second, petakIndex.first)))
                {
                    throw NotReadyHarvestedException("Tumbuhan");
                }

                Plant& plant = dynamic_cast<Plant&>(*ladang(petakIndex.second, petakIndex.first));
                if (plant.getCode() != codePlant){
                    throw NotChoosenException("Tumbuhan");
                }

                tempSlot.push_back(DataConverter::itos(petakIndex.second, petakIndex.first));
            }
            catch (GameException &e)
            {
                std::cout << e.what() << endl;
                i--;
            }
        }

        // SUCCESS
        // ilangin field + masukin inventory
        int tempProductIndex = -1;
        for (int i = 0; i < (int)GameData::_productConfig.size(); i++)
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

        std::cout << jumlah << " petak Tanaman " << codePlant << " pada petak ";
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