#include <stdio.h>
#include <stdlib.h>
int i, j, n;
void print(int **arr)
{
  for (i = 0; i < n; i++)
  {
    printf("\n");
    for (j = 0; j <= i; j++)
      printf("%d ", arr[i][j]);
  }
}

void pascalTriangle()
{
  int **arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc((i + 1) * (sizeof(int)));
    arr[i][0] = arr[i][i] = 1;
    for (j = 1; j < i; j++)
      arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
  }
  print(arr);
}

int main()
{
  scanf("%d", &n);
  pascalTriangle();
  return 0;
}