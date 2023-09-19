#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};

void main()
{
	struct node *head = NULL;
	int **ArrayAddresses;
	int *p = (int *)malloc(sizeof(int));
	ArrayAddresses = (int **)malloc(sizeof(int *));

	int size=0,i,j,ch;
	do
	{
		printf("Enter a number : ");
		p = (int *) realloc(p, (size+1) *sizeof(int));
		scanf("%d",(p+size));
		size++;
		printf("\nDo you want to continue? (1.yes)  : ");
		scanf("%d",&ch);
	}
	while(ch==1);
	*ArrayAddresses = p;
	ArrayAddresses = (int **) realloc(ArrayAddresses, sizeof(int *) * size);

  	for(i=1;i<size;i++)
	{
		int *pn = (int *) malloc(sizeof(int));
		for(j=0;j<size-i;j++)
		{
			pn = (int *) realloc(pn, (j+1) * sizeof(int));
			*(pn + j) = *(*(ArrayAddresses + i - 1) + j) + *(*(ArrayAddresses + i -1) + j + 1);
			//Here we are adding the values of the previous array. Therefore -1 is used. 
		}
		*(ArrayAddresses + i) = pn;
	}
	
	for(i=0; i<size ; i++)
	{
		for(j=0;j<size-i;j++)
		{
			printf("%d\t",*(*(ArrayAddresses + i) + j));
		}
		printf("\n");
	}
}
