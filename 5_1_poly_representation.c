#include<stdio.h>
int expres[10],coeres[10], n3;
void read(int exp[],int coe[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0)
		   printf("Enter the coefficient and exponent of 1st term : ");
		else if (i==n-1)
		   printf("Enter the coefficient and exponent of last term : ");
        else
		   printf("Enter the coefficient and exponent of next term : ");
        scanf("%d%d",&coe[i],&exp[i]);
	}
}
void disp(int exp[],int coe[],int n)
{   
	
    int i;
	printf("%dx^%d",coe[0],exp[0]);
	for(i=1;i<n;i++)
	{
	  if(exp[i] == 0)
	  {
	  	if(coe[i] < 0)
	  	
	      printf(" - %d",-coe[i]);
	    else
	  	  printf(" + %d",coe[i]);
	  }
	  else
	  {
	  	if(coe[i] < 0)
	      printf(" - %dx^%d",-coe[i],exp[i]);
	    else
	  	  printf(" + %dx^%d",coe[i],exp[i]);
      }
    }
	
}

void main(){
	int exp1[10],exp2[10],coe1[10],coe2[10], n1,n2,i;
	printf("Enter the number of terms of The polynomial : ");
	scanf("%d",&n1);
	printf("Enter the terms of 1st polynomial\n");
	read(exp1,coe1,n1);
	printf("\nThe polynomial is \n");
	disp(exp1,coe1,n1);
}
