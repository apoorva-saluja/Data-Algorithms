#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define n 50

struct Queue
{
    int queue[n];
    int f,r;
};

struct Queue *createqueue()
{
    struct Queue *newnode=(struct Queue*)malloc(sizeof(struct Queue));
    newnode->f=-1;
    newnode->r=-1;
    return newnode;
}

int isempty(struct Queue *queue)
{
    return queue->f==-1;
}

void enqueue(struct Queue *queue,int vertex)
{
    if(queue->r==n-1)
    {
        printf("queue is full \n");
        return;
    }
    if(queue->f==-1 && queue->r==-1)
        queue->f=queue->r=0;
    queue->r++;
    queue->queue[queue->r]=vertex;
}

int dequeue(struct Queue *queue)
{
    if(isempty(queue))
    {
        printf("queue is empty \n");
        return -1;
    }
    int vertex=queue->queue[queue->f];
    if(queue->f==queue->r)
        queue->f=queue->r=-1;
    else
        queue->f++;
    return vertex;
}

void bfs(int **graph,int numV,int s)
{
    int *visited=(int*)calloc(numV,sizeof(int));
    struct Queue *queue=createqueue();
    visited[s]=1;
    enqueue(queue,s);
    while(!isempty(queue))
    {
        int currV=dequeue(queue);
        printf("%d ",currV);
        for(int i=0;i<numV;i++)
        {
            if(graph[currV][i] && !visited[i])
            {
                visited[i]=1;
                enqueue(queue,i);
            }
        }
    }
    free(visited);
    free(queue);
}

int main()
{
    int numV,s;
    scanf("%d",&numV);
    int ** graph=(int **)malloc(numV*sizeof(int*));
    for(int i=0;i<numV;i++)
    {
        graph[i]=(int *)malloc(numV*sizeof(int));
        for(int j=0;j<numV;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    scanf("%d",&s);
    bfs(graph,numV,s);
    for(int i=0;i<numV;i++)
    {
        free(graph[i]);
    }
    free(graph);
}

/*

#include <stdio.h>
#include <stdlib.h>
#define n 50

struct Queue
{
    int queue[n];
    int f, r;
};

struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->f = -1;
    queue->r = -1;
    return queue;
}

int isEmpty(struct Queue* queue)
{
    return queue->f == -1;
}
void enqueue(struct Queue* queue, int vertex)
{
    if (queue->r == n - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    if (queue->f == -1)
        queue->f = 0;
    queue->r++;
    queue->queue[queue->r] = vertex;
}
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int vertex = queue->queue[queue->f];
    if (queue->f == queue->r)
        queue->f = queue->r = -1;
    else
        queue->f++;
    return vertex;
}

void bfs(int** graph, int numV, int s)
{
    int* visited = (int*)calloc(numV, sizeof(int));
    struct Queue* queue = createQueue();

    visited[s] = 1;
    enqueue(queue, s);
    while (!isEmpty(queue))
    {
        int currV = dequeue(queue);
        printf("%d ", currV);
        for (int i = 0; i < numV; i++)
        {
            if (graph[currV][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    free(visited);
    free(queue);
}
int main()
{
    int numV, s;
    scanf("%d", &numV);
    int** graph = (int**)malloc(numV * sizeof(int*));
    for (int i = 0; i < numV; i++)
    {
        graph[i] = (int*)malloc(numV * sizeof(int));
        for (int j = 0; j < numV; j++)
            scanf("%d", &graph[i][j]);
    }
    scanf("%d", &s);
    bfs(graph, numV, s);
    for (int i = 0; i < numV; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
*/
