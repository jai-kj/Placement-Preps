#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> majority(vector<int> &v)
  {
    int count1 = 0, count2 = 0, ele1 = -1, ele2 = -1;
    vector<int> toReturn;
    //Moore's Vooting Algorithm
    for (auto &it : v)
    {
      if (ele1 == it)
        count1++;
      else if (ele2 == it)
        count2++;
      else if (count1 == 0)
      {
        ele1 = it;
        count1 = 1;
      }
      else if (count2 == 0)
      {
        ele2 = it;
        count2 = 1;
      }
      else
      {
        count1--;
        count2--;
      }
    }
    count1 = 0;
    count2 = 0;
    for (auto &it : v)
    {
      if (it == ele1)
        count1++;
      else if (it == ele2)
        count2++;
    }
    if (count1 > v.size() / 3)
      toReturn.push_back(ele1);
    if (count2 > v.size() / 3)
      toReturn.push_back(ele2);
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
  for (auto &it : s.majority(v))
    cout << it << ' ';
  return 0;
}