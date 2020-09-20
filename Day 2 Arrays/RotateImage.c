#include <stdio.h>
#include <stdlib.h>
int i, j, n;

void print(int **arr)
{
  for (i = 0; i < n; i++)
  {
    printf("\n");
    for (j = 0; j < n; j++)
      printf("%d ", *(*(arr + i) + j));
  }
}

void swap(int **arr, int a, int b)
{
  if (a == b)
    return;
  int temp = arr[a][b];
  arr[a][b] = arr[b][a];
  arr[b][a] = temp;
}

void swapInRow(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void reverse(int *arr, int start, int end)
{
  while (start < end)
  {
    swapInRow(arr, start, end);
    start++;
    end--;
  }
}

void rotateMatrix(int **arr)
{
  for (i = 0; i < n; i++)
    for (j = 0; j < i; j++)
      swap(arr, i, j);
  for (i = 0; i < n; i++)
    reverse(arr[i], 0, n - 1);
}

int main()
{
  scanf("%d", &n);
  int **arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(n * sizeof(int));
    for (j = 0; j < n; j++)
    {
      scanf("%d", (*(arr + i) + j));
    }
  }
  rotateMatrix(arr);
  print(arr);
}
