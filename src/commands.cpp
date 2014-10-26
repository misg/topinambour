/* Main commands of the shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaïer@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#include "commands.h"
#include <sys/wait.h>
#include <unistd.h>
#include "tools.h"

using namespace std;

void execute_cmds(vector<string>& instructions)
{
    vector<pid_t> pids;

    for (string instr : instructions)
    {
        pid_t child_pid = fork();

        if (child_pid == 0)
        {
            vector<string> args = split(instr, ' ');

            char **argv = vector_of_string_to_array_of_char(args);

            execvp(argv[0], argv);

            free(argv);
        }
        else
            pids.push_back(child_pid);
    }

    for (pid_t pid : pids)
        waitpid(pid, NULL, 0);
}

istream& read_cmds(istream& in, bool prompt)
{
    string line;

    if (prompt)
        cout << "prompt> ";

    while (getline(in, line))
    {
        vector<string> instructions = split(line, ';');

        execute_cmds(instructions);

        cout << "prompt> ";
    }

    return cin;
}
