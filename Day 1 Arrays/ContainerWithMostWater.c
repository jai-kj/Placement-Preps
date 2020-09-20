#include <stdio.h>
#include <stdlib.h>
int i, n;

int findMaxWater(int a[])
{
  int width = n - 1, height, maxarea = 0, area, p1 = 0, p2 = n - 1;
  while (p1 < p2)
  {
    height = a[p1] > a[p2] ? a[p2] : a[p1];
    area = (p2 - p1) * height;
    if (area > maxarea)
      maxarea = area;
    if (a[p1] > a[p2])
      p2--;
    else
      p1++;
  }
  return maxarea;
}

int main()
{
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("%d", findMaxWater(a));
}