#ifndef GAMEEXCEPTION_HPP
#define GAMEEXCEPTION_HPP

#include <iostream>
using namespace std;

class GameException {
    public:
    virtual string what() = 0;
};

class StateConfigException : public GameException { //utk continue game
    string what() override {
        return "State is unavailable";
    }
};

class AddUserException : public GameException { //utk add user
    public:
    string what() override {
        return "Invalid user type";
    }
};

class MenuException : public GameException {    //utk mayor menu & stockman menu & farmer menu
    public:
    string what() override {
        return "Invalid Input";
    }
};

class FarmerException : public GameException {  //utk farmer tanam
 //blm
};



#endif
