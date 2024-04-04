#ifndef LADANG_HPP_
#define LADANG_HPP_

#include "../container.hpp"
#include "../../item/farmEntity/farmEntity.hpp"
#include "../../item/farmEntity/plant/plant.hpp"
#include <set>
#include <map>


class Ladang : public Container {
    public:

        /**
         * @brief Constructs a Ladang object with the specified number of rows and columns.
         *
         * @param row The number of rows in the ladang.
         * @param col The number of columns in the ladang.
         */
        Ladang(int row, int col);

        /**
         * @brief Destructor for the Ladang class.
         *
         * This destructor is responsible for cleaning up any resources
         * allocated by the Ladang class.
         */
        ~Ladang();

        /**
         * @brief Tanam tanaman pada ladang
         */
        void showPlant();


        /**
         * @brief Panen tanaman pada ladang
         */
        std::map<std::string, int> getHarvest();


        /**
         * @brief Set the item at the specified position in the ladang.
         *
         * This function sets the item at the specified position (i, j) in the ladang.
         * The item is represented by a pointer to an object of type Item.
         *
         * @param i The row index of the position.
         * @param j The column index of the position.
         * @param item A pointer to the item to be set.
         *
         * This constructor initializes a new instance of the Ladang class.
         */
        Ladang();

        /**
         * @class Ladang
         * @brief Represents a ladang (field) object.
         *
         * The Ladang class is responsible for managing the properties and behavior of a ladang object.
         * It provides methods to manipulate and access the ladang's data.
         */
        Ladang(const Ladang& ladang);

        /**
         * @brief Overloaded stream insertion operator for Ladang class.
         *
         * This function allows the Ladang object to be printed using the standard output stream.
         *
         * @param os The output stream object.
         * @param ladang The Ladang object to be printed.
         * @return std::ostream& The reference to the output stream object.
         */
        friend std::ostream& operator<<(std::ostream& os, const Ladang& ladang);

        /**
         * @brief Overloaded assignment operator for the Ladang class.
         *
         * This operator assigns the values of one Ladang object to another Ladang object.
         *
         * @param ladang The Ladang object to be assigned.
         * @return A reference to the assigned Ladang object.
         */
        Ladang& operator=(const Ladang& ladang);

        void setItem(int i, int j, Item* item) override;

        void setItem(string slot, Item* item) override;

        void setItem(Item* item) override;

        void deleteItem(int i, int j) override;

        void deleteItem(string slot) override;

        void addAge();

    private:

        std::set<Item*> harvestable;

        /**
         * @brief Mencetak baris dari ladang
         * @param os
         * @param i
         * @return
         */
        std::ostream& printRow(std::ostream& os, int i) const;

        /**
         * @brief Mencetak header dari ladang
         * @param os
         * @return
         */
        static bool isReadyToHarvest(Item* item) ;
};

#endif