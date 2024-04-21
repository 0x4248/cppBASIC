/* cppBASIC
 * A simple BASIC like interpreter in C++
 * Github: https://www.github.com/0x4248/cppBASIC
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string& str);
int find_variable(std::string variable, std::vector<std::string> variables);