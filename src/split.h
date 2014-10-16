#ifndef GUARD_split
#define GUARD_split

#include <deque>
#include <string>
#include <vector>

std::deque<std::string>& split(const std::string,
    std::deque<std::string>&, char);
std::vector<std::string>& split(const std::string,
    std::vector<std::string>&, char);

#endif
