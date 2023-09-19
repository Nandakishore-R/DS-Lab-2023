#include<stdio.h>
#include<string.h>
#define SIZE 20
char stack[SIZE];
int top = -1;

void push(char ch) {
    if(top == SIZE-1) {
        printf("ERROR : Stack overflow!! \n");
    }
    else
    {
    	stack[++top] = ch;
	}   
}

char pop() {
    if(top == -1) {
        printf("ERROR : Stack underflow!! \n");
    }
    return stack[top--];
}
int main() {

    char str[50];
    int i;
    printf("Enter a string : ");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    
    for(i=0;i<strlen(str);i++)
    {
        str[i] = pop();
    }
    push('\0');
    printf("Reversed string is : %s",str);
    
    
    
    return 0;
}