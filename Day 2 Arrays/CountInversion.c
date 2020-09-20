#include <stdio.h>
#include <stdlib.h>

int mergeCombineSort(int arr[], int b, int m, int e)
{
  int *temp = (int *)malloc((e + 1) * sizeof(int));
  int i = b, j = m + 1, index = b, k, count = 0;

  while (i <= m && j <= e)
  {
    if (arr[i] <= arr[j])
      temp[index++] = arr[i++];
    else
    {
      temp[index++] = arr[j++];
      count += (m + 1 - i);
    }
  }
  if (i > m)
    while (j <= e)
      temp[index++] = arr[j++];
  else
    while (i <= m)
      temp[index++] = arr[i++];

  for (k = b; k < index; k++)
    arr[k] = temp[k];

  return count;
}

int mergeDivide(int arr[], int b, int e)
{
  int inversion_count = 0;
  if (b < e)
  {
    // Same as (b + e) / 2, but avoids overflow for large b and e
    int m = b + (e - b) / 2;
    inversion_count += mergeDivide(arr, b, m);
    inversion_count += mergeDivide(arr, m + 1, e);
    inversion_count += mergeCombineSort(arr, b, m, e);
  }
  return inversion_count;
}

int main()
{
  int i, n;
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printf("%d\n", mergeDivide(arr, 0, n - 1));
  return 0;
}