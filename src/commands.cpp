/* Main commands of the shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaier@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 05/11/2014
 */

#include "commands.h"
#include <cstdlib>
#include "errno.h"
#include <sys/wait.h>
#include "string.h"
#include <unistd.h>
#include "tools.h"

using namespace std;

string QUIT = "quit";

vector<string> parse(const string input)
{
    return split(input, ';');
}

int execute(vector<string>& instructions)
{
    vector<pid_t> pids;
    bool quit = false;

    for (string instr : instructions)
    {
        if (split(instr, ' ')[0] == QUIT)
            quit = true;
        else
        {
            pid_t child_pid = fork();

            if (child_pid == 0)
            {
                vector<string> args = split(instr, ' ');

                char **argv = vector_of_string_to_array_of_char(args);
                int res = execvp(argv[0], argv);
                
                free(argv);

                if (res == -1)
                {
                    cerr << strerror(errno) << endl;
                    exit(EXIT_FAILURE);
                }
            }
            else
                pids.push_back(child_pid);
        }
    }

    for (pid_t pid : pids)
        waitpid(pid, NULL, 0);

    if (quit) return 1;
    else      return 0;
}
