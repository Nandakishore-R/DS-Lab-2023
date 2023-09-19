
#include<stdio.h>
#include<string.h>
struct emp
{
    char empno[10];
    char empname[20];
    int empsalary;
    char empdno[10];
};

void read(struct emp E[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the details of Employee %d\n",i+1);
        printf("Enter the Employee No : ");
        scanf("%s",E[i].empno);
        printf("Enter the name : ");
        scanf("%s",E[i].empname);
        printf("Enter the salary : ");
        scanf("%d",&E[i].empsalary);
        printf("Enter the department no : ");
        scanf("%s",E[i].empdno);
        printf("\n");
    }
}

void disp(struct emp *E, int n)
{
    int i;
    
    printf("Emp no\tName\t  Salary\tDepNo\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%s\t%d\t%s\n",E[i].empno,E[i].empname,E[i].empsalary,E[i].empdno);
    }
    printf("\n");
}
void search(struct emp *E, int n)
{
	char eno[20];
	int i,flag=0;
	 printf("Enter employee No to be searched : ");
	 scanf("%s",eno);
	 for(i=0;i<n;i++)
	 {
	 	if(strcmp(E[i].empno,eno) ==0)
	 	{
	 		flag=1;
			printf("The employee is found\n");
			printf("Emp No : %s\nName : %s\nSalary : %d\nDep No : %s\n",E[i].empno,E[i].empname,E[i].empsalary,E[i].empdno);
			break;
		}
	 }
	if(flag == 0)
		printf("%s is not found\n",eno);
}
void sortSalary(struct emp *E, int n)
{
    struct emp temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(E[i].empsalary > E[j].empsalary)
            {
                temp = E[i];
                E[i] = E[j];
                E[j] = temp;
            }
        }
    }
    
}
void sortName(struct emp *E, int n)
{
    struct emp temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(E[i].empname,E[j].empname) > 0)
            {
                temp = E[i];
                E[i] = E[j];
                E[j] = temp;
            }
        }
    }
    
}
int delete(struct emp *E, int n)
{
    int i,flag=0;
    char no[10];
    printf("Enter the employee no to be deleted : ");
    scanf("%s",no);
    for(i=0 ; i<n ; i++)
    {
        if (strcmp(E[i].empno,no) == 0)
        {
            flag = 1;
            for( ; i<n-1;i++)
			{
				E[i] = E[i+1];
			}
			n--;
			printf("Deleted successfully\n");
			break;
		}
    }
    if(flag == 0)
        printf("Employee not found");
	return n;
}
void main()
{
    int n;
    struct emp E[20];
    printf("Enter the number of employees : ");
    scanf("%d",&n);
    read(E,n);
    disp(E,n);
    printf("\n\nThe employee list sorted by salary\n");
    sortSalary(E,n);
    disp(E,n);
    printf("\n\nThe employee list sorted by Name\n");
    sortName(E,n);
    disp(E,n);
    search(E,n);
    n = delete(E,n);
    disp(E,n);
}
