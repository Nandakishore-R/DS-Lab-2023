#include<stdio.h>

int a[10][10],b[10][10],Res[10][10];
int r1,r2,c1,c2;

void read(int a[10][10],int r, int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	}	
}

void display(int arr[10][10], int r, int c)
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

void prod()
{
	int i,j,k;
	for (i = 0; i < r1; i++) {
       for (j = 0; j < c2; j++) {
     		Res[i][j] = 0;
            for (k = 0; k < c1; k++) {
               Res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
 
void main(){
    printf("Enter the number of rows and cols of 1st Matrix : ");
	scanf("%d%d",&r1,&c1);
	printf("Enter the number of rows and cols of 2nd Matrix : ");
	scanf("%d%d",&r2,&c2);
	if(c1 == r2)
	{
		printf("Enter the elements of A \n");
		read(a,r1,c1);
		printf("Enter the elements of A \n");
		read(b,r2,c2);
		prod();
		printf("Matrix A is\n");
	    display(a,r1,c1);
	    printf("Matrix B is\n");
	    display(b,r2,c2);
	    printf("Product Matrix is \n");
	    display(Res,r1,c2);
	}

	
}