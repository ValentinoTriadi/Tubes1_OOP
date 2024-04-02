#ifndef GAMEEXCEPTION_HPP
#define GAMEEXCEPTION_HPP

#include <iostream>
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

class FarmerException : public GameException
{ // utk farmer tanam
  // blm
};

class FoodEmptyException : public GameException {
    public:
    string what() override {
        return "Kamu mengambil harapan kosong dari penyimpanan.\nSilahkan masukan slot yang berisi makanan.";
    }
};

class InvalidFoodTypeException : public GameException {
    public:
    string what() override {
        return "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!\nSilahkan masukan slot yang berisi makanan.";
    }
};

class StorageFullException : public GameException {
    public:
    string what() override {
        return "Penyimpanan penuh.";
    }
};

class NotEnoughMoneyException : public GameException {
    public:
    string what() override {
        return "Uang tidak cukup.";
    }
};



#endif
