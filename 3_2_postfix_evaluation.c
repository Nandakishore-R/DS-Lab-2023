#include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    
    #define MAX_SIZE 100
    
    int isOperator(char ch) {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return 1;
        else
            return 0;
    }

    int applyOperator(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;

        }
    }

    void evaluatePostfix(char postfix[]) {
    
    int i;
    int stack[MAX_SIZE];
    int top = -1;

    for(i=0; postfix[i] != '\0'; i++) {

        if(isdigit(postfix[i])) //if digit push it into stack
        {
            stack[++top] = postfix[i] - '0'; //to get the number of the character digit
        }
        else if(isOperator(postfix[i])) {
            int num2 = stack[top--];
            int num1 = stack[top--];
            stack[++top] = applyOperator(postfix[i], num1, num2); 
            /*pop two elements from stack.Evaluate it and then push it*/
        }

    }

    printf("%d", stack[0]);
    }
    int main()
    {
        char str[MAX_SIZE];
        printf("Enter postfix string : ");
        scanf("%s", str);
        evaluatePostfix(str);
    }
    
    
