
#include <stdio.h>
#include <malloc.h>
void read(int *ptr,int n)
{
    int i;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
}
void mode(int *ptr,int n)
{
   int large = 0, i, j,k=0, count;
   int a[10];
   for (i = 0; i < n; ++i) 
   {
      count = 0;
      for (j = i; j < n; ++j)
      {
         if (*(ptr + j) == *(ptr + i))
            ++count;
      }
      if (count >= large)
      {
         if (count > large)
            k=0;
         a[k] = *(ptr + i);
         large = count;
         k++;
      }
   }
    if(k==1)
        printf("The mode is %d",a[0]);
    else
    {
        printf("The modes are : ");
        for(i=0;i<k;i++)
            printf("%d\t",a[i]);
    }
}
void main()
{
    int i,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *ptr = (int *) calloc(n,sizeof(int));
    read(ptr,n);
    mode(ptr,n);
}




//Mode using sort

/*

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <malloc.h>
void read(int *ptr,int n)
{
    int i;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
}
void sort(int *ptr,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)
            {
                if (*(ptr + i) > *(ptr + j))
                {
                    temp = *(ptr + i);
                    *(ptr + i) = *(ptr + j);
                    *(ptr + j) = temp;
                }
            }
    }
}
void finmode(int *ptr,int n)
{
    int i,j,k=0,count=0,large = 0;
    int a[10];
    sort(ptr,n);
    for(i=0; i<n; i=j)
    {
         for(j=i; *(ptr + j) == *(ptr + i); j++)
         {
             count++;
         }
         if(count >= large)
         {
            if (count > large)
                k=0;
            a[k] = *(ptr + i);
            large = count;
            k++;
         }
         count = 0;
    }
    if(k==1)
        printf("The mode is %d",a[0]);
    else
    {
        printf("The modes are : ");
        for(i=0;i<k;i++)
            printf("%d\t",a[i]);
    }
}
int main()
{
    int i,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *ptr = (int *) calloc(n,sizeof(int));
    read(ptr,n);
    mode(ptr,n);
    return 0;
}

*/