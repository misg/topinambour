#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

#include "split.h"

using namespace std;

char **convert(vector<string>& v)
{
    vector<string>::size_type size = v.size();
    
    char **argv = static_cast<char**>(calloc(size + 1, sizeof(char*)));

    for (vector<string>::size_type i = 0; i != size; ++i)
    {
       argv[i] = const_cast<char*>((*(v.data() + i)).data());
    }

    argv[size] = NULL;

    return argv;
}

void execute_cmds(deque<string>& cmds)
{
    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        vector<string> args;
        split(cmds.front(), args, ' ');
        char **argv = convert(args);
        execvp(argv[0], argv);
        free(argv);
    }
}

istream& read_cmds(istream& in, bool prompt=true)
{
    string line;

    if (prompt)
        cout << "<prompt> ";

    while (getline(in, line))
    {
        deque<string> cmds;
    
        split(line, cmds, ';');
        execute_cmds(cmds);

        cout << "<prompt> ";
    }

    return cin;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        read_cmds(cin);
    }
    else if (argc == 2)
    {
        ifstream batchFile(argv[1]);
        if (!batchFile)
        {
            cerr << "An error occured during opening file \""
                 << argv[1] << "\"." << endl;
            return 1;
        }
        read_cmds(batchFile, false);
        batchFile.close();
    }
    else
    {
        cerr << "Too much arguments." << endl;
        return 1;
    }
}
