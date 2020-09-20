#include <stdio.h>
#include <stdlib.h>

void mergeCombineSort(int arr[], int b, int m, int e)
{
  int *temp = (int *)malloc((e + 1) * sizeof(int));
  int i = b, j = m + 1, index = b, k;

  while (i <= m && j <= e)
  {
    if (arr[i] < arr[j])
    {
      temp[index] = arr[i++];
    }
    else
    {
      temp[index] = arr[j++];
    }
    index++;
  }
  if (i > m)
  {
    while (j <= e)
    {
      temp[index] = arr[j++];
      index++;
    }
  }
  else
  {
    while (i <= m)
    {
      temp[index] = arr[i++];
      index++;
    }
  }

  for (k = b; k < index; k++)
  {
    arr[k] = temp[k];
  }
}

void mergeDivide(int arr[], int b, int e)
{
  if (b < e)
  {
    // Same as (b + e) / 2, but avoids overflow for large b and e
    int m = b + (e - b) / 2;
    mergeDivide(arr, b, m);
    mergeDivide(arr, m + 1, e);
    mergeCombineSort(arr, b, m, e);
  }
  else
    return;
}

int *mergeSort(int arr[], int n)
{
  mergeDivide(arr, 0, n - 1);
}