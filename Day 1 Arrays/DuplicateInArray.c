#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
int i, n;

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

// Method 1
// Sort and Compare
int findDuplicate1(int a[])
{
  int flag = 0;
  mergeSort(a, n);
  for (i = 0; i < n - 1; i++)
  {
    if (a[i] == a[i + 1])
      return a[i];
  }
  if (flag == 0)
    return -1;
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

// Method 2
// Hashlist
struct dictionary
{
  int key;
  int value;
};
void createHashlist(struct dictionary *hashlist)
{
  for (i = 0; i < n; i++)
  {
    hashlist[i].key = i + 1;
    hashlist[i].value = 0;
  }
}

int updateHashlist(struct dictionary *hashlist, int num)
{
  int j, toFind = -1;
  for (j = 0; j < n; i++)
  {
    if (hashlist[j].key == num)
    {
      if (hashlist[j].value <= 1)
        hashlist[j].value += 1;
      else
      {
        toFind = hashlist[j].value;
        break;
      }
    }
  }
  return toFind;
}

int findDuplicate2(int a[])
{
  struct dictionary *hashlist = (struct dictionary *)malloc(n * sizeof(struct dictionary));
  createHashlist(hashlist);
  int duplicate = -1;
  for (i = 0; i < n; i++)
  {
    if (duplicate != -1)
      break;
    else
      duplicate = updateHashlist(hashlist, a[i]);
  }
  return duplicate;
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

// Method 3
// Floyd's Hare & Tortoise Algorithm
int findDuplicate3(int a[])
{
  int slow = a[0];
  int fast = a[0];

  do
  {
    slow = a[slow];
    fast = a[a[fast]];
  } while (slow != fast);

  fast = a[0];

  while (slow != fast)
  {
    slow = a[slow];
    fast = a[fast];
  }

  return slow;
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

int main()
{
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  //Method 1
  // printf("%d\n", findDuplicate(a));
  //Method 2
  // printf("%d\n", findDuplicate2(a));
  //Method 3
  printf("%d\n", findDuplicate3(a));
  return 0;
}