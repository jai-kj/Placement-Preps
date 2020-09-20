#include <stdio.h>
#include <stdlib.h>
int n1, n2, i;

void print(int a[], int start, int end)
{
  printf("\n");
  for (i = start; i < end; i++)
    printf("%d ", a[i]);
}

int gap(int a, int b)
{
  return (a + b) % 2 == 0 ? (a + b) / 2 : ((a + b) / 2) + 1;
}

void mergeTwoArray(int a[], int gap)
{
  int temp, p1 = 0, p2 = gap;
  while (gap > 0)
  {
    if (a[p1] > a[p2])
    {
      temp = a[p1];
      a[p1] = a[p2];
      a[p2] = temp;
    }
    p1++;
    p2++;
    if (p2 >= n1 + n2)
    {
      gap /= 2;
      p1 = 0;
      p2 = gap;
    }
  }
}

int main()
{
  scanf("%d", &n1);
  scanf("%d", &n2);
  int *a = (int *)malloc((n1 + n2) * sizeof(int));
  for (i = 0; i < n1; i++)
    scanf("%d", &a[i]);
  for (i = n1; i < n2 + n1; i++)
    scanf("%d", &a[i]);
  mergeTwoArray(a, gap(n1, n2));
  print(a, 0, n1);
  print(a, n1, n1 + n2);
  return 0;
}