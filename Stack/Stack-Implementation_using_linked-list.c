/* How we can implement an stack using linked list. */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top,*ptr;
void PUSH();
void POP();
void PEEP();
void display();
int main(void)
{
    int choice;
    printf("\n Implementation of stack using Linked-list: ");
    do
    {
        printf("\n Enter 1 for Push");
        printf("\n Enter 2 for Pop");
        printf("\n Enter 3 for PEEP");
        printf("\n Enter 4 for Display");
        printf("\n Enter 5 for Exit from the Program");
        printf("\n Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: PUSH();
                    break;
            case 2: POP();
                    break;
            case 3: PEEP();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);        
            default: printf("\n Wrong choice");
        }
    }while(choice<5);
    return 0;
}
/*Stack Push Operation*/
void PUSH()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter data: ");
    scanf("%d",&newnode->data);
    if(top==NULL)
    {
        top=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}
/*Stack Pop Operation*/
void POP()
{
    if(top==NULL)
        printf("\n Empty");
    else
    {
        ptr=top;
        printf("\n Deleted node data is %d",ptr->data);
        top=ptr->next;
        ptr->next=NULL;
        free(ptr);
    }
}
/*Stack Peep Operation*/
void PEEP()
{
    printf("\n Top most value is %d",top->data);
}
/*Stack Display Operation*/
void display()
{
    if(top==NULL)
    {
        printf("\n Nothing to print.");
    }
    else
    {
        ptr=top;
        while(ptr!=NULL)
        {
            printf("\n %d",ptr->data);
            ptr=ptr->next;
        }
    }
}