#include<stdio.h>
int a[20],n;
void insert()
{
	int i;
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
}
void occurence()
{
	int num,i,occ[20],occpos=-1;
	printf("Enter the element to be searched\n");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(a[i]==num)
		{
			occpos++;
			occ[occpos] = i;
		}
	}
	if(occpos==-1)
	{
		printf("Element not found");
	}
	else
	{
		printf("Element found at positions : ");
		for(i=0;i<=occpos;i++)
		{
			printf("%d\t",occ[i]);
			
		}
	}
	
}
void main()
{
	insert();
	occurence();
}