#include "../container.hpp"
#include "../../item/farmEntity/farmEntity.hpp"
#include "../../item/farmEntity/animal/animal.hpp"
#include <set>
#include <map>


class Peternakan : public Container {
    public:
            Peternakan();
            Peternakan(int row, int col);
            ~Peternakan();
            void showAnimal();

            std::map<std::string, int> getHarvest();

            friend std::ostream& operator<<(std::ostream& os, const Peternakan& ladang);

        private:
            std::ostream& printRow(std::ostream& os, int i) const;
            bool isReadyToHarvest(Item* item) const;
};