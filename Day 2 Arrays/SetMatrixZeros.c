#include <stdio.h>
#include <stdlib.h>
int i, j, n, m;

void print(int **arr)
{
  for (i = 0; i < n; i++)
  {
    printf("\n");
    for (j = 0; j < m; j++)
      printf("%d ", *(*(arr + i) + j));
  }
}

void setZeros(int **arr)
{
  int colFlag = 1;
  for (i = 0; i < n; i++)
  {
    if (arr[i][0] == 0)
      colFlag = 0;
    for (j = 1; j < m; j++)
      if (arr[i][j] == 0)
        arr[i][0] = arr[0][j] = 0;
  }

  for (i = n - 1; i >= 0; i--)
  {
    for (j = m - 1; j >= 1; j--)
      if (arr[i][0] == 0 || arr[0][j] == 0)
        arr[i][j] = 0;
    if (colFlag == 0)
      arr[i][0] = 0;
  }
  print(arr);
}

int main()
{
  scanf("%d %d", &n, &m);
  int **arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(m * sizeof(int));
    for (j = 0; j < m; j++)
    {
      scanf("%d", (*(arr + i) + j));
    }
  }
  setZeros(arr);
  return 0;
}