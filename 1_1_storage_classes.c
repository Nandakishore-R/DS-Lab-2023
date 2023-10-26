#include<stdio.h>
int global_var;

void staticfn(){
	static int static_var;
	printf("The value of static variable is %d\n",static_var++);
}
void main()
{
	register int register_var;
	int local_var = 10;
	staticfn();
	printf("Inside the main function\n");
	printf("The value of global variable is %d\n",global_var);
	staticfn();
	printf("The value of local variable is %d\n\n",local_var);
	printf("The value of register variable is %d\n\n",register_var);
	{
		int local_var=20;
		printf("Inside Block A\n");
		global_var++;
		printf("The value of global variable is %d\n",global_var);
		staticfn();
		printf("The value of local variable is %d\n\n",local_var);
	}
	{
		printf("Inside Block B\n");
		printf("The value of global variable is %d\n",global_var);
		staticfn();
		printf("The value of local variable is %d",local_var);
	}
}
