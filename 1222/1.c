#include <stdio.h>

int num;

void qs(int a[], int l, int r)
{
    int tmp;
    int key, i, j;
    if (l < r)
    {
        i = l;
        j = r + 1;
        key = a[l];
        while (1)
        {
            while (a[++i] < key)
                ;
            while (a[--j] > key)
                ;
            if (i >= j)
                {break;}
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        tmp = a[l];
        a[l] = a[j];
        a[j] = tmp;
            for (int q = 0; q < num; q++)
            {
                if (q == 0)
                {
                    printf("%d", a[q]);
                }
                else
                {
                    printf(" %d", a[q]);
                }
            }
            printf("\n");
        qs(a, l, j - 1);
        qs(a, j + 1, r);
    }
}

int main()
{
    scanf("%d", &num);
    int a[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
    qs(a, 0, num-1);
}