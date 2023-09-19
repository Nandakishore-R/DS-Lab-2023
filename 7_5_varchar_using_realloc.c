#include <stdio.h>
#include <malloc.h>

int main()
{
    char ch;
    char *ptr,i=0;
    printf("Enter the string\n");
    ptr = (char *) malloc(1 * sizeof(char));
    do
    {
        scanf("%c",&ch);
        *(ptr + i) = ch;
        i++;
        ptr =(char *) realloc(ptr, i * sizeof(char));
    }
    while(ch != '\n');
    *(ptr + i) = '\0';
    printf("\nThe string is \n%s",ptr);
    return 0;
}
