#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{

  unordered_map<string, int> ages;

  ages["Alice"] = 20;
  ages["Bob"] = 13;

  cout << " Bob's age" << ages["Bob"] << endl;

  if (ages.find("Charlie") == ages.end())
  {
    cout << "Charlie is not found" << endl;
  }

  for (auto &pair : ages)
  {
    cout << pair.first <<" ->" << pair.second << " ";
  }

  return 0;
}