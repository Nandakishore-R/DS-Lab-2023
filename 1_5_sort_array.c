#include<stdio.h>
#define SIZE 10
int a[SIZE],i,n,j;
void read()
{
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
}
void sort()
{
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
	}
}
void display()
{
	sort();
	printf("Sorted elements are :");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	read();
	sort();
	display();
	return 0;
}
