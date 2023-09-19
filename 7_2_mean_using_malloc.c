#include<stdio.h>
#include<malloc.h>
void main()
{
	int *ptr,n,sum=0,i;
	float mean;
	printf("Enter value for n : ");
	scanf("%d",&n);
	ptr=(int *)malloc(n*sizeof(int));
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	for(i=0;i<n;i++)
	{
		sum=sum+*(ptr + i);
	}
	mean=sum/n;
	printf("Mean  is %f",mean);
}