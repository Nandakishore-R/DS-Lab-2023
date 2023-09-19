#include<stdio.h>
int n;
void display(int a[])
{
	static int i = 0;
	if(i<n)
	{
		printf("%d\t",a[i]);
		i++;
		display(a);
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
	display(a);
	return 0;
}