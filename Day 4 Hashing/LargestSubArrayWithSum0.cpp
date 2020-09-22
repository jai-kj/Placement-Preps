#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int largestSubArrayZero(vector<int> &v)
  {
    int maxLen = 0, sum = 0;
    if (v.size() > 0)
    {
      unordered_map<int, int> unMap;
      for (int i = 0; i < v.size(); i++)
      {
        sum += v[i];
        if (v[i] == 0 && maxLen == 0)
          maxLen = 1;
        if (sum == 0)
          maxLen = i + 1;
        if (unMap.find(sum) == unMap.end())
          unMap[sum] = i;
        else
          maxLen = max(maxLen, i - unMap[sum]);
      }
    }
    return maxLen;
  }
};

int main()
{
  int number;
  vector<int> v;
  while ((cin >> number) && number != -999)
    v.push_back(number);
  Solution s;
  cout << s.largestSubArrayZero(v) << endl;
}