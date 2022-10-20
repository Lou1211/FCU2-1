#include <stdio.h>
#include <stdlib.h>

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

void add(int pinHsiu, int n) //加入堆疊的資料
{
    Linked_Stack new_add_node;
    new_add_node = (Linked_Stack)malloc(sizeof(Stack_tower));
    new_add_node->pinHsiu = pinHsiu;
    new_add_node->next = top[n];
    top[n] = new_add_node;
}

void Towermove(int num, tower a[], tower b[], tower c[])
{
    if (num == 1)
    {
        add(pop(0), 2);
        printf("Tower1:");
        shows[0] = top[0];
        for (int i = 0; i < 3; i++)
        {
            if (isEmpty(0))
            {
            }
            else if (!isEmpty(0))
            {
                printf("%d ", show(0));
            }
        }
        printf("\n");
        printf("Tower2:");
        shows[1] = top[1];
        for (int i = 0; i < 3; i++)
        {
            if (isEmpty(1))
            {
            }
            else if (!isEmpty(1))
            {
                printf("%d ", show(1));
            }
        }
        printf("\n");
        printf("Tower3:");
        shows[2] = top[2];
        for (int i = 0; i < 3; i++)
        {
            if (isEmpty(2))
            {
            }
            else if (!isEmpty(2))
            {
                printf("%d ", show(2));
            }
        }
        printf("\n");
        printf("\n");
    }
    else
    {
        Towermove(num - 1, a, c, b);

        add(pop(0), 2);
        printf("Tower1:");
        shows[0] = top[0];
        for (int i = 0; i < 3; i++)
        {
            if (isEmpty(0))
            {
            }
            else if (!isEmpty(0))
            {
                printf("%d ", show(0));
            }
        }
        printf("\n");
        printf("Tower2:");
        shows[1] = top[1];
        for (int i = 0; i < 3; i++)
        {
            if (isEmpty(1))
            {
            }
            else if (!isEmpty(1))
            {
                printf("%d ", show(1));
            }
        }
        printf("\n");
        printf("Tower3:");
        shows[2] = top[2];
        for (int i = 0; i < 3; i++)
        {
            if (isEmpty(2))
            {
            }
            else if (!isEmpty(2))
            {
                printf("%d ", show(2));
            }
        }
        printf("\n");
        printf("\n");

        Towermove(num - 1, b, a, c);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        add(i, 0);
    }
    /*printf("Tower1:");
    shows[0] = top[0];
    for (int i = 0; i < num; i++)
    {
        printf("%d ", show(0));
    }
    printf("\n");
    printf("Tower2:");
    shows[1] = top[1];
    for (int i = 0; i < num; i++)
    {
        printf("%d ", show(1));
    }
    printf("\n");
    printf("Tower3:");
    shows[2] = top[2];
    for (int i = 0; i < num; i++)
    {
        printf("%d ", show(2));
    }
    printf("\n");
    printf("\n");*/
    Towermove(num, a, b, c);
}