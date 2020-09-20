#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void display(vector<vector<int>> &matrix)
  {
    for (auto &row : matrix)
    {
      cout << endl;
      for (auto &col : row)
        cout << col << ' ';
    }
  }

  void searchInMatrix1(vector<vector<int>> &matrix, int target)
  {
    int n = matrix.size();
    if (n > 0)
    {
      int m = matrix[0].size();
      int i = 0, j = m - 1;
      while (i < n && j >= 0)
      {
        if (matrix[i][j] == target)
        {
          cout << "Element at (" << i << ", " << j << ") is " << target << endl;
          return;
        }
        if (matrix[i][j] > target)
          j--;
        else
          i++;
      }
    }
    cout << "Element not found";
    return;
  }

  bool searchInMatrix2(vector<vector<int>> &matrix, int target)
  {
    int n = matrix.size();
    if (n == 0)
      return false;
    int m = matrix[0].size();

    int low = 0, high = ((n * m) - 1);

    while (low <= high)
    {
      int mid = (low + (high - low) / 2);
      if (matrix[mid / m][mid % m] == target)
        return true;
      if (matrix[mid / m][mid % m] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return false;
  }
};

int main()
{
  int n, m, number;
  cin >> n >> m;
  vector<vector<int>> matrix;
  for (int i = 0; i < n; i++)
  {
    vector<int> row;
    for (int j = 0; j < m; j++)
    {
      cin >> number;
      row.push_back(number);
    }
    matrix.push_back(row);
  }
  int target;
  cin >> target;
  Solution s;
  // cout << s.searchInMatrix2(matrix, target);
  // s.searchInMatrix1(matrix, target);
  return 0;
}