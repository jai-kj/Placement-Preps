#include <stdio.h>
#include <stdlib.h>
int i, j, n;
int main()
{
  scanf("%d", &n);
  int **arr = (int **)malloc(n * sizeof(int *)), **toReturn = (int **)malloc(n * sizeof(int *)), *temp = (int *)malloc(2 * sizeof(int));
  for (i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(2 * sizeof(int));
    toReturn[i] = (int *)malloc(2 * sizeof(int));
    scanf("%d %d", (*(arr + i) + 0), (*(arr + i) + 1));
  }
  int count = 0;
  temp = arr[0];
  for (i = 0; i < n; i++)
  {
    if (arr[i][0] <= temp[1])
      temp[1] = temp[1] > arr[i][1] ? temp[1] : arr[i][1];
    else
    {
      toReturn[count][0] = temp[0];
      toReturn[count][1] = temp[1];
      count++;
      temp = arr[i];
    }
  }
  toReturn[count][0] = temp[0];
  toReturn[count][1] = temp[1];
  for (i = 0; i < n; i++)
    if (toReturn[i][0] != 0 && toReturn[i][1] != 0)
      printf("\n%d %d", *(*(toReturn + i) + 0), *(*(toReturn + i) + 1));
  return 0;
}
