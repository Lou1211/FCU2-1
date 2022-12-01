#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer left, right, Fp;
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
            tmp->Fp = root;
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
            tmp->Fp = root;
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
    node *dnode;

    for (int i = 0; i < num; i++)
    {
        if (tree[i]->data == find)
        {
            int tmp;
            if (tree[i]->left != NULL)
            {
                tmp = searchRoot(tree[i]->left);
                //printf("tmp = %d\n", tmp);
                dnode = tree[i]->left;
                while (dnode->right != NULL)
                {
                    dnode = dnode->right;
                }
                if (dnode->Fp->left->data == tmp)
                {
                    dnode->Fp->left = NULL;
                }
                else if (dnode->Fp->right->data == tmp)
                {
                    dnode->Fp->right = NULL;
                }
                tree[i]->data = tmp;
            }
            else
            {
                if (tree[i]->Fp->left->data == find)
                {
                    tree[i]->Fp->left = NULL;
                }
                else if (tree[i]->Fp->right->data == find)
                {
                    tree[i]->Fp->right = NULL;
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
