#include<stdio.h>
#define SIZE 5

int q[SIZE];
int f=-1,r=-1;

void enqueuefront(int e)
{
    if(r == SIZE-1)
    {
        printf("FULL\n");
    }
    else 
    {
        if(f == -1)
        {
            f=r=0;
        }
        for(int i=r;i>=0;i--)
            q[i+1] = q[i];
        q[f] = e;
        r++;
    }
}

void enqueuerear(int e)
{
    if(r == SIZE-1)
    {
        printf("FULL\n");
    }
    else if(f == -1)
    {
        f=r=0;
        q[f]=e;
    }
    else{
     q[++r]=e;   
    }
}

void dequeuefront()
{
    if(f==-1)
        printf("EMPTY\n");
    else
    {
        if(f==r)
            f=r=-1;
        else
            f=(f+1) % SIZE;
    }
}
void dequeuerear()
{
    if(f==-1)
        printf("EMPTY\n");
    else
    {
        if(f==r)
            f=r=-1;
        else
            r--;
    }
}
void disp()
{
    if(f == -1)
        printf("Empty\n");
    else
    {
        for(int i=f;i<=r;i++)
            printf("%d\t",q[i]);
        printf("\n");
    }
}

void main()
{
    enqueuerear(10);
    enqueuerear(20);
    enqueuefront(30);
    disp();
    enqueuerear(40);
    enqueuefront(5);
    // enqueue(60);
    disp();
    dequeuerear();
    disp();
    dequeuefront();
    disp();
}