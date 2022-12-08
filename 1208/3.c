#include <stdio.h>
#include <stdlib.h>

int need;
int check = 1;
int tmp[10][10];
int visit[10] = {0};

void dfs(int i)
{
    visit[i] = 1;
    if (check)
    {
        printf("%d", i);
        check = 0;
    }
    else
    {
        printf(" %d", i);
    }
    for (int j = 0; j < need; j++)
        if (tmp[i][j] && !visit[j])
            dfs(j);
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
    for (int j = 0; j < need; j++)
    {
        if (!visit[j])
        {
            dfs(j);
        }
    }
}