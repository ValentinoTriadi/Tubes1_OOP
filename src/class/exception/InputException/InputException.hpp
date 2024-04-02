#include "../GameException.hpp"
#include <string>

class InputException : public GameException
{
private:
    string messages;

public:
    explicit InputException(const std::string &message) : messages(message){};

    string what() override
    {
        return messages;
    }
};