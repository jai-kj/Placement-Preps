#include <stdio.h>
#include <stdlib.h>
int i, n;

int main()
{
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  int *temp = (int *)malloc(n + 1 * sizeof(int));
  for (i = 0; i < n + 1; i++)
  {
    if (i != n)
      scanf("%d", &a[i]);
    temp[i] = 0;
  }

  for (i = 0; i < n; i++)
  {
    temp[a[i]] += 1;
  }

  for (i = 1; i < n + 1; i++)
  {
    if (temp[i] > 1)
      printf("Repeating: %d", temp[i]);
    if (temp[i] == 0)
      printf("\nMissing: %d", i);
  }
}
