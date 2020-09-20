#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int majority(vector<int> &v)
  {
    int element, count = 0;
    for (auto &it : v)
    {
      //Moore's Vooting Algorithm
      if (count == 0)
        element = it;
      if (element == it)
        count++;
      else
        count--;
    }
    return element;
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
  cout << s.majority(v);
  return 0;
}
