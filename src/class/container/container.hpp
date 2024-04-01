#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "../item/item.hpp"
#include "../gameData/gameData.hpp"


class Container {
public:
    //Constructor
    Container();
    /**
     * @brief Constructs a Container object with the specified number of rows and columns.
     *
     * @param row The number of rows in the container.
     * @param col The number of columns in the container.
     */
    Container(int row, int col);

    // Destructor
    ~Container();

    //Setter
    void setRow(int row);
    void setCol(int col);
    /**
     * @brief Sets the item at the specified position in the container.
     * 
     * This function sets the item at the specified position (i, j) in the container.
     * The item is represented by a pointer to an object of type Item.
     * 
     * @param i The row index of the position.
     * @param j The column index of the position.
     * @param item A pointer to the item to be set.
     */
    void setItem(int i, int j, Item* item);

    /**
     * @brief Sets an item in the container at the specified slot.
     * 
     * This function sets the given item in the container at the specified slot.
     * 
     * @param slot The slot where the item will be set.
     * @param item A pointer to the item to be set.
     */
    void setItem(string slot, Item* item);

    /**
     * @brief Deletes an item at the specified position in the container.
     * 
     * This function removes the item at the specified position (i, j) in the container.
     * 
     * @param i The row index of the item to be deleted.
     * @param j The column index of the item to be deleted.
     */
    void deleteItem(int i, int j);

    /**
     * @brief Deletes an item from the container.
     * 
     * This function removes the item located at the specified slot from the container.
     * 
     * @param slot The slot of the item to be deleted.
     */
    void deleteItem(string slot);

    //Getter
    [[nodiscard]] int getRow() const;
    [[nodiscard]] int getCol() const;

    /**
     * @brief Returns the item at the specified position in the container.
     * 
     * This function returns the item at the specified position (i, j) in the container.
     * 
     * @param i The row index of the item.
     * @param j The column index of the item.
     * @return A pointer to the item at the specified position.
     */
    Item* operator()(int i, int j);

    //Method
    /**
     * @brief Overloads the << operator to allow printing the Container object.
     * 
     * @param os The output stream to write to.
     * @param container The Container object to be printed.
     * @return The output stream after writing the Container object.
     */
    friend ostream& operator<<(ostream& os, const Container& container);

    /**
     * @brief Overloads the = operator to allow copying the Container object.
     * 
     * @param container The Container object to be copied.
     * @return The copied Container object.
     */
    Container& operator=(Container& container);

    /**
     * @brief Overloads the [] operator to allow accessing the items in the container.
     *
     * This function returns a vector of items in the specified row of the container.
     *
     * @param i The row index of the items to be accessed.
     * @return A vector of items in the specified row.
     */
    vector<Item*> operator[](int i);
    

protected:
    /* data */
    vector<vector<Item*> > items;
    int row = 0;
    int col = 0;
    int cellKosong;

    //Helper
    ostream& printColumnName(ostream& os) const;
    ostream& printSeparator(ostream& os) const;
    virtual ostream& printRow(ostream& os, int row) const;
};


#endif // CONTAINER_HPP_