#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *Front=NULL,*Rear=NULL,*ptr,*temp;
void Insertion(void);
void Deletion(void);
void Search(void);
void Display(void);
int main()
{
    int opt;
    printf("\n\t <<-- Circular Queue -->");
    do{
    printf("\n Enter 1 for Insertion.");
    printf("\n Enter 2 for Deletion.");
    printf("\n Enter 3 for search.");
    printf("\n Enter 4 for Display.");
    printf("\n Enter 5 for Exit from the Program.");
    printf("\n \n Enter Option: ");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: Insertion();
                break;
        case 2: Deletion();
                break;        
        case 3: Search();
                break;
        case 4: Display();
                break;
        case 5: exit(0);        
        default: exit(0);
    }
    }
    while(1);
    return(0);
}
/* For Insertion Operation. */
void Insertion()
{
  struct node *new_node; int n;
  printf("\n How many node you are going to Enter: ");
  scanf("%d",&n);
  printf("Enter %d nodes: ",n);
  while(n>0)
  {
  new_node=(struct node*)malloc(sizeof(struct node));
      scanf("%d",&new_node->data);
      if((Front==NULL) && (Rear==NULL))
      {
          Front=new_node;
          Rear=new_node;
          new_node->pre=new_node;
          new_node->next=new_node;
      }
      else
      {
          Rear->next=new_node;
          new_node->pre=Rear;
          new_node->next=Front;
          Front->pre=new_node;
          Rear=Rear->next;
      }
    n--;
  }
}
/*Deletion Operation*/
void Deletion()
{
  if((Front==NULL)||(Front>Rear))
  {
      printf("\n Nothing to delete.");
  }
  else
  {
      ptr=Front;
      Front=Front->next;
      Front->pre=Rear;
      Rear->next=Front;
      ptr->pre=NULL;
      ptr->next=NULL;
      printf("\n Deleted data is %d",ptr->data);
      free(ptr);
  }
  printf("\n");
}
/*Search operation*/
void Search()
{
    int key,pos=1,temp=0;
    if((Front==NULL)||(Front>Rear))
    {
        printf("\n Nothing to be Search.");
    }
    else
    {
        ptr=Front;
        printf("Enter no. that you want to search: ");
        scanf("%d",&key);
        if(ptr->data==key)
        {
            printf("\n %d is found at %d Position.",key,pos);
            temp++;//For,Present element not found condition.
        }
        ptr=ptr->next;
        pos++;
       while(ptr!=Front)
       {
           if(ptr->data==key)
           {
               printf("\n %d is found at %d Position.",key,pos);
               temp++;//For,Present element not found condition.
           }
           pos++;
           ptr=ptr->next;
       }
       if(temp==0)
        printf("\n Element not Found.");
    }
    printf("\n");
}
//Display Operation in Doubly Linked-list
void Display()
{
   ptr=Front;
   if((Front==NULL && Rear==NULL)||(Front>Rear))
     {
        printf("\n Nothing to be Search.");
     }
   else
    {
        printf("\n Display Operation of Circular Queue:");
     while(ptr->next!=Front)
     {
         printf(" %d ",ptr->data);
         ptr=ptr->next;
     }
     printf("\n%d",ptr->data);
    }
    printf("\n");
}