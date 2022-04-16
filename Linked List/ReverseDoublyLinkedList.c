#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *head,*ptr,*temp;

void creation()
{

  struct node *new_node; int n;
  scanf("%d",&n);
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

void reverse()
{
    ptr = head;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
    }   
    head->pre = NULL; 
    head = ptr->next;
}

void display()
{
   ptr=head;
     while(ptr!=NULL)
     {
         printf(" %d ",ptr->data);
         ptr=ptr->pre;
     }
   
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        creation();
        n=n-1;
    }
     display();
    return 0;
}
