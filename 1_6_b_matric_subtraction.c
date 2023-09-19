#include<stdio.h>
int a[10][10],b[10][10],DiffMat[10][10],r,c;
void read()
{
	int i,j;
	printf("Enter no of rows of matrices :");
	scanf("%d",&r);
	printf("Enter no of columns of matrices :");
	scanf("%d",&c);
	printf("Enter the elements of matrix A\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	}
	printf("Enter the elements of matrix B\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&b[i][j]);
		}
		
	}	
	
}
void display(int arr[10][10])
{
int i,j;
for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			
			printf("%d\t",arr[i][j]);
		
		}
		printf("\n");
		
	}	
}
void diff()
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			DiffMat[i][j] = a[i][j] - b[i][j];
		}
		
	}	
	
}
int main()
{
	read();
	printf("Matrix A is\n");
	display(a);
	printf("Matrix B is\n");
	display(b);
	diff();
	printf("Difference Matrix is \n");
	display(DiffMat);
	return 0;
}
