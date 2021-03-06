/* Some useful tools
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaier@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#include "tools.h"

using namespace std;

vector<string> split(const string& s, char delimiter)
{
    vector<string> result;

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
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return result;
}

char **vector_of_string_to_array_of_char(vector<string>& v)
{
    vector<string>::size_type size = v.size();

    // Tip : calloc initializes array with null pointers.   
 
    char **a = static_cast<char**>(calloc(size + 1, sizeof(char*)));

    for (vector<string>::size_type i = 0; i != size; ++i)
    {
       a[i] = const_cast<char*>((*(v.data() + i)).data());
    }

    return a;
}
