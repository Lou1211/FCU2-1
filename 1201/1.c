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
node *root;

void insert(node *root, node *tmp)
{
    if (root->data > tmp->data)
    {
        if (root->left == NULL)
        {
            root->left = tmp;
        }
        else
        {
            insert(root->left, tmp);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = tmp;
        }
        else
        {
            insert(root->right, tmp);
        }
    }
}

int searchRoot(node *tmp)
{
    if (tmp->right != NULL)
    {
        searchRoot(tmp->right);
    }
    else
    {
        return tmp->data;
    }
}

void preorder(node *Pointer)
{
    if (Pointer)
    {
        // printf("%d ", Pointer->data);
        if (count == 0)
        {
            printf("%d", Pointer->data);
            count++;
        }
        else
        {
            printf(" %d", Pointer->data);
        }
        preorder(Pointer->left);
        preorder(Pointer->right);
    }
}

int main()
{
    scanf("%d", &num);
    node *tree[num];
    // printf("0");
    root = tree[0];
    for (int i = 0; i < num; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        tree[i] = malloc(sizeof(node));
        tree[i]->data = tmp;
        tree[i]->left = NULL;
        tree[i]->right = NULL;
        if (i == 0)
        {
            root = tree[0];
        }
        else
        {
            insert(root, tree[i]);
        }
    }

    int find;
    scanf("%d", &find);
    for (int i = 0; i < num; i++)
    {
        if (tree[i]->data == find)
        {
            int tmp;
            if (tree[i]->left != NULL || tree[i]->right != NULL)
            {
                tmp = searchRoot(tree[i]->left);
                printf("tmp = %d\n", tmp);
                for (int j = 0; j < num; j++)
                {
                    printf("%d %d,r=%d l=%d\n", j, tree[j]->data, tree[j]->right->data, tree[j]->left->data);
                    if (tree[j]->left->data == tmp)
                    {
                        printf(" l\n");
                        tree[j]->left = NULL;
                        j = num - 1;
                    }
                    else if (tree[j]->right->data == tmp)
                    {
                        printf(" r\n");
                        tree[j]->right = NULL;
                        j = num - 1;
                    }
                }
                tree[i]->data = tmp;
            }
            else
            {
                printf(" 2\n");
                for (int j = 0; j < num; j++)
                {
                    printf(" %d\n", j);
                    if (tree[j]->left->data == find)
                    {
                        tree[j]->left = NULL;
                        j = num - 1;
                    }
                    else if (tree[j]->right->data == find)
                    {
                        tree[j]->right = NULL;
                        j = num - 1;
                    }
                }
            }
        }
    }

    node *add;
    add = malloc(sizeof(node));
    scanf("%d", &add->data);
    add->left = NULL;
    add->right = NULL;
    insert(root, add);

    preorder(root);
}
// http://programer-learn.blogspot.com/2010/12/c_21.html