#include "container.hpp"

/**
 * \brief Default constructor for the Container class.
 *
 * This constructor initializes a new instance of the Container class.
 */
Container::Container()
{
    row = 0;
    col = 0;
    cellKosong = 0;
}

/**
 * @brief Constructs a Container object with the specified number of rows and columns.
 *
 * @param row The number of rows in the container.
 * @param col The number of columns in the container.
 */
Container::Container(int row, int col)
{
    this->row = row;
    this->col = col;
    cellKosong = row * col;

    // Intialize the items vector with nullptr
    for (int i = 0; i < row; i++)
    {
        // Create a temporary vector to store the items
        vector<Item *> temp;
        for (int j = 0; j < col; j++)
        {
            // Set all items to nullptr
            temp.push_back(nullptr);
        }

        // Add the temporary vector to the items vector
        items.push_back(temp);
    }
}

/**
 * @brief Destructor for the Container class.
 *
 * This destructor is responsible for cleaning up any resources
 * allocated by the Container class.
 */
Container::~Container()
{
}

/**
 * @brief Sets the row value of the Container.
 *
 * This function sets the row value of the Container object to the specified value.
 *
 * @param row The new row value to be set.
 */
void Container::setRow(int Setrow)
{
    this->row = Setrow;
}

/**
 * @brief Sets the column value of the Container.
 *
 * This function sets the column value of the Container object to the specified value.
 *
 * @param col The new column value to be set.
 */
void Container::setCol(int Setcol)
{
    this->col = Setcol;
}

/**
 * @brief Returns the row value of the Container.
 *
 * This function returns the row value of the Container object.
 *
 * @return The row value of the Container.
 */
int Container::getRow() const
{
    return row;
}

/**
 * @brief Returns the column value of the Container.
 *
 * This function returns the column value of the Container object.
 *
 * @return The column value of the Container.
 */
int Container::getCol() const
{
    return col;
}

/**
 * @brief Returns the number of empty cells in the container.
 *
 * This function returns the number of empty cells in the container.
 *
 * @return The number of empty cells in the container.
 */
int Container::getCellKosong() const
{
    return cellKosong;
}

/**
 * @brief Sets the item at the specified row and column.
 *
 * This function sets the item at the specified row and column to the specified item.
 *
 * @param i The row index of the item.
 * @param j The column index of the item.
 * @param item The item to be set.
 */
void Container::setItem(int i, int j, Item *item)
{
    try
    {
        if (i >= row || j >= col || i < 0 || j < 0)
        {
            throw IndexOutOfBoundException();
        }

        if (items[i][j] == nullptr)
        {
            items[i][j] = item;
            cellKosong--;
        }
        else
        {
            throw PetakSudahTerisiException(DataConverter::itos(j, i));
        }
    }
    catch (IndexOutOfBoundException &e)
    {
        cout << e.what() << endl;
    }
    catch (PetakSudahTerisiException &e)
    {
        cout << e.what() << endl;
    }
}

void Container::setItem(string slot, Item *item)
{
    int i = slot[0] - 'A';
    int j = stoi(slot.substr(1, 2)) - 1;
    setItem(i, j, item);
}

void Container::setItem(Item *item)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] == nullptr)
            {
                setItem(i, j, item);
                return;
            }
        }
    }
    throw FullException("penyimpanan");
}

void Container::deleteItem(int i, int j)
{
    if (items[i][j] != nullptr)
    {
        items[i][j] = nullptr;
        cellKosong++;
    }
    else
    {
        throw KosongException("Slot " + DataConverter::itos(j, i));
    }
}

void Container::deleteItem(string slot)
{
    int j = slot[0] - 'A';
    int i = stoi(slot.substr(1, 2)) - 1;
    deleteItem(i, j);
}

void Container::deleteItemByName(string slot)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] != nullptr && items[i][j]->getNama() == slot)
            {
                deleteItem(i, j);
                return;
            }
        }
    }
    throw KosongException("Item " + slot);
}

vector<Item*> Container::getItems()
{
    vector<Item*> itemList;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (items[i][j] != nullptr)
            {
                itemList.push_back(items[i][j]);
            }
        }
    }
    return itemList;
}

map<string, vector<Item *>> Container::getItemsPointer()
{
    map<string, vector<Item *>> itemMap;

    for (std::vector<Item *> row : items)
    {
        for (Item *item : row)
        {
            if (item != nullptr)
            {
                itemMap[item->getNama()].push_back(item);
            }
        }
    }
    return itemMap;
}

map<string, int> Container::getFood()
{
    map<string, int> itemMap;
    for (std::vector<Item *> row : items)
    {
        for (Item *item : row)
        {
            // Check if item is not empty and item is a product
            if (item != nullptr && item->getItemType() == 0)
            {
                itemMap[item->getCode()]++;
            }
        }
    }
    return itemMap;
}

int Container::getFoodTotal() const
{
    int total = 0;
    for (std::vector<Item *> row : items)
    {
        for (Item *item : row)
        {
            // Check if item is not empty and item is a product
            if (item != nullptr && item->getItemType() == 0)
            {
                total++;
            }
        }
    }
    return total;
}

/**
 * @brief Returns the item at the specified row and column.
 *
 * This function returns the item at the specified row and column.
 *
 * @param i The row index of the item.
 * @param j The column index of the item.
 * @return The item at the specified row and column.
 */
Item *Container::operator()(int i, int j)
{
    return items[i][j];
}

/**
 * Prints the column name of the container.
 *
 * @param os The output stream to print the column name to.
 * @return The output stream after printing the column name.
 */
ostream &Container::printColumnName(ostream &os) const
{
    // Print spaces
    for (int i = 0; i < 3; i++)
    {
        os << " ";
    }

    // Print the column name
    char c = 'A';
    for (int i = 0; i < col; i++)
    {
        os << "   " << c << "  ";
        c++;
    }

    os << endl;
    return os;
}

/**
 * Prints the separator for the container.
 *
 * This function is responsible for printing the separator used in the container.
 * The separator is printed to the specified output stream.
 *
 * @param os The output stream to which the separator will be printed.
 * @return A reference to the output stream after printing the separator.
 */
ostream &Container::printSeparator(ostream &os) const
{
    // Print spaces
    for (int i = 0; i < 3; i++)
    {
        os << " ";
    }

    // Print the separator
    for (int i = 0; i < col; i++)
    {
        os << "+-----";
    }

    // Print the last plus sign
    os << "+" << endl;

    return os;
}

/**
 * Prints the specified row of the container.
 *
 * @param os The output stream to print to.
 * @param row The row number to print.
 * @return The output stream after printing the row.
 */
ostream &Container::printRow(ostream &os, int row) const
{
    // Handle the formatting if the row number is less than 9
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
            os << " " << items[row][i]->getCode() << " ";
        }
        else
        {
            os << "     ";
        }
    }

    os << "|" << endl;

    return os;
}

/**
 * @brief Overloaded stream insertion operator for the Container class.
 *
 * This function overloads the stream insertion operator for the Container class.
 *
 * @param os The output stream to write to.
 * @param container The Container object to write to the output stream.
 * @return The output stream.
 */
ostream &operator<<(ostream &os, const Container &container)
{
    os << "=================[ Penyimpanan ]==================" << endl
       << endl;
    // print column name
    container.printColumnName(os);
    container.printSeparator(os);

    for (int i = 0; i < container.getRow(); i++)
    {
        container.printRow(os, i);
        container.printSeparator(os);
    }

    return os;
}

/**
 * @brief Overloaded assignment operator for the Container class.
 *
 * This function overloads the assignment operator for the Container class.
 *
 * @param container The Container object to be copied.
 * @return The copied Container object.
 */
Container &Container::operator=(const Container &container)
{
    this->row = container.row;
    this->col = container.col;
    this->cellKosong = container.cellKosong;

    this->items.clear();
    this->items.resize(row, vector<Item *>(col, nullptr));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            items[i][j] = container.items[i][j];
        }
    }

    return *this;
}

bool Container::isEmpty() const
{
    for (const std::vector<Item *> &row : items)
    {
        for (const Item *item : row)
        {
            if (item != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

bool Container::isAnyAnimal()
{
    for (const std::vector<Item *> &row : items)
    {
        for (const Item *item : row)
        {
            // Check if item is not empty and item is an animal
            if (item != nullptr && item->getItemType() == 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool Container::isAnyPlant()
{
    for (const std::vector<Item *> &row : items)
    {
        for (const Item *item : row)
        {
            // Check if item is not empty and item is a plant
            if (item != nullptr && item->getItemType() == 2)
            {
                return true;
            }
        }
    }
    return false;
}
