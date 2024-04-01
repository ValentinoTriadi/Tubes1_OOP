#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>
#include <iostream>
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
         * @param ItemType Type of Item (0: Product, 1: Animal, 2: Plant)
        */
        Item(int, string, string, int, int);
        /**
         * Destructor
         * !```Don't call this function directly```!
        */


        virtual ~Item();
        //! GETTER !//

        /**
         * Get ID of Item
         * @return ID of Item
        */
        [[nodiscard]] int getId() const;
        /**
         * Get Code of Item
         * @return Code of Item
        */
        [[nodiscard]] string getCode() const;
        /**
         * Get Name of Item
         * @return Name of Item
        */
        [[nodiscard]] string getNama() const;
        /**
         * Get Price of Item
         * @return Price of Item
        */
        [[nodiscard]] int getHarga() const;
        /*
        * 0 = Product
        * 1 = Animal
        * 2 = Plant
        * 3 = Building
        */
        [[nodiscard]] int getItemType() const;



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

        /*
        * 0 = Product
        * 1 = Animal
        * 2 = Plant
        * 3 = Building
        */
        const int ItemType;
};

#endif