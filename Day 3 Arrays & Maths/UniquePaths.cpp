#include <iostream>

using namespace std;

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    double res = 1;
    int N = n + m - 2;
    int r = m - 1;
    for (int i = 1; i <= m - 1; i++)
    {
      res = res * (N - r + i) / i;
      cout << res << ' ';
    }
    return (int)res;
  }
};

int main()
{
  int m, n;
  cin >> m >> n;
  Solution s;
  cout << s.uniquePaths(m, n);
  return 0;
}