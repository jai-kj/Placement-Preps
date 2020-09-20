#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mergeSort.h"

void print(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

int threeSumClosest(int *arr, int n, int target)
{
  int diff = 999999, i, low, high;
  for (i = 0; i < n; i++)
  {
    if (diff == 0)
      break;
    low = i + 1;
    high = n - 1;
    while (low < high)
    {
      int sum = arr[i] + arr[low] + arr[high];
      if (abs(target - sum) < abs(diff))
        diff = target - sum;
      if (sum < target)
        low++;
      else
        high--;
    }
  }
  return target - diff;
}

int main()
{
  int i, n;
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int target;
  scanf("%d", &target);
  mergeSort(arr, n);
  printf("%d\n", threeSumClosest(arr, n, target));
  return 0;
}