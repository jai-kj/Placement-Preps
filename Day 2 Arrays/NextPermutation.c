#include <stdio.h>
#include <stdlib.h>
int i, n;

void print(int *arr)
{
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

void swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void reverse(int *arr, int start, int end)
{
  while (start < end)
  {
    swap(arr, start, end);
    start++;
    end--;
  }
}

void nextPermutation(int *arr)
{
  int j;
  i = n - 2;
  while (i >= 0 && arr[i] >= arr[i + 1])
    i--;
  if (i >= 0)
  {
    j = n - 1;
    while (j >= 0 && arr[j] <= arr[i])
      j--;
    swap(arr, i, j);
  }
  reverse(arr, i + 1, n - 1);
}

int main()
{
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  nextPermutation(arr);
  print(arr);
  return 0;
}