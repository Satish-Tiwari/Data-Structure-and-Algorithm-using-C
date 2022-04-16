#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*ptr;
void create(int);
void Insert_beg(void);
void Insert_Last(void);
void Insert_pos(int);
void display(void);
void deletion_Beginning(void);
void deletion_Last(void);
void deletion_Specific(void);
int main()
{
    int choice,n,pos;
    printf("\n\t Single Linked-List Program:--");
    printf("\n\t Enter 1 for Creation.");
    printf("\n\t Enter 2 for Insertion at Beginning.");
    printf("\n\t Enter 3 for Insertion at Last.");
    printf("\n\t Enter 4 for Insertion at Specific Position.");
    printf("\n\t Enter 5 for Display Operation.");
    printf("\n\t Enter 6 for Deletion at Beginning.");
    printf("\n\t Enter 7 for Deletion at Last.");
    printf("\n\t Enter 8 for Deletion at Specific Position.");
    printf("\n\t Enter 9 for 'Exit'.");
    while(1)
    {
    printf("\n\n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\t\t Creation of node in Single Linked-list---");
                printf("\n Enter no of Node: ");
                scanf("%d",&n);
                create(n);
                break;
        case 2: Insert_beg();
                break;
        case 3: Insert_Last();
                break;
        case 4: printf("\t\t Insertion at Specific Position---");
                printf("\n Enter Position: ");
                scanf("%d",&pos);
                Insert_pos(pos);
                break;
        case 5: display();
                break;
        case 6: deletion_Beginning();
                break;
        case 7: deletion_Last();
                break;
        case 8: deletion_Specific();
                break;        
        case 9: exit(0);
        default:printf("\n Invalid Option.");

    }
    }
    getch();
}
void create(int n)
{
    struct node *newnode;
    for(int i=1;i<=n;i++) 
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      printf("\n Enter data in %d Node:\n",i);
      scanf("%d",&newnode->data);
      if(head==NULL)
      {
          head=newnode;
          newnode->next=NULL;
          //n=n-1;
      }
      else
      {
          ptr=head;
          while(ptr->next!=NULL)
          {
              ptr=ptr->next;
          }
          ptr->next=newnode;
          newnode->next=NULL;
          //n=n-1;
      }
    }
}
void Insert_beg()
{
    printf("\t\t Insertion at beginning---");
    struct node *newnode;
    newnode= (struct node*)malloc(sizeof(struct node));
    printf("\n Enter data: ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void Insert_Last()
{
    printf("\t\t Insertion at Last---");
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter data: ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
}
void Insert_pos(int pos)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter data");
    scanf("%d",&newnode->data);
    if(head==NULL && pos==1)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else if(head==NULL && pos>1)
    {
        printf("\n Wrong Position. ");
    }
    else if(head!=NULL && pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else if(head!=NULL && pos>1)
    {
        ptr=head;
        while(ptr!=NULL && pos>1)
        {
            temp=ptr;
            ptr=ptr->next;
            pos=pos-1;
        }
        if(pos==1)
        {
            temp->next=newnode;
            newnode->next=ptr;
        }
        if(pos>1)
        {
            printf("\n Position does not Exist.");
        }
    }
}
void display()
{
    printf("\t\t Display Operation of Single Linked-list--- \n\t\t\t");
    if(head==NULL)
        printf("\n Linked-List is Empty.");
    else{
        ptr=head;
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
      ptr->next=NULL;
      printf("\n Deleted data is %d",ptr->data);
      free(ptr);
  }
}

void deletion_Last()
{
    printf("\t\t Deletion at Last---");
   ptr=head;
   struct node *temp;
  if(head==NULL)
  {
      printf("\n Nothing to delete.");
  }
  else
  {
      while(ptr->next!=NULL)
      {
          temp=ptr;
          ptr=ptr->next;
      }
      temp->next=NULL;
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
          ptr->next=NULL;
       printf("\n Deleted data is %d",ptr->data);
       free(ptr);
      }
  }
  else
  {
      struct node *temp;
      while(ptr->next!=NULL && pos>1)
      {
          temp=ptr;
          ptr=ptr->next;
          pos=pos-1;
      }
      if(ptr->next!=NULL)
      {
          temp->next=ptr->next;
          ptr->next=NULL;
           printf("\n Deleted data is %d",ptr->data);
       free(ptr);
      }
      else
      {
        temp->next=NULL;
        printf("\n Deleted data is %d",ptr->data);
        free(ptr);
      }
  }
}

