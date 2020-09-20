#include <iostream>

using namespace std;

class Solution
{
public:
  double myPow(double x, int n)
  {
    double ans = 1.0;
    long newN = n;
    if (newN < 0)
      newN = -1 * newN;
    while (newN > 0)
    {
      if (newN % 2 == 1)
      {
        ans *= x;
        newN -= 1;
      }
      else
      {
        x *= x;
        newN /= 2;
      }
    }
    if (n < 0)
      ans = double(1.0) / double(ans);
    return ans;
  }
};

int main()
{
  double x;
  int n;
  cin >> x >> n;
  Solution s;
  cout << s.myPow(x, n);
  return 0;
}