/* Main commands of the shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaïer@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#include "commands.h"
#include <cstdlib>
#include <sys/wait.h>
#include <unistd.h>
#include "tools.h"

using namespace std;

vector<string> parse(const string input)
{
    return split(input, ';');
}

void execute(vector<string>& instructions)
{
    vector<pid_t> pids;
    string quit_command = "quit";
    bool quit = false;

    for (string instr : instructions)
    {
        if (split(instr, ' ')[0] == quit_command)
            quit = true;
        else
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
    }

    for (pid_t pid : pids)
        waitpid(pid, NULL, 0);

    if (quit)
        exit(EXIT_SUCCESS);
}
