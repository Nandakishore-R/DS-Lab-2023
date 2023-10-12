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

void inorder(tree *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
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

void inorder2(tree *r)
{

    tree *t=root;
    tree *temp;
    
    do
    {
        if(t==NULL)
        {
        	temp = pop();
        	if (temp == NULL)
        		continue;
        	printf("%d\t",temp->data);
        	t = temp->right;

        }
        else
        {
            push(t);
            t=t->left;
        }
    }while(temp!= NULL);
    
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
    inorder(root);
    printf("\n");
    inorder2(root);
    return 0;
}
