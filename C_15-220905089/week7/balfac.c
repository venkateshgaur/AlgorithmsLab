#include<stdio.h>
#include<stdlib.h>

typedef struct node * nodeptr;
struct node
{
    int val;
    nodeptr lchild, rchild;
    int bf;
};
nodeptr getnode()
{
    return ((nodeptr)malloc(sizeof(struct node)));
}
nodeptr insert(nodeptr root, int x)
{
    if (!root)
    {
        root = getnode();
        root->val = x;
        root->bf = 0;
        root->lchild = root->rchild = NULL;
        return root;
    }
    else
    {
        if (x < root->val)
            root->lchild = insert(root->lchild, x);
        else if (x > root->val)
            root->rchild = insert(root->rchild, x);
        else
            printf("no duplicates\n");
        return root;
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int height(nodeptr root)
{
    if(root)
        return max(height(root->lchild), height(root->rchild))+1;
}
void balfac(nodeptr root)
{
    if(root)
    {
        root->bf = height(root->lchild)-height(root->rchild);
        balfac(root->lchild);
        balfac(root->rchild);
    }
}
void printbalfac(nodeptr root)
{
    if(root)
    {
        printbalfac(root->lchild);
        printf("%d -> %d\n", root->val, root->bf);
        printbalfac(root->rchild);
    }
}
void main()
{
    int x;
    printf("enter root: ");
    scanf("%d", &x);
    printf("\n");
    printf("\n");
}