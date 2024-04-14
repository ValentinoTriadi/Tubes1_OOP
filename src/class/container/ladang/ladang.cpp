#include "ladang.hpp"

Ladang::Ladang() : Container()
{
    // Inisialisasi Ladang
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = nullptr;
        }
    }
}

Ladang::Ladang(int row, int col) : Container(row, col)
{
    // Inisialisasi Ladang
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = nullptr;
        }
    }
}

Ladang::Ladang(const Ladang &ladang) : Container(ladang) {}

Ladang::~Ladang() {}

Ladang &Ladang::operator=(const Ladang &ladang)
{
    // Copy the attributes of the specified ladang object
    this->row = ladang.row;
    this->col = ladang.col;
    this->cellKosong = ladang.cellKosong;

    this->items.clear();
    this->items.resize(row, vector<Item *>(col, nullptr));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = ladang.items[i][j];
        }
    }

    this->harvestable = ladang.harvestable;
    return *this;
}

ostream &Ladang::printRow(ostream &os, int row) const
{

    if (row < 9)
    {
        os << "0";
    }

    // Print the row number
    os << row + 1 << " ";

    // Print the items in the row
    for (int i = 0; i < col; i++)
    {
        os << "|";

        // Print the item code if it is not nullptr
        if (items[row][i] != nullptr)
        {
            if (isReadyToHarvest(items[row][i]))
            {
                // Print the item code in green if it is ready to harvest
                os << "\033[32m " << items[row][i]->getCode() << "\033[0m ";
            }
            else
            {
                // Print the item code in red if it is not ready to harvest
                os << "\033[31m " << items[row][i]->getCode() << "\033[0m ";
            }
        }
        else
        {
            os << "     ";
        }
    }

    os << "|" << endl;

    return os;
}

void Ladang::showPlant()
{
    // Inisialisasi set untuk menyimpan kode tanaman yang sudah ditampilkan
    set<string> temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] != nullptr)
            {
                // Print the item code if it is not nullptr
                if (temp.find(items[i][j]->getCode()) == temp.end())
                {

                    // Insert the item code to the set
                    temp.insert(items[i][j]->getCode());
                    std::cout << " - " << items[i][j]->getCode() << " : " << items[i][j]->getNama() << endl;
                }
            }
        }
    }
}

map<string, int> Ladang::getHarvest()
{
    // Inisialisasi map untuk menyimpan kode tanaman yang siap dipanen
    map<string, int> temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] != nullptr)
            {

                // Increment the count of the item code if it is ready to harvest
                if (isReadyToHarvest(items[i][j]))
                    temp[items[i][j]->getCode()]++;
            }
        }
    }

    return temp;
}

ostream &operator<<(ostream &os, const Ladang &ladang)
{
    // Print the ladang object
    os << "=================[ Ladang ]==================" << endl
       << endl;

    ladang.printColumnName(os);
    ladang.printSeparator(os);

    for (int i = 0; i < ladang.getRow(); i++)
    {
        ladang.printRow(os, i);
        ladang.printSeparator(os);
    }

    return os;
}

bool Ladang::isReadyToHarvest(Item *item)
{
    Plant *plant = (Plant *)item;

    // Check if the item is ready to be harvested
    try {
        bool temp = plant->getAge() >= plant->getHarvestLimit();
        return temp;
    } catch (...) {
        return false;
    }
}

void Ladang::setItem(int i, int j, Item *item)
{
    Container::setItem(i, j, item);
    harvestable.emplace(item);
}

void Ladang::setItem(string slot, Item *item)
{
    Container::setItem(slot, item);
    harvestable.emplace(item);
}

void Ladang::setItem(Item *item)
{
    Container::setItem(item);
    harvestable.emplace(item);
}

void Ladang::deleteItem(int i, int j)
{
    Container::deleteItem(i, j);
    harvestable.erase(items[i][j]);
}

void Ladang::deleteItem(string slot)
{
    Container::deleteItem(slot);
    int j = slot[0] - 'A';
    int i = stoi(slot.substr(1, 2)) - 1;
    harvestable.erase(items[i][j]);
}

void Ladang::addAge()
{
    for (auto &item : harvestable)
    {
        Plant *plant = (Plant *)(item);
        try {
            plant->grow();
        } catch (...) {
            continue;
        }
    }
}