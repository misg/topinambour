#ifndef GUARD_commands
#define GUARD_commands

#include <deque>
#include <iostream>
#include <string>

void execute_cmds(std::deque<std::string>&);

std::istream& read_cmds(std::istream&, bool prompt=true);

#endif
