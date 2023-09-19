#include<stdio.h>
int n;
void display(int a[],int i)
{
	if(i>=0)
	{
		printf("%d\t",a[i]);
		i--;
		display(a,i);
	}
}
int main()
{
	int a[20],i;
	printf("Enter size of elements : ");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	display(a,n-1);
	return 0;
}