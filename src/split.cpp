#include "split.h"

using namespace std;

deque<string>& split(const string s, deque<string>& res, char delimiter)
{
    string::size_type i = 0, size = s.size();

    while (i != size)
    {
        while (i != size && (isspace(s[i]) || s[i] == delimiter))
            ++i;

        string::size_type j = i;

        while (j != size && s[j] != delimiter)
            ++j;

        if (i != j)
        {
            res.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return res;
}

vector<string>& split(const string s, vector<string>& res, char delimiter)
{
    string::size_type i = 0, size = s.size();

    while (i != size)
    {
        while (i != size && (isspace(s[i]) || s[i] == delimiter))
            ++i;

        string::size_type j = i;

        while (j != size && s[j] != delimiter)
            ++j;

        if (i != j)
        {
            res.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return res;
}
