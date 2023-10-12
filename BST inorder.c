#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node tree;
tree *root = NULL;

void insert(int e)
{
    tree *p,*x,*t;
    if(root==NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        p=root;
        while(p!=NULL)
        {
            x=p;
            if(p->data > e)
                p=p->left;
            else if(p->data < e)
                p=p->right;
            else
            {
                printf("Repeated value not allowed!");
                return;
            }
        }
        t=(tree *)malloc(sizeof(tree));
        t->data=e;
        t->right=NULL;
        t->left=NULL;
        if(x->data < e)
            x->right = t;
        else
            x->left = t;
        
    }
}

void inorder(tree *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
    }
}

void main()
{
    insert(100);
    insert(50);
    insert(200);
    insert(10);
    insert(10);
    insert(60);
    insert(150);
    insert(250);
    inorder(root);
}
