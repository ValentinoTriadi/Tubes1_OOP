#include "DataConverter.hpp"
#include <algorithm>
#include <regex>

template <>
int DataConverter::StringToNumber(const string &data)
{
    try
    {
        if (isNumber(data))
        {
            return std::stoi(data);
        }
        else
        {
            throw InputException("Input Is Not a Number");
        }
    }
    catch (GameException &i)
    {
        std::cout << i.what() << std::endl;
        return -999;
    }
}

template <>
float DataConverter::StringToNumber(const string &data)
{
    try
    {
        if (isNumber(data))
        {
            return std::stof(data);
        }
        else
        {
            throw InputException("Input Is Not a Number");
        }
    }
    catch (InputException &i)
    {
        std::cout << i.what() << std::endl;
        return -999; // ERROR Code
    }
}

bool DataConverter::isNumber(char data)
{
    return data >= '0' && data <= '9';
}

bool DataConverter::isNumber(const string &data)
{
    if (data.empty() || (data.size() == 1 && data[0] == '-'))
        return false;

    bool hasDigit = false;
    bool hasDecimal = false;

    for (size_t i = 0; i < data.size(); ++i)
    {
        char c = data[i];

        if (i == 0 && c == '-')
        {
            continue;
        }

        if (c == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }

        else if (!std::isdigit(c))
        {
            return false;
        }
        else
        {
            hasDigit = true;
        }
    }

    return hasDigit;
}

std::pair<int, int> DataConverter::GetSingleRowCol(const string& message)
{
    cout << message;
    string input;
    cin >> input;
    if (input.size() != 3)
    {
        throw InputException("Invalid Input: Please input 3 characters EX: (B01)");
    }
    if (!isAlphabet(input[0]) || !isNumber(input[1]) || !isNumber(input[2]))
    {
        throw InputException("Invalid Input: Please input [A-Z][0-9][0-9]");
    }

    return std::make_pair((int)(input[0] - 'A'), stoi(input.substr(1,2)) - 1);
};

vector<std::pair<int, int>> DataConverter::GetMultipleRowCol(int quantity, const string& message)
{
    while (true) {
        try{
            cout << message;
            string input;
            for (int i = 0; i < quantity; i++)
            {
                string temp;
                cin >> temp;
                input += temp;
                if (i != quantity - 1) {
                    input += " ";
                }
            }
            cout << endl;

            if (input.length() < 3)
                throw InputException("Invalid Input: Please input minimum 3 characters.");

            // Regex for input with format A01, A02, A03,..., A0N
            std::regex pattern("([A-Z][0-9]{2},?\\s?)+");
            if (!std::regex_match(input, pattern))
                throw InputException("Invalid Input: Please input A-Z and 0-9 with pattern A09, B01,..., C04");

            vector<std::pair<int, int>> result;
            result.reserve(quantity);

            // Split the input string by comma and space
            std::istringstream ss(input);
            std::string token;
            while(std::getline(ss, token, ','))
            {
                // Remove leading and trailing spaces
                token.erase(0, token.find_first_not_of(' '));
                token.erase(token.find_last_not_of(' ') + 1);

                // Process each pair separately
                result.emplace_back((int)(token[0] - 'A'), std::stoi(token.substr(1)) - 1);
            }

            return result;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }
}

bool DataConverter::isAlphabet(const string &data)
{
    if (data.empty())
        return false;

    for (char i : data)
    {
        if (!isAlphabet(i))
            return false;
    }

    return true;
}

bool DataConverter::isAlphabet(char data)
{
    return data >= 'A' && data <= 'Z';
}

string DataConverter::LowerCase(string data)
{
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

string DataConverter::itos(int j, int i){
    string slot;
    slot += (char)(i + 'A');
    string temp = to_string(j+1);
    if (temp.length() == 1) slot += "0";
    slot += temp;
    return slot;
}