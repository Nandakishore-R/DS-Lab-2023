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

tree *stack[20];
int top=-1;

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
                printf("Repeated value not allowed!\n");
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

void preorder(tree *r)
{
    if(r!=NULL)
    {
        printf("%d\t",r->data);
		preorder(r->left);	
        preorder(r->right);
    }
}

void push(tree *e)
{
	if(top==19)
	{
		printf("Stack is full\n");
	}
	else
	{
		top++;
		stack[top] = e;
	}
}
tree * pop()
{	
	tree *t;
	if(top==-1)
	{
		t = NULL;
	}
	else
	{
	t = stack[top--];	
	}
	return t;
}

void preorder2(tree *root)
{
    tree *t=root;
    tree *temp;
    
    while(temp != NULL)
    {
        if(t==NULL)
        {
        	temp = pop();
        	if (temp == NULL)
        		continue;
        	t = temp->right;

        }
        else
        {
            push(t);
            printf("%d\t",t->data);
            t=t->left;
        }
    }
}

int main()
{
    insert(45);
    insert(15);
    insert(79);
    insert(10);
    insert(20);
    insert(55);
    insert(90);
    insert(12);
    insert(50);
    preorder2(root);
    return 0;
}
