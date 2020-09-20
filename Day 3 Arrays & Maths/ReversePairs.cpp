#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int mergeSort(vector<int> &v, int beg, int mid, int end)
  {
    int count = 0, j = mid + 1;
    for (int i = beg; i <= mid; i++)
    {
      while (j <= end && v[i] > 2LL * v[j])
        j++;
      count += (j - (mid + 1));
    }

    vector<int> temp;
    int left = beg, right = mid + 1, k, index = beg;
    while (left <= mid && right <= end)
    {
      if (v[left] < v[right])
        temp.push_back(v[left++]);
      else
        temp.push_back(v[right++]);
    }
    while (left <= mid)
      temp.push_back(v[left++]);
    while (right <= end)
      temp.push_back(v[right++]);

    for (k = beg; k <= end; k++)
      v[k] = temp[k - beg];

    return count;
  }

  int mergeDivide(vector<int> &v, int beg, int end)
  {
    if (beg >= end)
      return 0;
    int mid = beg + (end - beg) / 2;
    int count = mergeDivide(v, beg, mid);
    count += mergeDivide(v, mid + 1, end);
    count += mergeSort(v, beg, mid, end);
    return count;
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
  cout << s.mergeDivide(v, 0, n - 1);
  return 0;
}
