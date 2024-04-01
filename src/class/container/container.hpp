#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

#include <iostream>
#include <vector>
#include "../item/item.hpp"


class Container {
public:
    //Constructor
    Container();
    Container(int row, int col);

    // Destructor
    virtual ~Container();

    //Setter
    void setRow(int row);
    void setCol(int col);
    void setItem(int i, int j, Item& item);
    void deleteItem(int i, int j);

    //Getter
    [[nodiscard]] int getRow() const;
    [[nodiscard]] int getCol() const;
    virtual Item* operator()(int i, int j);

    //Method
    friend ostream& operator<<(ostream& os, const Container& container);
    Container& operator=(Container& container);
    

private:
    /* data */
    vector<vector<Item*> > items;
    int row;
    int col;
    int cellKosong;

    //Helper
    ostream& printColumnName(ostream& os) const;
    ostream& printSeparator(ostream& os) const;
    ostream& printRow(ostream& os, int row) const;
};


#endif // CONTAINER_HPP_