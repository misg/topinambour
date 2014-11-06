/* Main commands of the shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaier@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#ifndef __src__commands_h__
#define __src__commands_h__

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse(const std::string);

int execute(std::vector<std::string>&);

#endif
