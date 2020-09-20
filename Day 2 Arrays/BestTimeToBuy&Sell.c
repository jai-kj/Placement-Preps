#include <stdio.h>
#include <stdlib.h>
int i, n;

int maxProfitOnBuySell(int *arr)
{
  int minBuy = 99999, maxProfit = 0;
  for (i = 0; i < n; i++)
  {
    if (minBuy > arr[i])
      minBuy = arr[i];
    else if (arr[i] - minBuy > maxProfit)
      maxProfit = arr[i] - minBuy;
  }
  return maxProfit;
}

int main()
{
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printf("%d\n", maxProfitOnBuySell(arr));
  return 0;
}