#include "peternakan.hpp"

Peternakan::Peternakan() : Container()
{
    // Inisialisasi Peternakan
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = nullptr;
        }
    }
}

Peternakan::Peternakan(int row, int col) : Container(row, col)
{
    // Inisialisasi Peternakan
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = nullptr;
        }
    }
}

Peternakan::Peternakan(const Peternakan &peternakan) : Container(peternakan) {}

Peternakan::~Peternakan() {}

Peternakan &Peternakan::operator=(const Peternakan &peternakan)
{
    // Copy the attributes of the specified peternakan object
    this->row = peternakan.row;
    this->col = peternakan.col;
    this->cellKosong = peternakan.cellKosong;

    // Clear the items vector and resize it to the new size
    this->items.clear();
    this->items.resize(row, vector<Item *>(col, nullptr));

    // Copy the items from the specified peternakan object
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = peternakan.items[i][j];
        }
    }

    return *this;
}

bool Peternakan::isAnyHarvestable()
{
    for (const std::vector<Item *> &row : items)
    {
        for (Item *const &item : row)
        {
            if (item != nullptr && isReadyToHarvest(item))
            {
                return true;
            }
        }
    }
    return false;
}

ostream &Peternakan::printRow(ostream &os, int row) const
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

void Peternakan::showAnimal()
{
    // Menampilkan hewan yang ada di peternakan
    set<string> temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // Jika ada hewan di peternakan
            if (items[i][j] != nullptr)
            {

                // If the item code is not in the set
                if (temp.find(items[i][j]->getCode()) == temp.end())
                {

                    // Insert the item code into the set
                    temp.insert(items[i][j]->getCode());
                    std::cout << " - " << items[i][j]->getCode() << " : " << items[i][j]->getNama() << endl;
                }
            }
        }
    }
}

map<string, int> Peternakan::getHarvest()
{
    // Menampilkan hewan yang siap dipanen
    map<string, int> temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] != nullptr)
            {

                // If the item is ready to harvest
                if (isReadyToHarvest(items[i][j]))
                    temp[items[i][j]->getCode()]++;
            }
        }
    }

    return temp;
}

ostream &operator<<(ostream &os, const Peternakan &ladang)
{
    os << "=================[ Peternakan ]==================" << endl
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

bool Peternakan::isReadyToHarvest(Item *item)
{
    Animal *animal = dynamic_cast<Animal*>(item);

    // Check if the animal is ready to be harvested
    return animal->getWeight() >= animal->getHarvestLimit();
}

map<string, int> Peternakan::getHarvestable()
{
    map<string, int> animals;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] != nullptr)
            {
                // Increment the count of the item code if it is ready to harvest
                if (isReadyToHarvest(items[i][j]))
                    animals[items[i][j]->getCode()]++;
            }
        }
    }
    return animals;
}

bool Peternakan::isAnyEmpty()
{
    return cellKosong > 0;
}
