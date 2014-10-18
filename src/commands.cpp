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

void execute_cmds(deque<string>& cmds)
{
    vector<pid_t> pids;

    while (!cmds.empty())
    {
        pid_t child_pid = fork();

        if (child_pid == 0)
        {
            vector<string> args = split(cmds.front(), ' ');

            char **argv = convert(args);

            execvp(argv[0], argv);

            free(argv);
        }
        else
            pids.push_back(child_pid);

        cmds.pop_front();
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
        deque<string> cmds = split(line, ';');

        execute_cmds(cmds);

        cout << "prompt> ";
    }

    return cin;
}
