//Adjacency Matrix: Undirected graph

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define n 10

int arr[n][n];

void add(int arr[n][n],int a,int b)
{
    arr[a][b]=arr[b][a]=1;
}

int main()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    int size;
    scanf("%d ",&size);
    int a,b;
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        add(arr,a,b);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d:",i+1);
      for(int j=0;j<n;j++)
      {
        printf("%d ",arr[i][j]);
      }
      printf("\n");
    }
}
