#include<stdio.h>
#include<conio.h>
#define max 10
int queue[max];
int front=-1,rear=-1;
void push(void);
int main()
{
    push();
    return 0;
}
void push(void)
{
    int item,F=0;
    printf("Enter item: ");
    scanf("%d",&item);
    if(rear==max-1)
    {
        printf("Overflow");
        F=1;
    }
    if(F!=0)
    {
        if(front==-1&&rear==-1)
        {
            front=rear=0;
        }
        else{
            rear=rear+1;
            queue[rear]=item;
        }
    }

}
