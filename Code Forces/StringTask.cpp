#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string s;
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] >= 65 && s[i] <= 92)
      s[i] += 32;
    if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
      continue;
    cout << "." << s[i];
  }
  return 0;
}