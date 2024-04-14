#ifndef PETERNAKAN_HPP
#define PETERNAKAN_HPP

#include "../container.hpp"
#include "../../item/farmEntity/farmEntity.hpp"
#include "../../item/farmEntity/animal/animal.hpp"
#include <set>
#include <map>


class   Peternakan : public Container {
    public:
            /**
             * @brief Default constructor for the Peternakan class.
             */
            Peternakan();

            /**
             * @brief Constructs a Peternakan object with the specified number of rows and columns.
             *
             * @param row The number of rows in the peternakan.
             * @param col The number of columns in the peternakan.
             */
            Peternakan(int row, int col);

            /**
             * @brief Destructor for the Peternakan class.
             *
             * This destructor is responsible for cleaning up any resources
             * allocated by the Peternakan class.
             */
            ~Peternakan();

            /**
             * @brief Copy constructor for the Peternakan class.
             *
             * This constructor initializes a new Peternakan object with the same
             * attributes as the specified Peternakan object.
             *
             * @param peternakan The Peternakan object to be copied.
             */
            Peternakan(const Peternakan& peternakan);

            /**
             * @brief Show animal in the peternakan
             */
            void showAnimal();

            /**
             * @brief Get the animal in the peternakan
             */
            std::map<std::string, int> getHarvest();

            /**
             * @brief Set the item at the specified position in the peternakan.
             *
             * This function sets the item at the specified position (i, j) in the peternakan.
             * The item is represented by a pointer to an object of type Item.
             *
             * @param i The row index of the position.
             * @param j The column index of the position.
             * @param item A pointer to the item to be set.
             */
            friend std::ostream& operator<<(std::ostream& os, const Peternakan& ladang);

            /**
             * @brief Assignment operator for the Peternakan class.
             * 
             * This operator assigns the values of the given Peternakan object to the current object.
             * 
             * @param peternakan The Peternakan object to be assigned.
             * @return A reference to the current Peternakan object after assignment.
             */
            Peternakan& operator=(const Peternakan& peternakan);

            /**
             * @brief Mencari apakah ada hewan yang siap dipanen.
             * @return true jika ada hewan yang siap dipanen, false jika tidak ada hewan yang siap dipanen
             */
            bool isAnyHarvestable();

            // Override the setItem method from the Container class. To cache harvestable.
            map<string, int> getHarvestable();

            bool isAnyEmpty();

            /**
             * Checks if the given item is ready to be harvested.
             *
             * @param item The item to check.
             * @return True if the item is ready to be harvested, false otherwise.
             */
            static bool isReadyToHarvest(Item* item) ;

private:


            /**
             * Prints the specified row of the container to the output stream.
             *
             * @param os The output stream to print to.
             * @param i The index of the row to print.
             * @return The modified output stream.
             */
            std::ostream& printRow(std::ostream& os, int i) const;

};

#endif