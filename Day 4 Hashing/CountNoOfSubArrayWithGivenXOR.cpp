#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int count(vector<int> &v, int targetXOR)
  {
    int n = v.size(), count = 0;
    vector<int> prefix(n, 0);
    // computing prefix array
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
      prefix[i] = prefix[i - 1] ^ v[i];

    // calculating count
    int temp = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      // we do target xor prefix[i] as
      // prefix[i] = v[0] + ... + v[i] which is basically
      temp = targetXOR ^ prefix[i];

      // If temp exists in map, then there is another previous prefix with
      // same XOR, i.e., there is a subarray ending at i with XOR equal to targetXOR.
      // We add count of all such subarrays to result = count.
      count += mp[temp];

      if (prefix[i] == targetXOR)
        count++;

      mp[prefix[i]]++;
    }
    return count;
  }
};

int main()
{
  int number, targetXOR;
  vector<int> v;
  while ((cin >> number) && number != -999)
    v.push_back(number);

  cin >> targetXOR;
  Solution s;
  cout << s.count(v, targetXOR) << endl;
  return 0;
}