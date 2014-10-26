/* Some useful tools
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaïer@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#ifndef __src__tools_h__
#define __src__tools_h__

#include <string>
#include <vector>

std::vector<std::string> split(const std::string, char);
char **vector_of_string_to_array_of_char(std::vector<std::string>&);

#endif
