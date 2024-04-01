#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include "../farmEntity.hpp"

class Animal final : public FarmEntity {
    public:

        //! CTOR, DTOR !//

        /**
         * Default Constructor
         * Usage: ```Animal animal;```
         */
        Animal();
        /**
         * Constructor
         * @param Id ID of Animal
         * @param Code Code of Animal
         * @param Name Name of Animal
         * @param Price Price of Animal
         * @param Type Type of Animal
         * @param Weight Weight of Animal
         * @param HarvestLimit Harvest Limit of Animal (Minimum Age or Weight to Harvest)
         */
        Animal(int, const string&, const string&, int, const string&, int, int);
        /**
         * Destructor
         * !```Don't call this function directly```!
         */
        ~Animal() override;


        //! GETTER, SETTER !//

        /**
         * Get Weight of Animal
         * @return Weight of Animal
         */
        [[nodiscard]] int getWeight() const;
        /**
         * Set Weight of Animal
         * @param Weight Weight of Animal
         */
        void setWeight(int);


        //! Method !//


        /**
         * Print Animal to the screen
         */
        void print() const override;

    private:
        int Weight;
        string code_;
};


#endif