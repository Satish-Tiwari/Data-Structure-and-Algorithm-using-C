#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
// Structure for Doubly Linked-list
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *head=NULL,*ptr;

/*Creation Operation. */
void creation()
{
  printf("\t\t Creation of node in Doubly Linked-list---");
  struct node *new_node; 
  int n,i;
    printf("\n How many node you are going to Create: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      new_node=(struct node*)malloc(sizeof(struct node));
      printf("\n Enter data in %d node: ",i);
      scanf("%d",&new_node->data);
      if(head==NULL)
      {
          head=new_node;
          new_node->pre=NULL;
          new_node->next=NULL;
      }
      else
      {
          ptr=head;
          while(ptr->next!=NULL)
          {
              ptr=ptr->next;
          }
          ptr->next=new_node;
          new_node->pre=ptr;
          new_node->next=NULL;
      }
    }  
}
// insertion at beginning
void Insert_Beginning()
{
    printf("\t\t Insertion at beginning---");
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter Data: ");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        head=new_node;
        new_node->pre=NULL;
        new_node->next=NULL;
    }
    else
    {
        new_node->next=head;
        head->pre=new_node;
        new_node->pre=NULL;
        head=new_node;
    }
}
void Insert_Last()
{
   printf("\t\t Insertion at Last---");
   struct node *new_node;
   new_node=(struct node*)malloc(sizeof(struct node));
   printf("\n Enter Data: ");
   scanf("%d",&new_node->data);

   if(head==NULL)
    {
        head=new_node;
        new_node->pre=NULL;
        new_node->next=NULL;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->pre=ptr;
        new_node->next=NULL;
    }

}
// Insertion at Specific Position
void Insert_Specific()
{
   printf("\t\t Insertion at Specific Position---");
   int pos;
   struct node *new_node;
   new_node=(struct node*)malloc(sizeof(struct node));
   printf("\n Enter Position: ");
   scanf("%d",&pos);
   printf("\n Enter Data: ");
   scanf("%d",&new_node->data);

   if(head==NULL && pos==1)
     {
       head=new_node;
       new_node->pre=NULL;
       new_node->next=NULL;
     }
  else if(head!=NULL && pos==1)
      {
       new_node->next=head;
       head->pre=new_node;
       new_node->pre=NULL;
       head=new_node;
      }
  else if(head!=NULL && pos>1)
   {
    ptr=head;
    while(ptr->next!=NULL && pos>1)
    {
      ptr=ptr->next;
      pos=pos-1;
    }
    if(pos==1)
    {
       new_node->pre=ptr->pre;
       (ptr->pre)->next=new_node;
       new_node->next=ptr;
       ptr->pre=new_node;
    }
    else if(pos==2)
    {
       new_node->pre=ptr;
       ptr->next=new_node;
       new_node->next=NULL;
       
    }
    else 
    {
     printf("\n wrong position");
    }
  }
}
//Display Operation in Doubly Linked-list
void display()
{
   printf("\t\t Display Operation of Single Linked-list--- \n\t\t\t");
   ptr=head;
   if(head==NULL)
   {
       printf("Doubly Linked-list is not created. ");
   }
   else
   {
     while(ptr!=NULL)
     {

         printf(" %d ",ptr->data);
         ptr=ptr->next;
     }
   }
}

void deletion_Beginning()
{
  printf("\t\t Deletion from Beginning---");
  ptr=head;
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else if(ptr->next==NULL)
  {
    head=NULL;
    printf("\n Deleted data is %d",ptr->data);
    free(ptr);
  }
  else
  {
      head=ptr->next;
      (ptr->next)->pre=NULL;
      ptr->next=NULL;
      printf("\n Deleted data is %d",ptr->data);
      free(ptr);
  }
}

void deletion_Last()
{
  printf("\t\t Deletion at Last---");
  ptr=head;
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else
  {
      while(ptr->next!=NULL)
      {
          ptr=ptr->next;
      }
      (ptr->pre)->next=NULL;
      ptr->pre=NULL;
     printf("\n Deleted data is %d",ptr->data);
     free(ptr);
  }
}

void deletion_Specific()
{
  printf("\t\t Deletion at Specific Position----");
  int pos;
  ptr=head;
  printf("\n Enter position.");
  scanf("%d",&pos);
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else if(head!=NULL && pos==1)
  {
     if(ptr->next==NULL)
      {
        head=NULL;
       printf("\n Deleted data is %d",ptr->data);
       free(ptr);
      }
      else
      {
          head=ptr->next;
          (ptr->next)->pre=NULL;
          ptr->next=NULL;
       printf("\n Deleted data is %d",ptr->data);
       free(ptr);
      }
  }
  else
  {
      while(ptr->next!=NULL && pos>1)
      {
          ptr=ptr->next;
          pos=pos-1;
      }
      if(ptr->next!=NULL)
      {
          (ptr->pre)->next=ptr->next;
          (ptr->next)->pre=ptr->pre;
          ptr->pre=NULL;
          ptr->next=NULL;
           printf("\n Deleted data is %d",ptr->data);
       free(ptr);
      }
      else
      {
          (ptr->pre)->next=NULL;
           ptr->pre=NULL;
           printf("\n Deleted data is %d",ptr->data);
       free(ptr);
      }
  }
}
void main()
{
    int choise;
    printf("\t Doubly Linked-List Program");
    printf("\n\t Enter 1 for Creation: ");
    printf("\n\t Enter 2 for Insertion at Beginning: ");
    printf("\n\t Enter 3 for Insertion at Last: ");
    printf("\n\t Enter 4 for Insertion at Specific Position: ");
    printf("\n\t Enter 5 for Display: ");

    printf("\n\t Enter 6 for Deletion at Beginning: ");
    printf("\n\t Enter 7 for Deletion at Last: ");
    printf("\n\t Enter 8 for Deletion at Specific Position: ");
    while(1)
    {
    printf("\n\n Enter your choice: ");
    scanf("%d",&choise);
    switch(choise)
    {
        case 1: creation();
                break;
        case 2: Insert_Beginning();
                 break;
        case 3: Insert_Last();
                break;
        case 4: Insert_Specific();
                break;
        case 5: display();
                break;
        case 6: deletion_Beginning();
                break;
        case 7: deletion_Last();
                break;
        case 8: deletion_Specific();
                break;
        default: exit(0);
    }
    } 
    return 0;
}

