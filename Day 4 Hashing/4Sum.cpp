#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &v, int target)
  {
    int n = v.size();
    vector<vector<int>> toReturn;
    if (n >= 4)
    {
      sort(v.begin(), v.end());
      for (int i = 0; i < n; i++)
      {
        for (int j = i + 1; j < n; j++)
        {
          int rem = target - v[i] - v[j], left = j + 1, right = n - 1;
          while (left < right)
          {
            if (v[left] + v[right] < rem)
              left++;
            else if (v[left] + v[right] > rem)
              right--;
            else
            {
              vector<int> res(4, 0);
              res[0] = v[i];
              res[1] = v[j];
              res[2] = v[left];
              res[3] = v[right];
              toReturn.push_back(res);

              while (left < right && v[left] == res[2])
                ++left;
              while (left < right && v[right] == res[3])
                --right;
            }
          }

          while (j + 1 < n && v[j + 1] == v[j])
            ++j;
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
  int target;
  cin >> target;
  Solution s;
  for (auto &row : s.fourSum(v, target))
  {
    cout << endl;
    for (auto &it : row)
      cout << it << ' ';
  }
  return 0;
}