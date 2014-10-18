/* Main commands of the shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaïer@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#ifndef __src__commands_h__
#define __src__commands_h__

#include <deque>
#include <iostream>
#include <string>

void execute_cmds(std::deque<std::string>&);

std::istream& read_cmds(std::istream&, bool prompt=true);

#endif
