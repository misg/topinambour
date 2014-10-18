#include "commands.h"
#include <fstream>
#include "utils.h"

using namespace std;

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
