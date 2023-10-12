#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;
tree *root=NULL;

void insert(int e)
{
    tree *x,*p,*t;
    if(root == NULL)
    {
        root=(tree *)malloc(sizeof(tree));
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
            if(e>p->data)
                p=p->right;
            else if(e<p->data)
                p=p->left;
            else
            {
                printf("Duplicates value not allowed\n");
                return;
            }
        }
        t=(tree *)malloc(sizeof(tree));
        t->data = e;
        t->left=NULL;
        t->right=NULL;
        if(e>x->data)
            x->right=t;
        else
            x->left=t;
    }
}

void inorder(tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void preorder(tree *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

int main()
{
    insert(50);
    insert(60);
    insert(45);
    insert(70);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
