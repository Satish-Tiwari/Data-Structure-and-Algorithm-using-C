#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *head,*ptr,*temp;
void creation(void);
void Insert_Beginning(void);
void Insert_Last(void);
void Insert_Specific(void);
void display(void);
void search(void);
void deletion_Beginning(void);
void deletion_Last(void);
void deletion_Specific(void);
int main()
{
    int opt;
    printf("\n\t <<-- Doubly Circular Linked List -->");
    printf("\n Enter 1 for Creation.");
    printf("\n Enter 2 for Insertion at Beginning.");
    printf("\n Enter 3 for Insertion at Last.");
    printf("\n Enter 4 for Insertion at Specific Position.");
    printf("\n Enter 5 for Display.");
    printf("\n Enter 6 for search.");
    printf("\n Enter 7 for Deletion at Beginning.");
    printf("\n Enter 8 for Deletion at Last.");
    printf("\n Enter 9 for Deletion at Specific Position.");
    do
    {
    printf("\n \n Enter Option: ");
    scanf("%d",&opt);
    switch(opt)
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
        case 6: search();
                break;
        case 7: deletion_Beginning();
                break;
        case 8: deletion_Last();
                break;
        case 9: deletion_Specific();
                break;
        default: exit(0);
    }
    }
    while(1);
    return(0);
}
/* For Creation Operation. */
void creation()
{
  printf("\t Creation Operation--");
  struct node *new_node; int n;
  printf("\n How many node you are going to Enter: ");
  scanf("%d",&n);
  printf("Enter %d nodes: ",n);
  for(int i=1;i<=n;i++)
  {
  new_node=(struct node*)malloc(sizeof(struct node));
      scanf("%d",&new_node->data);
      if(head==NULL)
      {
          head=new_node;
          new_node->pre=new_node;
          new_node->next=new_node;
      }
      else
      {
        new_node->next=head;
        new_node->pre=head->pre;
        (head->pre)->next=new_node;
        head->pre=new_node;
      }
  }
}
/*Insertion at Beginning in Doubly Circular Linked List*/
void Insert_Beginning()
{
    printf("\t Insertion at Beginning--");
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter Data: ");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        head=new_node;
        new_node->pre=new_node;
        new_node->next=new_node;
    }
    else
    {
        new_node->next=head;
        new_node->pre=head->pre;
        (head->pre)->next=new_node;
        head->pre=new_node;
        head=new_node;
    }
}
/*Insertion at last in Doubly Circular Linked List*/
void Insert_Last()
{
   printf(" \t Insetion at Last--");
   struct node *new_node;
   new_node=(struct node*)malloc(sizeof(struct node));
   printf("\n Enter Data: ");
   scanf("%d",&new_node->data);

   if(head==NULL)
    {
        head=new_node;
        new_node->pre=new_node;
        new_node->next=new_node;
    }
    else
    {
      new_node->next=head;
      new_node->pre=head->pre;
      (head->pre)->next=new_node;
      head->pre=new_node;
    }

}
// Insertion at Specific Position
void Insert_Specific()
{
   printf("\t Insertion at Specified Position--");
   int pos;
   struct node *new_node;
   new_node=(struct node*)malloc(sizeof(struct node));
   printf("\n Enter Data: ");
   scanf("%d",&new_node->data);
   printf("Enter Position: ");
   scanf("%d",&pos);

   if(head==NULL && pos==1)

    {
        head=new_node;
        new_node->pre=new_node;
        new_node->next=new_node;
    }
    else if(head==NULL && pos>1)
        printf("\n Wrong Position. ");
    else if(head!=NULL && pos==1)
    {
        new_node->next=head;
        new_node->pre=head->pre;
        (head->pre)->next=new_node;
        head->pre=new_node;
        head=new_node;
    }
    else if(head!=NULL && pos>1)
    {
        ptr=head;
        while(ptr->next!=head && pos>1)
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
            new_node->next=ptr->next;
            (ptr->next)->pre=new_node;
            ptr->next=new_node;
        }
        else
        printf("\n Wrong Position.");
    }
}
//Display Operation in Doubly Linked-list
void display()
{
   printf("\t Display Operation of Doubly Circular Linked List--\n\t");
   ptr=head;
   if(head==NULL)
   {
       printf("Doubly Linked-list is not created. ");
   }
   else
   {
     while(ptr->next!=head)
     {

         printf(" %d ",ptr->data);
         ptr=ptr->next;
     }
     printf(" %d ",ptr->data);
   }
}
/*Search operation*/
void search()
{
    printf("\t Search Operation--");
    int key,pos=1;
    printf("\nEnter no. that you want to search: ");
    scanf("%d",&key);
    ptr=head;
    if(ptr->data==key)
    {
        printf("Element found at Position %d\n",pos);
    }
    ptr=ptr->next;
    pos=pos+1;
    while(ptr!=head)
    {
        if(ptr->data==key)
        {
        printf("Element found at Position %d\n",pos);
        }
        ptr=ptr->next;
        pos++;
    }
}
/*Function for Deletion at Beginning in Doubly Circular Linked-List*/
void deletion_Beginning()
{
  printf("\t Deletion from Beginning");
    ptr=head;
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else if(ptr->next==head)
  {
    head=NULL;
    printf("\n Deleted data is %d",ptr->data);
    free(ptr);
  }
  else
  {
      head=ptr->next;
      head->pre=ptr->pre;
      (ptr->pre)->next=head;
      ptr->pre=NULL;
      ptr->next=NULL;
      printf("\n Deleted data is %d",ptr->data);
      free(ptr);
  }
}
/*Function for Deletion at Last in Doubly Circular Linked-List*/
void deletion_Last()
{
  printf("\t Deletion at Last--");  
   ptr=head;
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else
  {
      while(ptr->next!=head)
      {
          ptr=ptr->next;
      }
      (ptr->pre)->next=head;
      head->pre=ptr->pre;
      ptr->pre=NULL;
      ptr->next=NULL;
     printf("\n Deleted data is %d",ptr->data);
     free(ptr);
  }
}
/*Function for Deletion at Specified Positioin in Doubly Circular Linked-List*/
void deletion_Specific()
{
  printf("\t Deletion at Specified Position--");  
    int pos;
  ptr=head;
  printf("\nEnter position.");
  scanf("%d",&pos);
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else if(ptr->next==head && pos==1)
  {
      head=NULL;
      ptr->pre=NULL;
      ptr->next=NULL;
      printf("Deleted data is %d",ptr->data);
      free(ptr);
  }
  else if(ptr->next!=head && pos==1)
  {
      head=ptr->next;
      head->pre=ptr->pre;
      (head->pre)->next=head;
      ptr->pre=NULL;
      ptr->next=NULL;
      printf("Deleted data is %d",ptr->data);
      free(ptr);
  }
  else
  {
      while(ptr->next!=head && pos>1)
      {
          ptr=ptr->next;
          pos=pos-1;
      }
      if(pos==1)
      {
          (ptr->pre)->next=ptr->next;
          (ptr->next)->pre=ptr->pre;
           ptr->pre=NULL;
           ptr->next=NULL;
           printf("Deleted data is %d",ptr->data);
           free(ptr);
      }
  }
  }