#include <stdio.h>
#include <stdlib.h>

typedef struct listList *listPointer;

typedef struct listList
{
    int data;
    listPointer link;
} listList;

#define MALLOC(p, s)              \
    if (!((p) = malloc(s)))       \
    {                             \
        fprintf(stderr, "error"); \
        exit(EXIT_FAILURE);       \
    }

listPointer create(int times[20])
{
    listPointer first, sec;
    MALLOC(first, sizeof(*first));
    MALLOC(sec, sizeof(*sec));
    first->data = times[0];
    first->link = NULL;
    sec->data = times[1];
    sec->link = first;
    return first;
}

int insert(listPointer *f, listPointer x, int d)
{
    listPointer tmp;
    MALLOC(tmp, sizeof(tmp));
    tmp->data = d;
    if (*f)
    {
        tmp->link = x->link;
        x->link = tmp;
    }
    else{
        tmp->link = NULL;
        *f = tmp;
    }
    return tmp;
}

void printList(listPointer f){
    while (f!=NULL)
    {
        printf("%d ",f->data);
        f = f->link;
    }
}

int findNum(listPointer f,int find){
    while (f!=NULL)
    {
        if (f->data == find)
        {
            //f = f->link;
            return f;
        }
        f = f->link;
    }
}

int main()
{
    int time;
    scanf("%d", &time);
    int times[20];
    for (int i = 0; i < time; i++)
    {
        scanf("%d", &times[i]);
    }
    int fir = create(times);
    int las = fir;
    for (int i = 1; i < time; i++)
    {
        las = insert(fir, las, times[i]);
    }
    int find,add;
    scanf("%d%d",&find,&add);
    las = findNum(fir,find);
    insert(fir, las, add);
    for (int i = 0; i < time; i++)
    {
        if(times[i]==find){
            add = i;
        }
    }
    printf("%d\n",add);
    printList(fir);

}