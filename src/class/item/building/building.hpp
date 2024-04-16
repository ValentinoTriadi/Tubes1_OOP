#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include "../item.hpp"
#include <map>

class Building final : public Item {
    public:
        /**
         * @brief Construct a new Building object
         */
        Building();

        /**
         * @brief Construct a new Building object
         *
         * @param id id dari building
         * @param code code dari building
         * @param name nama dari building
         * @param price harga dari building
         * @param recipe resep dari building
         */
        Building(int, const string&, const string&, int, const map<string, int>&);

        /**
         * Copy Constructor
        */
        Building(const Building&);

        ~Building() override;

        [[nodiscard]] map<string, int> getRecipe() const;

        void print() const override;

    private:
        map<string, int> Recipe;
};

#endif