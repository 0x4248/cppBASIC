/* cppBASIC
 * A simple BASIC like interpreter in C++
 * Github: https://www.github.com/0x4248/cppBASIC
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "util.h"

std::vector<std::string> tokenize(const std::string &str)
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (iss >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}

int find_variable(std::string variable, std::vector<std::string> variables)
{
    for (int i = 0; i < variables.size(); i++)
    {
        if (variables[i] == variable)
        {
            return i;
        }
    }
    return -1;
}