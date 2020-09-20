#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &v)
  {
    int n = v.size();
    vector<vector<int>> toReturn;
    if (n >= 3)
    {
      sort(v.begin(), v.end());
      for (int i = 0; i < n; i++)
      {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
          if (v[i] + v[left] + v[right] < 0)
            left++;
          else if (v[i] + v[left] + v[right] > 0)
            right--;
          else
          {
            vector<int> res(3, 0);
            res[0] = v[i];
            res[1] = v[left];
            res[2] = v[right];
            toReturn.push_back(res);

            while (left < right && v[left] == res[1])
              ++left;
            while (left < right && v[right] == res[2])
              --right;
          }
        }
        while (i + 1 < n && v[i + 1] == v[i])
          ++i;
      }
    }
    return toReturn;
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
  for (auto &row : s.threeSum(v))
  {
    cout << endl;
    for (auto &it : row)
      cout << it << ' ';
  }
  return 0;
}