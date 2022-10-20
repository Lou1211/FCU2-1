#include <stdio.h>
#include <stdlib.h>

int p;

typedef struct tower
{
    int pinHsiu;
    struct tower *next;
} tower;

tower a[10];
tower b[10];
tower c[10];

typedef struct tower Stack_tower;
typedef Stack_tower *Linked_Stack;
Linked_Stack top[3] = {NULL};
Linked_Stack shows[3] = {NULL};

int pop(int n) //刪除堆疊的資料
{
    Linked_Stack ptr = top[n];
    int temp;
    temp = ptr->pinHsiu;
    top[n] = top[n]->next;
    free(ptr);
    return temp;
}

int isEmpty(int n)
{
    if (shows[n] == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int show(int n)
{
    if (isEmpty(n))
    {
    }
    else if (!isEmpty(n))
    {
        Linked_Stack ptr = shows[n];
        int temp;
        temp = ptr->pinHsiu;
        shows[n] = shows[n]->next;
        return temp;
    }
}

void showall()
{
    int tmpc = 0;
    int tmp[p];
    for (int i = 0; i < p; i++)
    {
        tmp[i] = 0;
    }
    printf("Tower1:");
    shows[0] = top[0];
    for (int i = 0; i < p; i++)
    {
        if (isEmpty(0))
        {
        }
        else if (!isEmpty(0))
        {
            tmp[i] = show(0);
            tmpc++;
        }
    }
    for (int i = tmpc-1; i >= 0; i--)
    {
        if (i==0)
        {
            printf("%d", tmp[i]);
        }
        else{
            printf("%d ", tmp[i]);
        }
    }
    printf("\n");

    tmpc = 0;
    for (int i = 0; i < p; i++)
    {
        tmp[i] = 0;
    }
    printf("Tower2:");
    shows[1] = top[1];
    for (int i = 0; i < p; i++)
    {
        if (isEmpty(1))
        {
        }
        else if (!isEmpty(1))
        {
            tmp[i] = show(1);
            tmpc++;
        }
    }
    for (int i = tmpc-1; i >= 0; i--)
    {
        if (i==0)
        {
            printf("%d", tmp[i]);
        }
        else{
            printf("%d ", tmp[i]);
        }
    }
    printf("\n");

    tmpc = 0;
    for (int i = 0; i < p; i++)
    {
        tmp[i] = 0;
    }
    printf("Tower3:");
    shows[2] = top[2];
    for (int i = 0; i < p; i++)
    {
        if (isEmpty(2))
        {
        }
        else if (!isEmpty(2))
        {
            tmp[i] = show(2);
            tmpc++;
        }
    }
    for (int i = tmpc-1; i >= 0; i--)
    {
        if (i==0)
        {
            printf("%d", tmp[i]);
        }
        else{
            printf("%d ", tmp[i]);
        }
    }
    printf("\n");
    printf("\n");
}

void add(int pinHsiu, int n) //加入堆疊的資料
{
    Linked_Stack new_add_node[n];
    new_add_node[n] = (Linked_Stack)malloc(sizeof(Stack_tower));
    new_add_node[n]->pinHsiu = pinHsiu;
    new_add_node[n]->next = top[n];
    top[n] = new_add_node[n];
}

void Towermove(int num, int j, int q, int k)
{
    if (num == 1)
    {
        add(pop(j), k);
        showall();
    }
    else
    {
        Towermove(num - 1, j, k, q);
        add(pop(j), k);
        showall();
        Towermove(num - 1, q, j, k);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = num; i >= 1; i--)
    {
        add(i, 0);
    }
    p = num;
    showall();
    Towermove(num, 0, 1, 2);
}