#include<stdio.h>
#include<stdlib.h>

struct node
{
 struct node *left;
 int data;
 struct node *right;
};
struct node *head,*ptr;

void create(void)
{
    struct node *newnode;
    int n;
    printf("\n\t How many node you are going to created: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\n Enter %d node:",i);
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=newnode;
            newnode->right=newnode;
            newnode->left=newnode;
        }
        else
        {
            (head->left)->right=newnode;
            newnode->left=head->left;
            newnode->right=head;
            head->left=newnode;
        }
    }
}

void Insert_begg(void)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n\t Enter node: ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->left=newnode;
        newnode->right=newnode;
    }
    else
    {
        (head->left)->right=newnode;
        head->left=newnode;
        newnode->right=head;
        newnode->left=head->left;
        head=newnode;
    }
}

void Insert_specific(void);
void Insert_last(void);

void display(void)
{
    printf("\n\t Display Operation of the Program : ");
    ptr=head;
    printf(" %d",ptr->data);
    ptr=ptr->right;
    while(ptr!=head)
    {
        printf(" %d",ptr->data);
        ptr=ptr->right;
    }   
}

int main(int argc, char const *argv[])
{
    int opt;
    printf("Program that perform all operations of doubly circular Linked list.");
    while (1)
    {
    printf("\n 1. Creation");
    printf("\n 2. Insertation in Beginning");
    printf("\n 3. Insertation on specific position");
    printf("\n 4. Insertation at Last");
    printf("\n 5. Display operation");
    printf("\n\t Enter option : ");
    scanf("%d",&opt);
    switch (opt)
    {
    case 1 : create();
             break;
    case 2 : Insert_begg();
             break;
 /*   case 3 : Insert_specific();
             break;
    case 4 : Insert_last();
             break;*/
    case 5 : display();
             break;                        
    default: exit(0);
    }
    }
    return 0;
}
