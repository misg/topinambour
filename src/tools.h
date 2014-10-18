#ifndef GUARD_split
#define GUARD_split

#include <deque>
#include <string>
#include <vector>

std::deque<std::string> split(const std::string, char);
std::vector<std::string> split(const std::string, char);
char **vector_to_array(std::vector<std::string>&);

#endif
