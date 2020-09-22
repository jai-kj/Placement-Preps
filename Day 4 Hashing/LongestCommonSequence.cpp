#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int lcs(vector<int> &v)
  {
    int longestStreak = 0;
    unordered_set<int> unique;
    if (v.size() > 0)
    {
      int currentNum, currentStreak = 0;
      for (auto &it : v)
        unique.insert(it);

      for (auto &it : v)
      {
        if (unique.find(it - 1) == unique.end())
        {
          currentNum = it;
          currentStreak = 1;

          while (unique.find(currentNum + 1) != unique.end())
          {
            currentNum += 1;
            currentStreak += 1;
          }

          longestStreak = max(longestStreak, currentStreak);
        }
      }
    }
    return longestStreak;
  }
};

int main()
{
  int n, number;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> number;
    v.push_back(number);
  }
  Solution s;
  cout << s.lcs(v);
  return 0;
}