#include <stdio.h>
#include <stdlib.h>

int need;
int check = 1;

typedef struct node *nodePointer;
typedef struct node
{
    int finish;
    int data;
    nodePointer vertex;
} node;

void dfs(nodePointer v, nodePointer q[])
{
    nodePointer w;
    v->finish = 1;
    if (check)
    {
        printf("%d", v->data);
        check = 0;
    }
    else
    {
        printf(" %d", v->data);
    }
    for (w = q[v->data]; w; w = w->vertex)
    {
        if (!(w->vertex->finish))
        {
            dfs(w->vertex, q);
        }
    }
}

int main()
{
    scanf("%d", &need);
    int tmp[need][need];
    for (int i = 0; i < need; i++)
    {
        for (int j = 0; j < need; j++)
        {
            scanf("%d", &tmp[i][j]);
        }
    }
    node *NodeList[need];
    for (int i = 0; i < need; i++)
    {
        NodeList[i] = malloc(sizeof(node));
        NodeList[i]->finish = 0;
        NodeList[i]->data = i;
        NodeList[i]->vertex = NULL;
    }

    for (int i = 0; i < need; i++)
    {
        for (int j = 0; j < need; j++)
        {
            if (tmp[i][j] == 1)
            {
                for (; NodeList[i]->vertex == NULL; NodeList[i] = NodeList[i]->vertex)
                {
                }
                NodeList[i]->vertex->data = j;
                NodeList[j]->vertex->data = i;
            }
        }
    }
    dfs(NodeList[0],NodeList);
}