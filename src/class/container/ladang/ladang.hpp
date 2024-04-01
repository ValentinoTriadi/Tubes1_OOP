#include "../container.hpp"
#include "../../item/farmEntity/farmEntity.hpp"
#include "../../item/farmEntity/plant/plant.hpp"
#include <set>
#include <map>


class Ladang : public Container {
    public:
            /**
             * @brief Default constructor for the Ladang class.
             * 
             * This constructor initializes a new instance of the Ladang class.
             */
            Ladang();
            /**
             * @brief Constructs a new Ladang object with the specified number of rows and columns.
             *
             * @param row The number of rows in the Ladang.
             * @param col The number of columns in the Ladang.
             */
            Ladang(int row, int col);
            /**
             * @class Ladang
             * @brief Represents a ladang (field) object.
             * 
             * The Ladang class is responsible for managing the properties and behavior of a ladang object.
             * It provides methods to manipulate and access the ladang's data.
             */
            Ladang(const Ladang& ladang);
            /**
             * @brief Destructor for the Ladang class.
             */
            ~Ladang();
            /**
             * Displays the plants in the ladang.
             */
            void showPlant();

            /**
             * Retrieves the harvest from the ladang.
             *
             * @return A map containing the harvested items, where the key is the item name and the value is the quantity.
             */
            std::map<std::string, int> getHarvest();

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

        private:
            std::ostream& printRow(std::ostream& os, int i) const;
            bool isReadyToHarvest(Item* item) const;
};