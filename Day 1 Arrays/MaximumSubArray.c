#include <stdio.h>
#include <stdlib.h>
int i, n;

int main()
{
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // Kadane's Algorithm
  int sum = 0, maximum = a[0];
  for (i = 0; i < n; i++)
  {
    sum += a[i];
    if (sum > maximum)
      maximum = sum;
    if (sum < 0)
      sum = 0;
  }
  printf("%d", maximum);
  return 0;
}