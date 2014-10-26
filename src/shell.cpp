/* Programming Assignment 1: The Unix Shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaïer@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 18/10/2014
 */

#include "commands.h"
#include <fstream>
#include "tools.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1) // Prompt mode
    {
        cout << "prompt> ";

        string line;
        while (getline(cin, line))
        {
            vector<string> instructions = parse(line);
            execute(instructions);

            cout << "prompt> ";
        }
    }
    else if (argc == 2) // Batch mode
    {
        ifstream batchFile(argv[1]);
        if (!batchFile)
        {
            cerr << "An error occured during opening file \""
                 << argv[1] << "\"." << endl;
            return 1;
        }
        
        string line;
        while (getline(batchFile, line))
        {
            cout << line << endl;

            vector<string> instructions = parse(line);
            execute(instructions);
        }

        batchFile.close();
    }
    else
    {
        cerr << "Too much arguments." << endl;
        return 1;
    }
}
