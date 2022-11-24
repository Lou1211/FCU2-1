#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer left, right;
} node;

int num;
int count = 0;

void inorder(node *Pointer)
{
    if (Pointer)
    {
        inorder(Pointer->left);
        if (count < num - 1)
        {
            printf("%d ", Pointer->data);
            count++;
        }
        else
        {
            printf("%d", Pointer->data);
        }
        inorder(Pointer->right);
    }
}

void preorder(node *Pointer)
{
    if (Pointer)
    {
        if (count < num - 1)
        {
            printf("%d ", Pointer->data);
            count++;
        }
        else
        {
            printf("%d", Pointer->data);
        }
        preorder(Pointer->left);
        preorder(Pointer->right);
    }
}

void postorder(node *Pointer)
{
    if (Pointer)
    {
        postorder(Pointer->left);
        postorder(Pointer->right);
        if (count < num - 1)
        {
            printf("%d ", Pointer->data);
            count++;
        }
        else
        {
            printf("%d", Pointer->data);
        }
    }
}

int main()
{
    scanf("%d", &num);
    node *tree[num];
    // printf("0");
    for (int i = 0; i < num; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        tree[i] = malloc(sizeof(node));
        tree[i]->data = tmp;
        tree[i]->left = NULL;
        tree[i]->right = NULL;
        // printf("1");
    }

    int find;
    scanf("%d", &find);

    for (int i = 0; i < num; i++)
    {
        if (tree[i]->data == find)
        {
            tree[i]->data = -999;
        }
    }

    for (int i = 0; i < num / 2; i++)
    {
        if ((i + 1) * 2 - 1 < num)
        {
            if (tree[(i + 1) * 2 - 1]->data != -999)
            {
                tree[i]->left = tree[(i + 1) * 2 - 1];
            }
            if (tree[(i + 1) * 2]->data != -999)
            {
                tree[i]->right = tree[(i + 1) * 2];
            }
        }
        // printf("2");
    }

    // printf("DLR:");
    preorder(tree[0]);
    // printf("\n");
    // count = 0;

    /*printf("LDR:");
    inorder(tree[0]);
    printf("\n");
    count = 0;

    printf("LRD:");
    postorder(tree[0]);
    printf("\n");
    count = 0;*/
}