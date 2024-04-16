#ifndef INPUT_EXCEPTION_HPP
#define INPUT_EXCEPTION_HPP
#include <string>
#include "GameException.hpp"

class InputException : public GameException
{
private:
    std::string messages;

public:
    explicit InputException(const std::string &message) : messages(message){};

    std::string what() override
    {
        return messages;
    }
};

#endif