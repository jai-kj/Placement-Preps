#include <iostream>

using namespace std;

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  int toShow = 0;
  for (int i = 0; i < s1.length(); i++)
  {
    if (s1[i] >= 65 && s1[i] <= 92)
      s1[i] += 32;
    if (s2[i] >= 65 && s2[i] <= 92)
      s2[i] += 32;
    if (s1[i] == s2[i])
      continue;
    else if (s1[i] > s2[i])
    {
      toShow = 1;
      break;
    }
    else
    {
      toShow = -1;
      break;
    }
  }
  cout << toShow << endl;
}