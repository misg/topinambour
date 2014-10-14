#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string>& split(const string s, queue<string>& cmds, char delimiter=';')
{
  string::size_type i = 0, size = s.size();

  while (i != size) {
  
    while (i!= size && (isspace(s[i]) || s[i] == delimiter))
      ++i;
  
    string::size_type j = i;

    while (j != size && s[j] != delimiter)
      ++j;

    if (i != j) {
      cmds.push(s.substr(i, j-i));
      i = j;
    }
  }

  return cmds;
}

void execute_cmds(queue<string>& cmds)
{

}

istream& read_cmds(istream& in)
{
  string line;

  while (getline(in, line))
  {
    queue<string> cmds;
    
    split(line, cmds);
    execute_cmds(cmds);
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
    read_cmds(batchFile);
    batchFile.close();
  }
  else
  {
    cerr << "Too much arguments." << endl;
    return 1;
  }
}
