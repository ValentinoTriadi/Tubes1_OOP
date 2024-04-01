#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "../container/container.hpp"
#include "Keuangan/StatusKeuangan.hpp"
#include "../container/container.hpp"

class People
{
protected:
    /**
     * Used to keep track of the number of people
     * Mainly used to automatically assign the id of people each time a new people is created
     */
    static int people_counter;

    int id;
    /**
     * Id used to create a unique identifier for certain user
     * Mainly used for identify owner of a store
     */
    Container storage;
    /**
     * Money monitor of user
     * default = 50 gulden
     */
    StatusKeuangan Keuangan;
    /**
     * weight of user
     * default = 40 kg
     */
    int Weight;
    /**
     * type of user
     * (1) mayor
     * (2) farmer
     * (3) stockman
     */
    int Type;

public:
    /**
     * @param weight saved the weight of user
     * @param Keuangan saved the money of user
     * @param Type type of user
     */
    People(int, int, int, int, int);

    People();

    /**
     * @brief Menghapus objek people
     */
    virtual ~People();

    /**
     *  @brief Mencetak penyimpanan yang dimiliki oleh people
     */
    void cetakPenyimpanan();

    /**
     *  @brief Makan
     */
    void makan();

    /**
     *  @brief Membeli
     */
    void membeli();

    /**
     *  @brief Menjual
     */
    void menjual();

    /**
     *  @brief Set container
     *  @param container container yang akan di set
     */

    [[nodiscard]] int GetWeight() const { return Weight; }

    /**
     *  @brief Get Keuangan
     *  @return Keuangan
     */
    [[nodiscard]] int GetKeuangan() { return Keuangan.GetMoney(); }

    /**
     *  @brief Get Type
     *  @return Type
     */
    [[nodiscard]] int GetType() const { return Type; }

    /**
     *  @brief Set container
     *  @param container container yang akan di set
     */
    void setStorage(const Container &);
};

#endif