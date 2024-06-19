#include <stdio.h>
#define n 100

void dfs(int ar[n][n],int visited[n],int v, int s)
{
    int stack[n];
    int top=-1;
    stack[++top]=s;
    while(top!=-1)
    {
        int vertex=stack[top--];
        if(!visited[vertex])
        {
            printf("%d",vertex);
            visited[vertex]=1;
            for(int i=v-1;i>=0;i--)
            {
                if(ar[vertex][i] && !visited[i])
                {
                    stack[++top]=i;
                }
            }
        }
    }
}
int main()
{
    int ar[n][n];
    int visited[n];
    int v,s;
    scanf("%d",&v);
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        for(int j=0;j<v;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    scanf("%d",&s);
    dfs(ar,visited,v,s);
}
/*

int main()
{
    int ar[n][n];
    int visited[n];
    int v, s;
    scanf("%d", &v);
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    scanf("%d", &s);

    dfs(ar, visited, v, s);

    return 0;
}
#include <stdio.h>
#define n 100

void dfs(int ar[n][n], int visited[n], int v, int s)
{
    int stack[n];
    int top = -1;
    stack[++top] = s;

    while (top != -1)
    {
        int vertex = stack[top--];
        if (!visited[vertex])
        {
            printf("%d ", vertex);
            visited[vertex] = 1;
            for (int i = v - 1; i >= 0; i--)
            {
                if (ar[vertex][i] && !visited[i])
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

*/
