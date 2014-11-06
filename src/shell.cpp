/* Programming Assignment 1: The Unix Shell
 * @Author: Michaël Sghaïer
 * @Email: michael.sghaier@polymtl.ca
 * @Date: 18/10/2014
 * @LastUpdate: 05/11/2014
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
            int res = execute(instructions);
            if (res == 1) return EXIT_SUCCESS;

            cout << "prompt> ";
        }

        if (cin.eof())
        {
            cout << endl;
            return EXIT_SUCCESS;
        }
    }
    else if (argc == 2) // Batch mode
    {
        ifstream batchFile(argv[1]);
        if (!batchFile)
        {
            cerr << "An error occured during opening file \""
                 << argv[1] << "\"." << endl;
            return EXIT_FAILURE;
        }
        
        string line;
        while (getline(batchFile, line))
        {
            cout << line << endl;

            vector<string> instructions = parse(line);
            int res = execute(instructions);
            if (res == 1) return EXIT_SUCCESS;
        }
        
        batchFile.close();

        if (batchFile.eof())
            return EXIT_SUCCESS;
    }
    else
    {
        cerr << "Too much arguments." << endl;
        return EXIT_FAILURE;
    }
}
