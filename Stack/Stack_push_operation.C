#include<stdio.h>
#include<conio.h>
#define max 5
int Top=-1;
int stack[max];
void push(int stack[],int size);
int main()
{
    //for(int i=-1;i<max;i++)
    push(stack,max);
    getch();
}
void push(int stack[],int size)
{
    if(Top==max-1)
        printf("Stack is overflow");
    else
    {
        Top=Top+1;
        printf("Enter value to store in Stack__ ");
        scanf("%d",&stack[Top]);
    }
}
