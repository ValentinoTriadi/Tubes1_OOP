#ifndef GAMEEXCEPTION_HPP
#define GAMEEXCEPTION_HPP

#include <iostream>
#include <utility>
#include <map>
using namespace std;

class GameException
{
public:
    virtual string what() = 0;
};

class StateConfigException : public GameException
{ // utk continue game
    string what() override
    {
        return "State is unavailable";
    }
};

class AddUserException : public GameException
{ // utk add user
public:
    string what() override
    {
        return "Invalid user type";
    }
};

class MenuException : public GameException
{ // utk mayor menu & stockman menu & farmer menu
private:
    string message;

public:
    explicit MenuException(const string& additionalMessage = "Invalid Input")
    {
        message = additionalMessage;
    }
    string what() override
    {
        return message;
    }
};

class RunException : public GameException
{ // utk mayor run & stockman run & farmer run
private:
    string message;

public:
    explicit RunException(const string& additionalMessage = "Invalid Type of Run")
    {
        message = additionalMessage;
    }
    string what() override
    {
        return message;
    }
};


class FarmerException : public GameException
{ // utk farmer tanam
  // blm
};


/*
 * EXCEPTION IN CLASS PEOPLE
*/
class PeopleException : public GameException {
public:
string what() override {
    return "People Exception Error";
}
};

class FoodEmptyException : public GameException {
    public:
    string what() override {
        return "Kamu mengambil harapan kosong dari penyimpanan.\nSilahkan masukan slot yang berisi makanan.\n";
    }
};

class InvalidFoodTypeException : public GameException {
    public:
    string what() override {
        return "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!\nSilahkan masukan slot yang berisi makanan.\n";
    }
};

class StorageEmptyException : GameException {
    public:
    string what() override {
        return "Penyimpanan kosong!";
    }
};

class StorageFullException : public GameException {
    public:
    string what() override {
        return "Jumlah penyimpanan tidaak cukup!";
    }
};

class NotEnoughMoneyException : public GameException {
    public:
    string what() override {
        return "Uang tidak cukup.";
    }
};


// * EXCEPTION IN CLASS STOCKMAN
class StockmanException : public GameException {
    private:
        string message1;
        string message2;

    public:
        StockmanException(string message1, string message2){
            this->message1 = std::move(message1);
            this->message2 = std::move(message2);
        }
        string what() override{
            return "Tidak ada " + message1 + " di " + message2;
        }
};

class KosongException : public GameException {
    private:
        string message;

    public:
        KosongException(string message){
            this->message = std::move(message);
        }
        string what() override{
            return message + " kosong";
        }
};

class NotException : public GameException {
    private:
        string message;
    public:
        NotException(string message){
            this->message = std::move(message);
        }
        string what() override{
            return "Bukan " + message;
        }
};

class PetakSudahTerisiException : public GameException {
    public:
        string what() override {
            return "Petak sudah terisi";
        }
};

class HewanMakanException : public GameException {
    private:
        string message;
    public:
        HewanMakanException(string message){
            this->message = std::move(message);
        }
        string what() override {
            return "Hewan ini hanya bisa makan " + message;
        }
};

class AnimalNotFoundException : public GameException {
    public:
        string what() override {
            return "Tidak ada hewan yang bisa dipanen";
        }
};

class NotValidException : public GameException {
    private:
        string message;
    public:
        NotValidException(string message){
            this->message = std::move(message);
        }
        string what() override {
            return message + " tidak valid";
        }
};

class PetakMelebihiException : public GameException {
    public:
        string what() override {
            return "Jumlah petak melebihi yang siap dipanen";
        }
};

class AnimalCodeException : public GameException {
    public:
        string what() override {
            return "Hewan di slot bukanlah hewan yang dipilih";
        }
};

class NotReadyHarvestedException : public GameException {
    public:
        string what() override {
            return "Hewan belum siap dipanen";
        }
};

/*
 * Class Exception untuk Mayor
 */
class NotEnoughGuldenOrItemException : public GameException {
    int money = 0;
    const std::map<string,int>& barang{};

    public:

        NotEnoughGuldenOrItemException() = default;
        NotEnoughGuldenOrItemException(int money , const std::map<string,int>& barang) : money(money), barang(barang) {};

        string what() override {
            string message = "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
            if (money > 0) {
                message += to_string(money) + " gulden, ";
            }
            for (auto& item : barang) {
                message += to_string(item.second) + " " + item.first;
                if (item != *barang.rbegin()) {
                    message += ", ";
                }
            }
            message += "!";
            return message;
        }
};

#endif
