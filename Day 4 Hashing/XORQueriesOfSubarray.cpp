#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> xorQueries(vector<int> &v, vector<vector<int>> &queries)
  {
    int n = v.size();
    vector<int> toReturn;
    vector<int> prefix(n, 0);
    prefix[0] = v[0];
    for (int i = 0; i < v.size(); i++)
      prefix[i] = prefix[i - 1] ^ v[i];

    int l, r;
    for (auto &row : queries)
    {
      int exor = 0;
      l = row[0];
      r = row[1];
      if (l > 0)
        exor = prefix[r] ^ prefix[l - 1];
      else if (l == 0)
        exor = prefix[r];
      toReturn.push_back(exor);
    }

    return toReturn;
  }
};

int main()
{
  int number, rowCount;
  vector<int> v;
  while ((cin >> number) && number != -1)
    v.push_back(number);

  cin >> rowCount;
  vector<vector<int>> queries;
  for (int i = 0; i < rowCount; i++)
  {
    vector<int> rowInput;
    while ((cin >> number) && number != -1)
      rowInput.push_back(number);
    queries.push_back(rowInput);
  }

  Solution s;
  for (auto &it : s.xorQueries(v, queries))
    cout << it << ' ';
  return 0;
}