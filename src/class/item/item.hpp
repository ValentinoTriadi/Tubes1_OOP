#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    public:
        //! CTOR, DTOR !//

        /**
         * Default Constructor
         * Usage: ```Item item;```
        */
        Item();
        /**
         * Constructor
         * @param Id ID of Item
         * @param Code Code of Item
         * @param Name Name of Item
         * @param Price Price of Item
        */
        Item(const int, const string&, const string&, const int);
        /**
         * Destructor
         * !```Don't call this function directly```!
        */
        ~Item();



        //! GETTER !//

        /**
         * Get ID of Item
         * @return ID of Item
        */
        int getId() const;
        /**
         * Get Code of Item
         * @return Code of Item
        */
        string getCode() const;
        /**
         * Get Name of Item
         * @return Name of Item
        */
        string getNama() const;
        /**
         * Get Price of Item
         * @return Price of Item
        */
        int getHarga() const;



        //! Method !//

        /**
         * Print Item
         * Usage: ```item.print();```
         * Format: 
            ```----------ITEM----------```
            ```Id: <Id>```
            ```Code: <Code>```
            ```Name: <Name>```
            ```Price: <Price>```
        */
        virtual void print() const;

    private:
        const int Id;
        const string Code;
        const string Name;
        const int Price;
};

#endif