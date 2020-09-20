#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &v, int target)
  {
    vector<int> toReturn;
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
      if (m.find(target - v[i]) == m.end())
        m[v[i]] = i;
      else
      {
        toReturn.push_back(i);
        toReturn.push_back(m.at(target - v[i]));
        return toReturn;
      }
    }
    return toReturn;
  }
};

int main()
{
  int n, number;
  cin >> n; //Length of array
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> number;
    v.push_back(number);
  }
  int target;
  cin >> target;
  Solution s;
  for (auto &it : s.twoSum(v, target))
    cout << it << ' ';
  return 0;
}