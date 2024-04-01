#include "../container.hpp"
#include "../../item/farmEntity/farmEntity.hpp"
#include "../../item/farmEntity/plant/plant.hpp"
#include <set>
#include <map>


class Ladang : public Container {
    public:
            /**
             * @brief Default constructor for the Ladang class.
             */
            Ladang();

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
             */
            friend std::ostream& operator<<(std::ostream& os, const Ladang& ladang);

        private:
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
            bool isReadyToHarvest(Item* item) const;
};