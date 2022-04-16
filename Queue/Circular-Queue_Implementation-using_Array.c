#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
int Queue[MAX];
int Front=-1, Rear=-1;
void Insertion(void);
void Deletion(void);
void Search(void);
void Display(void);
int main()
{
    int opt;
    printf("\t Implementation of Circular Queue using Array...");
    do
    {
       printf("\n 1.Insertion Operation");
       printf("\n 2.Deletion Operation");
       printf("\n 3.Search Operation");
       printf("\n 4.Display Operation");
       printf("\n 5.Exit from the Program");
       printf("\n\t Enter Option: ");
       scanf("%d",&opt);
       switch (opt)
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
    } while (1);
    return 0;
}
/*Circular Queue Insertion Operation.*/
void Insertion()
{
    int n;
   if((Front==0 && Rear==MAX-1)||(Front==Rear+1))
    {
      printf("\nOverflow\n");
      return;
    }  
   else if(Front==-1 && Rear==-1)
   {
       Front=0;
       //Rear=0;
       /*When Element insert first time then Rear will also 
         come to zeroth place.*/
   }
   else if(Rear==MAX-1&&Front!=0)
    {
        Rear=0;
    }    
       printf("\n How many number you  want to store in Queue: ");
       scanf("%d",&n);
       printf("Enter %d number: ",n);
       for(int i=0;i<n;i++)
       {
           Rear=Rear+1;
           scanf("%d",&Queue[Rear]);
       }
     
}
/*Circular Queue Deletion Operation.*/
void Deletion()
{
   int value;
   if(Front==-1&&Rear==-1)
   {
       printf("\n Underflow");
       return;
   }
   else
   {
        value=Queue[Front];
        printf("\n Deleted element:%d\n",value);
   }
   //Find new value of Front
   if(Front==Rear)
   {
       Front=Rear=-1;
   }
   else if(Front==MAX-1)
   {
       Front=0;
   }
   else
   {
       Front=Front+1;
   }
}
/*Circular Queue Search Operation.*/
void Search()
{
   int sch,i;
   int temp=0;//This is useful to define element not found condition. 
   if(Front==-1 || Front>Rear)
   {
       printf("\n Underflow");
       return;
   }
   else
   {
       printf("\n Enter the number that you want to Search: ");
       scanf("%d",&sch);
       for(i=Front;i<=Rear;i++)
       {
           if(sch==Queue[i])
           {
               printf("\n %d is found at %d position.",sch,i);
               temp++;
           }
       }
       if(temp==0)
        {
            printf("\n %d is not found.",sch);
        }
   }
   printf("\n");
}
/*Circular Queue Display Operation*/
void Display()
{
   int i; 
   if(Front==-1 || Front>Rear)
   {
       printf("\n Underflow");
       return;
   }
   else
   {
       printf("\n Display Operation of Circular Queue:");
       for(i=Front;i<=Rear;i++)
       {
           printf(" %d ",Queue[i]);
       }
   }
   printf("\n");
}