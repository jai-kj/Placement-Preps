#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int number;
  vector<int> v;
  while ((cin >> number) && number != -999)
    v.push_back(number);

  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < v.size() - 1; j++)
      if (v[j] > v[j + 1])
      {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }

  for (auto &it : v)
    cout << it << ' ';

  return 0;
}