#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxLength(string s)
  {
    int l = 0, r = 0, len = 0, n = s.size();
    unordered_map<char, int> m;
    if (n <= 1)
      return n;
    while (r < n)
    {
      if (m.find(s[r]) != m.end())
        l = max(l, m[s[r]] + 1);
      m[s[r]] = r;
      len = max(r - l + 1, len);
      r++;
    }
    return len;
  }
};

int main()
{
  string s;
  cin >> s;
  Solution sl;
  cout << sl.maxLength(s) << endl;
  return 0;
}