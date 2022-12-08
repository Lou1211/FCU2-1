#include <stdio.h>
#include <stdlib.h>

int need;
int check = 1;
int tmp[10][10];
int visit[9] = {0};

typedef struct node *nodePointer;
typedef struct node
{
    int data;
    nodePointer vertex;
} node;

node *list[10] = {0};

void add_edge(int a, int data)
{
    node *e;
    e->data = data;
    e->vertex = list[a];
    list[a] = e;
}

void dfs(int v)
{
    nodePointer w;
    visit[v] = 1;
    if (check)
    {
        printf("%d", v);
        check = 0;
    }
    else
    {
        printf(" %d", v);
    }
    for (w = list[v]; w; w = w->vertex)
    {
        if (!(visit[w->vertex->data]))
        {
            dfs(w->vertex->data);
        }
    }
}

int main()
{
    scanf("%d", &need);
    int num = 0;
    for (int i = 0; i < need; i++)
    {
        for (int j = 0; j < need; j++)
        {
            scanf("%d", &tmp[i][j]);
        }
    }
    for (int i = 0; i < need; i++)
    {
        for (int j = i + 1; j < need; j++)
        {
            if (tmp[i][j] == 1)
            {
                add_edge(i, j);
            }
        }
    }
    dfs(0);
}