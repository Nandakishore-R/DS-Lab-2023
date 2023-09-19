
#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *t;
    int a;
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&a);
    if(head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = a;
        head->next = NULL;
    }
    else
    {
        t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = (struct node *)malloc(sizeof(struct node));
        t->next->data = a;
        t->next->next = NULL;
    }
}

void delete()
{
    struct node *t;
    int a;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else 
    {
        printf("\nEnter the element to be deleted : ");
        scanf("%d",&a);
        if(head->data == a)
        {
            head = head->next;
            printf("\n%d is deleted\n\n",a);
        }
        else
        {
            t=head;
            while(t->next != NULL && t->next->data != a)
            {
                t=t->next;
            }
            if(t->next == NULL)
                printf("\nElement not found\n\n");
            else
            {
                t->next=t->next->next;
                printf("\n%d is deleted\n\n",a);
            }
        }
    }
}

void disp()
{
    struct node *t;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        t=head;
        printf("\n");
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t = t->next;
        }
        printf("\n\n");
    }
}

void count()
{
    struct node *t;
    int count=0;
    t=head;
    while(t!=NULL)
    {
        t = t->next;
        count++;
    }
    printf("\nThe number of elements in the linked list is : %d\n\n",count);
}

void search()
{
    struct node *t;
    int a,index = 0,flag=0;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        printf("\nEnter the element to be searched : ");
        scanf("%d",&a);
        t=head;
        while(t!= NULL)
        {
            if(t->data == a)
            {
                flag = 1;
                printf("Element found at position %d\n",index);
            }
            t=t->next;
            index++;
        }
        if(flag == 0)
            printf("Element not found\n");
        printf("\n");
    }
}

void replace()
{
    struct node *t;
    int a,b,index = 0,flag=0,choice;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        printf("\nEnter the element to be searched : ");
        scanf("%d",&a);
        t=head;
        while(t!= NULL)
        {
            if(t->data == a)
            {
                flag = 1;
                printf("Element found at position %d\n",index);
                printf("Do you want to replace it?\n1 - Yes\t2 - No\n");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1 : printf("Enter the element to replace %d : ",a);
                             scanf("%d",&b);
                             t->data = b;
                             break;
                    case 2 : break;
                    default : printf("wrong choice");
                              continue;
                            
                };
                
            }
            t=t->next;
            index++;
        }
        if(flag == 0)
            printf("Element not found\n");
        printf("\n");
    }
}

void reverse()
{
    struct node *t,*temp1,*temp2;
    int i=0;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        t=head;
        temp2=NULL;
        while(t!=NULL)
        {
            temp1 = t;
            t=t->next;
            temp1->next = temp2;
            temp2 = temp1;
        }
        head = temp2;
    }
    printf("\nThe linked list is reversed\n\n");
}

void sort()
{
    struct node *i,*j,*temp2;
    int temp;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        for(i=head; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j=j->next)
            {
                if(j->data < i->data)
                {
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
        }
    }
    printf("\nThe linked list is sorted\n\n");
}
   
int menu()
{
    int ch;
    printf("Insert - 1\nDelete - 2\nDisplay - 3\nCount the no. of elements - 4\n");
    printf("Search - 5\nFind and replace - 6\nSort - 7\nReverse - 8\nExit - 9\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

int main()
{
    int i,ch,a;
    for(ch = menu();ch != 9;ch = menu())
    {
        switch(ch)
        {
            case 1 : insert();
                     break;
            case 2 : delete();
                     break;
            case 3 : disp();
                     break;
            case 4 : count();
                     break;
            case 5 : search();
                     break;
            case 6 : replace();
                     break;
            case 7 : sort();
                     break;
            case 8 : reverse();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
    return 0;
}