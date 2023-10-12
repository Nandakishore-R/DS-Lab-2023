#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;

void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data = e;
		head->prev = head->next = NULL;
	}
	else
	{
		t=head;
		while(t->next != NULL)
			t=t->next;
		t->next = (struct node *)malloc(sizeof(struct node));
		t->next->data = e;
		t->next->prev = t;
		t->next->next = NULL;
	}
}

void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("Empty!");
	}
	else if(head->data ==e && head->next == NULL)
	{
		head = NULL;
	}
	else if(head->data == e)
	{
		head=head->next;
		head->prev = NULL;
	}
	else
	{
		t=head;
		while(t!=NULL && t->data!=e)
			t=t->next;
		if(t==NULL)
			printf("Element not found\n");
		else if(t->next == NULL)
		{
			t->prev->next = NULL;
		}
		else
		{
			t->prev->next = t->next;
			t->next->prev = t->prev;
		}
	}
}

void display()
{
	struct node *t;
	if(head == NULL)
	{
		printf("Doubly Linked List empty\n");
	}
	else
	{
		t=head;
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
			
		}
		printf("\n");
	}
}

int menu()
{
    int ch;
    printf("\nInsert - 1\nDelete - 2\nDisplay - 3\nExit - 4\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

int main()
{
    int i,ch,e;
    for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter the value to be inserted : ");
            		 scanf("%d",&e);
					 insert(e);
                     break;
            case 2 : printf("Enter the value to be deleted : ");
            		 scanf("%d",&e);
					 delete(e);
                     break;
            case 3 : display();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
    return 0;
}
