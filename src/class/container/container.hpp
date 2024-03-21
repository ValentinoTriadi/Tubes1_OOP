#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

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

    //Getter
    int getRow() const;
    int getCol() const;
    virtual Item* operator()(int i, int j);

    //Method
    friend ostream& operator<<(ostream& os, const Container& container);

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


#endif // __CONTAINER_HPP__
