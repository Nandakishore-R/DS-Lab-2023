#include<stdio.h>
#define SIZE 10
int insert(int arr[],int pos)
{
	if(pos==SIZE-1)
	{
		printf("Array is full\n");

	}
	else
	{
		printf("Enter element to be inserted\n");
		pos++;
		scanf("%d",&arr[pos]);
		
	}
	return pos;
}
int delete(int a[],int pos)
{	
	if(pos==-1)
	{
		printf("Array is empty\n");
	}
	else
	{
		int p,i;
		printf("\nEnter position to be deleted\n");
		scanf("%d",&p);
	 	if((p>pos)||(p<0))
		{
			printf("Wrng position\n");
		}
		else
		{
			for(i=p;i<pos;i++)
			{
				a[i]=a[i+1];
			}
			pos--;
			printf("Deleted successfully\n");
		}
	}
	return pos;
}

void display(int a[],int pos)
{
	int i;
	printf("\nThe elements are\n");
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sort(int a[],int pos)
{
int i,j,temp;
for(i=0;i<pos;i++)
{
	for(j=i+1;j<=pos;j++)
	{
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
}
display(a,pos);	
}
void search(int a[],int pos)
{
	int flag=0,num,i;
	printf("Enter element to be searched : ");
	scanf("%d",&num);
	for(i=0;i<=pos;i++)
	{
		if(num==a[i])
		{
			flag=1;
			printf("Element found at position : %d\n",i);
			break;
		}
	}
	if(flag==0)
	{
		printf("Element not found\n");
	}
}
int menu()
{
	int ch;
	printf("\n1.Insert\n2.Delete\n3.Sort\n4.Display\n5.Search\n6.Exit\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void main()
{
	int arr[SIZE],pos=-1;
	int ch;
	for(ch = menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
				pos = insert(arr,pos);
				break;
			case 2:
				pos=delete(arr,pos);
				break;
			case 3:
				sort(arr,pos);
				break;
			case 4:
				display(arr,pos);
				break;
			case 5:
				search(arr,pos);
				break;
			default:
				printf("Wrong choice\n");
				break;
		}
	}	
}