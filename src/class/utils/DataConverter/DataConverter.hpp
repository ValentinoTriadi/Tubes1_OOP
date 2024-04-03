#ifndef DATA_CONVERTER_HPP
#define DATA_CONVERTER_HPP
#include <string>
#include <vector>
#include "../../exception/InputException/InputException.hpp"

/**
 * @brief Class Used to hanlde all the data converts from one data type to another
 */

using namespace std;

class DataConverter
{
public:
    /**
     * @brief Validate User Input for multiple Row and Column input
     * Input will be taken from the function
     */
    static vector<std::pair<int, int>> GetMultipleRowCol();

    /**
     * @brief Validate User Input for Player Row and Column input
     * Input will be taken from the function
     */
    static std::pair<int, int> GetSingleRowCol();
    /**
     * @brief Check if the character is a number
     * @return true if a number
     */
    static bool isNumber(char);

    /**
     * @brief Check if the character is an alphabet
     * @return true if an alphabet
     */
    static bool isAlphabet(char);

    /**
     * @brief Check if the string is an alphabet
     * @return true if an alphabet
     */
    static bool isAlphabet(const string &data);

    /**
     * @brief Check if the string is a number
     * @return true if a number
     */
    static bool isNumber(const string &data);

    /**
     * Convert data input to int or float
     * Usage:```return T;```
     * Param string : used to convert the string into T either float or integer
     */
    template <typename T>
    static T StringToNumber(const string &);

    /**
     * @brief Change the string to lowercase
     * @return string in lowercase
     */
    static string LowerCase(string data);
};
#endif