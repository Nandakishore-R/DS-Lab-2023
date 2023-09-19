6_1_Stack_operations.c
#include<stdio.h>
#define SIZE 5
int stack[SIZE],top=-1;
void push()
{
	if(top==SIZE-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		printf("Enter element to be pushed\n");
		top++;
		scanf("%d",&stack[top]);
	}
}
void pop()
{	
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
	printf("Popped item is : %d",stack[top]);
	top--;	
	}
}

void peek()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Element at the top is : %d",stack[top]);
	}
}
int menu()
{
	int ch;
	printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch;
	ch = menu();
	while(ch!=4)
	{
		switch(ch)
		{     
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			
			default:
				printf("Wrong choice\n");
				break;
		}
		ch=menu();
	}
	
	return 0;		
}