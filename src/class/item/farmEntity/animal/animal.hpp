#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "../farmEntity.hpp"

class Animal : public FarmEntity {
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
        Animal(const int, const string&, const string&, const int, const string&, const int, const int);
        /**
         * Destructor
         * !```Don't call this function directly```!
         */
        ~Animal();


        //! GETTER, SETTER !//

        /**
         * Get Weight of Animal
         * @return Weight of Animal
         */
        int getWeight() const;
        /**
         * Set Weight of Animal
         * @param Weight Weight of Animal
         */
        void setWeight(int);


        //! Method !//


        /**
         * Print Animal to the screen
         */
        void print() const;

    private:
        int Weight;

};


#endif