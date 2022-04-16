#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *rear,*front,*ptr;
void insertion();
void deletion();
void search();
void display();
int main()
{
int ch;
while(1) 
{
printf("\n Enter 1 for Insertion in Queue.");
printf("\n Enter 2 for Deletion from Queue.");
printf("\n Enter 3 for Search in Queue.");
printf("\n Enter 4 for Display from Queue.");
printf("\n Enter 5 for Exit from the program.");
printf("\n Enter option: ");
scanf("%d",&ch);
    switch(ch)
    {
        case 1: insertion();
                break;
        case 2: deletion();
                break;
        case 3: search();
                break;        
        case 4: display();
                break;
        case 5: exit(0);        
        default:printf("Invalid Option.");
    }
}
   return 0;
}
/*Queue Insertion Operation*/
void insertion()
{
    struct node *newnode;
    int n,i;
    printf("\n How many number you are going to enter: ");
    scanf("%d",&n);
    printf("Enter %d number: ",n);
    for(i=1;i<=n;i++)
    {
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
     newnode->next=NULL;
    if((rear==NULL)&&(front==NULL))
    {
        rear=front=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=rear->next;
    }
    }
    printf("\n");
}
/*Deletion Operation*/
void deletion()
{
   if((front==NULL)||(front>rear))
   {
       printf("\n Nothing to delete.");
   }
   else{
    ptr=front;
    front=front->next;
    printf("\n Deletion data(node) is: %d",ptr->data);
    free(ptr);
   }
   printf("\n");
}
/*Search Operation*/
void search()
{
    int sch,temp=0,pos=1;
    if((front==NULL)||(front>rear))
        printf("\n Nothing to Search.");
    else
    {
      ptr=front;
      printf("\n Enter number that you want to search: ");
      scanf("%d",&sch);
     while(ptr!=NULL)
      {
        if(sch==ptr->data)
        {
        printf("\n %d is found at %d Position.",sch,pos);
        temp++;
        }
        pos++;
        ptr=ptr->next;
      }
      if(temp==0)
      {
          printf("\nElement not found.");
      }
    } 
    printf("\n");
}
/*Display Operation*/
void display()
{
    if((front==NULL)||(front>rear))
        printf("\n Nothing to print.");
    else
       ptr=front;

  while(ptr!=NULL)
  {
      printf("\n %d",ptr->data);
      ptr=ptr->next;
  }
  printf("\n");
}