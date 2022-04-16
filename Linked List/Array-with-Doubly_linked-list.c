#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
   struct node
    {
       struct node *pre;
       int array[100];
       struct node *next;
    };
struct node *head=NULL,*ptr;
void  Create(void);
void  Display(void); 
void main()
{
    /* code */
    int opt; 
    while(1)
    {   printf("\n\n\t1.Create");
        printf("\n\t2.Display");
        printf("\n\t3.Exit\n");
        printf("\n\tEnter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: Create();
                    break;
            case 2: Display();
                    break;
            case 3: exit(0);        
            default:printf("\n Invalid Option.");                
        }
    }
    return 0;
}
void Create()
{
    struct node *newnode;
    int n;
    printf("How many node array type you are going to created:");
    scanf("%d",&n);
    for(int l=1;l<=n;l++)
    {
        int n1;
    newnode=(struct node*) malloc (sizeof(struct node));
    printf("\n How many number you are going to Enter in %d node: ",l);
    scanf("%d",&n1);
    printf("Enter %d number: ",n1);
    int i;
    for(i=0;i<n1;i++)
    {
    scanf("%d",&newnode->array[i]);
    }
    newnode->array[i]=NULL;
    //Because of the value of i has already increased.

    /*When we perform display operation that time we don't know how many
    numbers are stored in particular array, because of it is not fix to store
    same no. data in each array.Hence,To stop the loop during display operation of
    linked-list.Becsuse of,here we have already stored that the last element of array is 
    NULL.*/
    if(head==NULL)
    {
        head=newnode;
        newnode->pre=NULL;
        newnode->next=NULL;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        newnode->pre=ptr;
        ptr->next=newnode;
        newnode->next=NULL;
    }
    }
}
void Display()
{
    if(head==NULL)
    {
        printf("\n Linked-List is not Created:---");
    }
    else
    {
        int num=1;
        ptr=head;
        while(ptr!=NULL)
        {
            printf("\nData stored in %d node: ",num);
            int length=0;
            for(;ptr->array[length]!=NULL;)
            {
               printf(" %d ",ptr->array[length]);
               length++;
            }
            ptr=ptr->next;
            num++;
        }
    }
    
}
