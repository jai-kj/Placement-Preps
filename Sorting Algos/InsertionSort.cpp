#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int number;
  vector<int> v;
  while ((cin >> number) && number != -999)
    v.push_back(number);

  for (int i = 1; i < v.size(); i++)
  {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && key < v[j])
    {
      v[j + 1] = v[j];
      j -= 1;
    }
    v[j + 1] = key;
  }

  for (auto &it : v)
    cout << it << ' ';

  return 0;
}