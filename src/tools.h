/* Some useful tools
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaïer@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#ifndef __src__tools_h__
#define __src__tools_h__

#include <deque>
#include <string>
#include <vector>

std::deque<std::string> split(const std::string, char);
std::vector<std::string> split(const std::string, char);
char **vector_to_array(std::vector<std::string>&);

#endif
