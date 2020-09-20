#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, n, j;
  scanf("%d", &n);
  int **arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(2 * sizeof(int));
    scanf("%d %d", (*(arr + i) + 0), (*(arr + i) + 1));
  }

  int fuel, count;
  for (i = 0; i < n; i++)
  {
    j = i;
    count = n;
    fuel = 0;
    while (count-- > 0)
    {
      fuel += arr[j][0];
      if (fuel < arr[j][1])
        break;
      fuel -= arr[j][1];
      if (++j == n)
        j = 0;
    }
    if (count == -1)
    {
      printf("%d", j);
      break;
    }
  }
  return 0;
}