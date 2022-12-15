#include <stdio.h>
#include <stdlib.h>

int i, j;
int k, a, b, u, v, n;
int e = 1;
int min, c[9][9], parent[9];
int flag = 1;
int find(int);
int uni(int, int);

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0)
                c[i][j] = 999;
        }
    }
    while (e < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (c[i][j] < min)
                {
                    min = c[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            if (flag)
            {
                printf("%d", min);
                flag = 0;
            }
            else
            {
                printf(" %d", min);
            }
            e++;
        }
        c[a][b] = c[b][a] = 999;
    }
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}