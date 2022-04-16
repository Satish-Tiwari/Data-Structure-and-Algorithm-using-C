#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
   int Coefficient;
   int Exponent;
   struct node *next;
}*Head_1=NULL,*Head_2=NULL,*ptr,*temp;

void Final_Polynomial(void);

main()
{
    int term_1,term_2;
    struct node *First_node,*Second_node,*Resultant_node;
    printf("\n <--Program for addition of two Polynomial and the Polynomials are created using only one Variable -->\n");

    printf("\n Enter how many terms are present in first Polynomial: ");
    scanf("%d",&term_1);
    printf("\n\t <-- Enter first Polynomial -->");
    for(int i=1;i<=term_1;i++)
    {
       First_node=(struct node *)malloc(sizeof(struct node));
       printf("\n Enter Coefficient and Exponent of %d term: ",i);
       scanf("%d %d",&First_node->Coefficient,&First_node->Exponent);
       if(Head_1==NULL)
       {
           Head_1=First_node;
           First_node->next=NULL;
       }
       else
       {
           ptr=Head_1;
           while(ptr->next!=NULL)
           {
           ptr=ptr->next;
           }
           ptr->next=First_node;
           First_node->next=NULL;
       }        
    }
    printf("\n\t First Polynomial is: ");
    ptr=Head_1;
    while(ptr!=NULL)
    {
        printf("+ %dx^%d ",ptr->Coefficient,ptr->Exponent);
        ptr=ptr->next;
    }

    printf("\n\n Enter how many terms are present in Second Polynomial: ");
    scanf("%d",&term_2);
    printf("\n\t <-- Enter Second Polynomial -->");
    for(int i=1;i<=term_2;i++)
    {
       Second_node=(struct node *)malloc(sizeof(struct node));
       printf("\n Enter Coefficient and Exponent of %d term: ",i);
       scanf("%d %d",&Second_node->Coefficient,&Second_node->Exponent);
       if(Head_2==NULL)
       {
           Head_2=Second_node;
           Second_node->next=NULL;
       }
       else
       {
           ptr=Head_2;
           while(ptr->next!=NULL)
           {
           ptr=ptr->next;
           }
           ptr->next=Second_node;
           Second_node->next=NULL;
       }        
    }
    printf("\n\t Second Polynomial is: ");
    ptr=Head_2;
    while(ptr!=NULL)
    {
        printf("+ %dx^%d ",ptr->Coefficient,ptr->Exponent);
        ptr=ptr->next;
    }

    Final_Polynomial();
    return 0;
}

/*Function for adding two Polynomials*/
void Final_Polynomial()
{
    struct node *Resultant_node;
    ptr=Head_1;
    temp=Head_2;
    int flag;
    while(temp!=NULL)
    {
        flag=0;
        ptr=Head_1;
        while(ptr!=NULL)
        {
            if(temp->Exponent==ptr->Exponent)
            {
                ptr->Coefficient+=temp->Coefficient;
                flag++;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==0)
        {
            Resultant_node=(struct node *)malloc(sizeof(struct node));
            Resultant_node->Coefficient=temp->Coefficient;
            Resultant_node->Exponent=temp->Exponent;
            Resultant_node->next=Head_1;
            Head_1=Resultant_node;
        }
        temp=temp->next;
    }
    
    /*Now,Result of two Polynomial is ready. We can also sort this Resultant Polynomial
      according to the increasing order of Exponent using Bubble Sort Algorithm.*/
    ptr=Head_1;
    temp=Head_1;
    while(ptr!=NULL)
    {
        while(temp->next!=NULL)
        {
            if((temp->Exponent)>((temp->next)->Exponent))
            {
                /*Swap Exponent*/
                int t1=temp->Exponent;
                temp->Exponent=(temp->next)->Exponent;
                (temp->next)->Exponent=t1;
                /*After that, Swap Coefficient*/
                int t2=temp->Coefficient;
                temp->Coefficient=(temp->next)->Coefficient;
                (temp->next)->Coefficient=t2;
            }
            temp=temp->next;
        }
        ptr=ptr->next;
    }    
    //Display the Resultant Polynomial.
    printf("\n\n Resulatant Polynomial is: ");
    ptr=Head_1;
    while(ptr!=NULL)
    {
        printf("+ %dx^%d ",ptr->Coefficient,ptr->Exponent);
        ptr=ptr->next;
    }    
}