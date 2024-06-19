#include <stdio.h>
#define n 8

void initialize(int arr[n][n])
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr[i][j] = 0;
}

void add(int arr[n][n], int i, int j)
{
  arr[i][j] = 1;
  arr[j][i] = 1;
}

void display(int arr[n][n])
{
  int i, j;

  for (i = 1; i < n; i++)
    {
        int count =0;
    for (j = 1; j < n; j++)
    {
      if(arr[i][j]==1)
      {
          count++;
      }
    }
    printf("%d \n",count);
  }
}

int main()
{
  int ar[n][n];
  initialize(ar);
  add(ar, 1, 4);
  add(ar, 1, 2);
  add(ar, 1, 3);
  add(ar, 2, 3);
  add(ar, 2, 5);
  add(ar, 2, 7);
  add(ar, 3, 6);
  add(ar, 3, 7);
  display(ar);

  return 0;
}
